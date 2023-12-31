#include "Framework.h"
#include "Terrain.h"

Terrain::Terrain(Shader* shader, wstring heightFile)
	: shader(shader)
{
	heightmap = new Texture(heightFile);

	CreateVertexData();
	CreateIndexData();
	CreateNormalData();
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
	static Vector3 direction = Vector3(-1, -1, 1);
	ImGui::SliderFloat3("Direction", direction, -1, 1);

	Matrix world;
	D3DXMatrixIdentity(&world);
	shader->AsMatrix("World")->SetMatrix(world);
	shader->AsMatrix("View")->SetMatrix(Context::Get()->View());
	shader->AsMatrix("Projection")->SetMatrix(Context::Get()->Projection());
	shader->AsVector("Direction")->SetFloatVector(direction);
}

void Terrain::Render()
{
	// Normal vector 그리기
	//for (int i = 0; i < vertexCount; ++i)
	//{
	//	Vector3 start	= vertices[i].Position;
	//	Vector3 end		= vertices[i].Position + vertices[i].Normal * 2;
	//	DebugLine::Get()->RenderLine(start, end, Color(0, 1, 0, 1));
	//}

	UINT stride = sizeof(TerrainVertex);
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
	// Index 수	= 사각형 수 * 6
	//			= (X축 정점 갯수 - 1) * (Y축 정점 갯수 - 1) * 6
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

void Terrain::CreateNormalData()
{
	for (UINT i = 0; i < indexCount / 3; ++i)
	{
		UINT index0 = indices[3 * i + 0];
		UINT index1 = indices[3 * i + 1];
		UINT index2 = indices[3 * i + 2];

		Vector3 a = vertices[index1].Position - vertices[index0].Position;
		Vector3 b = vertices[index2].Position - vertices[index0].Position;
		Vector3 normal;
		D3DXVec3Cross(&normal, &a, &b);

		vertices[index0].Normal += normal;
		vertices[index1].Normal += normal;
		vertices[index2].Normal += normal;
	}
	
	for (UINT i = 0; i < indexCount / 3; ++i)
	{
		D3DXVec3Normalize(&vertices[indices[3 * i + 0]].Normal, &vertices[indices[3 * i + 0]].Normal);
		D3DXVec3Normalize(&vertices[indices[3 * i + 1]].Normal, &vertices[indices[3 * i + 1]].Normal);
		D3DXVec3Normalize(&vertices[indices[3 * i + 2]].Normal, &vertices[indices[3 * i + 2]].Normal);
	}
}

void Terrain::CreateBuffer()
{
	// Create Vertex Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = sizeof(TerrainVertex) * vertexCount;
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