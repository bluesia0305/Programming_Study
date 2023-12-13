#include "stdafx.h"
#include "WorldDemo.h"

void WorldDemo::Initialize()
{
	shader = new Shader(L"09_World.fx");

	// Local 좌표
	vertices[0].Position = Vector3(0.0f, 0.0f, 0.0f);
	vertices[1].Position = Vector3(0.0f, 0.5f, 0.0f);
	vertices[2].Position = Vector3(0.5f, 0.0f, 0.0f);

	vertices[3].Position = Vector3(0.5f, 0.0f, 0.0f);
	vertices[4].Position = Vector3(0.0f, 0.5f, 0.0f);
	vertices[5].Position = Vector3(0.5f, 0.5f, 0.0f);

	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));	// 멤버변수 내 포인터 존재할 때 초기화
	desc.ByteWidth = sizeof(Vertex) * 6;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	D3D11_SUBRESOURCE_DATA subResource = { 0 };		// 일반적인 구조체 초기화
	subResource.pSysMem = vertices;

	Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer));


	D3DXMatrixIdentity(&world);
}

void WorldDemo::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
}

void WorldDemo::Update()
{
	//if (Keyboard::Get()->Press(VK_RIGHT))
	//	world._41 += 2.0f * Time::Delta();
	//else if (Keyboard::Get()->Press(VK_LEFT))
	//	world._41 -= 2.0f * Time::Delta();

	if (Keyboard::Get()->Press(VK_RIGHT))
	{
		world._11 += 2.0f * Time::Delta();
		world._22 += 2.0f * Time::Delta();
	}
	else if (Keyboard::Get()->Press(VK_LEFT))
	{
		world._11 -= 2.0f * Time::Delta();
		world._22 -= 2.0f * Time::Delta();
	}
}

void WorldDemo::Render()
{
	// Vertex shader로 전달할 W, V, P 행렬 설정
	shader->AsMatrix("World")->SetMatrix(world);
	shader->AsMatrix("View")->SetMatrix(Context::Get()->View());
	shader->AsMatrix("Projection")->SetMatrix(Context::Get()->Projection());

	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	
	shader->Draw(0, 0, 6);
}