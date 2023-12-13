#include "Framework.h"
#include "Terrain.h"

Terrain::Terrain(Shader* shader, wstring heightFile)
	: shader(shader)
{
	heightmap = new Texture(heightFile);

	CreateVertexData();
	CreateIndexData();
	CreateBuffer();
}

Terrain::~Terrain()
{
	SafeDelete(heightmap);
	SafeDeleteArray(vertices);
	SafeDeleteArray(indices);

	SafeRelease(vertexBuffer);
	SafeRelease(indexBuffer);
}

void Terrain::Update()
{
	Matrix world;
	D3DXMatrixIdentity(&world);
	shader->AsMatrix("World")->SetMatrix(world);
	shader->AsMatrix("View")->SetMatrix(Context::Get()->View());
	shader->AsMatrix("Projection")->SetMatrix(Context::Get()->Projection());
}

void Terrain::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	D3D::GetDC()->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	shader->DrawIndexed(0, pass, indexCount);
}

void Terrain::CreateVertexData()
{
	vector<Color> heights;
	heightmap->ReadPixel(DXGI_FORMAT_R8G8B8A8_UNORM, &heights);

	width		= heightmap->GetWidth();
	height		= heightmap->GetHeight();
	vertexCount = width * height;
	vertices	= new TerrainVertex[vertexCount];

	for (UINT z = 0; z < height; ++z)
	{
		for (UINT x = 0; x < width; ++x)
		{
			UINT index = width * z + x;
			UINT pixel = width * (height - 1 - z) + x;	// UV 좌표계의 V 방향과 Z 방향이 반대

			vertices[index].Position.x = (float)x;
			vertices[index].Position.y = heights[pixel].r * 255.0f / 10.0f;
			vertices[index].Position.z = (float)z;
		}
	}
}

void Terrain::CreateIndexData()
{
	indexCount	= (width - 1) * (height - 1) * 6;
	indices		= new UINT[indexCount];

	UINT index = 0;
	for (UINT i = 0; i < height - 1; ++i)
	{
		for (UINT j = 0; j < width - 1; ++j)
		{
			indices[index + 0] = width * i			+ j;
			indices[index + 1] = width * (i + 1)	+ j;
			indices[index + 2] = width * i			+ (j + 1);
			indices[index + 3] = width * i			+ (j + 1);
			indices[index + 4] = width * (i + 1)	+ j;
			indices[index + 5] = width * (i + 1)	+ (j + 1);

			index += 6;
		}
	}
}

void Terrain::CreateBuffer()
{
	// Create Vertex Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = sizeof(Vertex) * vertexCount;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = vertices;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer));
	}

	// Create Index Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = sizeof(UINT) * indexCount;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = indices;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &indexBuffer));
	}
}