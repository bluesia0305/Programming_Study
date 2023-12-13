#include "stdafx.h"
#include "TriangleList.h"

void TriangleList::Initialize()
{
	shader = new Shader(L"06_Triangle.fx");

	// VertexBuffer
	{
		vertices[0].Position = Vector3(-0.5f,  0.0f,  0.0f);
		vertices[1].Position = Vector3( 0.0f,  0.5f,  0.0f);
		vertices[2].Position = Vector3( 0.5f,  0.0f,  0.0f);

		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));	// 멤버변수 내 포인터 존재할 때 초기화
		desc.ByteWidth = sizeof(Vertex) * 3;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };		// 일반적인 구조체 초기화
		subResource.pSysMem = vertices;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer));
	}

	// VertexBuffer2
	{
		vertices2[0].Position = Vector3(-0.5f, -0.5f,  0.0f);
		vertices2[1].Position = Vector3( 0.0f,  0.0f,  0.0f);
		vertices2[2].Position = Vector3( 0.5f, -0.5f,  0.0f);

		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = sizeof(Vertex) * 3;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = vertices2;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer2));
	}

	// VertexBuffer3
	{
		vertices3[0].Position = Vector3(-0.5f,  0.0f,  0.0f);
		vertices3[1].Position = Vector3( 0.0f,  0.5f,  0.0f);
		vertices3[2].Position = Vector3( 0.5f,  0.0f,  0.0f);
		vertices3[3].Position = Vector3(-0.5f, -0.5f,  0.0f);
		vertices3[4].Position = Vector3( 0.0f,  0.0f,  0.0f);
		vertices3[5].Position = Vector3( 0.5f, -0.5f,  0.0f);

		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = sizeof(Vertex) * 6;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = vertices3;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer3));
	}
}

void TriangleList::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
	SafeRelease(vertexBuffer2);
}

void TriangleList::Update()
{

}

void TriangleList::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	//D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	//D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//shader->Draw(0, 0, 3);

	//D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer2, &stride, &offset);
	//D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	//shader->Draw(0, 1, 3);

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer3, &stride, &offset);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	shader->Draw(0, 2, 6);
}