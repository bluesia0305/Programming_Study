#include "stdafx.h"
#include "GridDemo.h"

void GridDemo::Initialize()
{
	shader = new Shader(L"10_World.fx");

	// Generate Vertex Data
	vertexCount = (width + 1) * (height + 1);
	vertices	= new Vertex[vertexCount];

	for (UINT i = 0; i <= height; ++i)
	{
		for (UINT j = 0; j <= width; ++j)
		{
			UINT index = (width + 1) * i + j;
			vertices[index].Position.x = static_cast<float>(j);
			vertices[index].Position.y = static_cast<float>(i);
			vertices[index].Position.z = 0.0f;
		}
	}

	// Generate Index Data
	indexCount	= width * height * 6;
	indices		= new UINT[indexCount];

	UINT index = 0;
	for (UINT i = 0; i < height; ++i)
	{
		for (UINT j = 0; j < width; ++j)
		{
			indices[index + 0] = (width + 1) * i		+ j;
			indices[index + 1] = (width + 1) * (i + 1)	+ j;
			indices[index + 2] = (width + 1) * i		+ (j + 1);
			indices[index + 3] = (width + 1) * i		+ (j + 1);
			indices[index + 4] = (width + 1) * (i + 1)	+ j;
			indices[index + 5] = (width + 1) * (i + 1)	+ (j + 1);

			index += 6;
		}
	}

	// Create Vertex Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));	// 멤버변수 내 포인터 존재할 때 초기화
		desc.ByteWidth = sizeof(Vertex) * vertexCount;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };		// 일반적인 구조체 초기화
		subResource.pSysMem = vertices;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer));
	}

	// Create Index Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));	// 멤버변수 내 포인터 존재할 때 초기화
		desc.ByteWidth = sizeof(UINT) * indexCount;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };		// 일반적인 구조체 초기화
		subResource.pSysMem = indices;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &indexBuffer));
	}

	SafeDeleteArray(vertices);
	SafeDeleteArray(indices);

	D3DXMatrixIdentity(&world);
}

void GridDemo::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
	SafeRelease(indexBuffer);
}

void GridDemo::Update()
{

}

void GridDemo::Render()
{
	// Vertex shader로 전달할 W, V, P 행렬 설정
	shader->AsScalar("Index")->SetInt(0);
	shader->AsMatrix("World")->SetMatrix(world);
	shader->AsMatrix("View")->SetMatrix(Context::Get()->View());
	shader->AsMatrix("Projection")->SetMatrix(Context::Get()->Projection());

	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	D3D::GetDC()->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);

	shader->DrawIndexed(0, 1, indexCount);
}