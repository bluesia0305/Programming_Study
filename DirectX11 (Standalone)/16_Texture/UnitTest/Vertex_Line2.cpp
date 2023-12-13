#include "stdafx.h"
#include "Vertex_Line2.h"

void Vertex_Line2::Initialize()
{
	shader = new Shader(L"06_Triangle.fx");

	vertices[0].Position = Vector3(0.0f, 0.0f, 0.0f);
	vertices[1].Position = Vector3(1.0f, 0.0f, 0.0f);

	vertices[2].Position = Vector3(0.0f, 0.5f, 0.0f);
	vertices[3].Position = Vector3(1.0f, 0.5f, 0.0f);

	vertices[4].Position = Vector3(0.0f, -.5f, 0.0f);
	vertices[5].Position = Vector3(1.0f, -.5f, 0.0f);
	
	D3D11_BUFFER_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));	// ������� �� ������ ������ �� �ʱ�ȭ
	desc.ByteWidth = sizeof(Vertex) * 6;
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	
	D3D11_SUBRESOURCE_DATA subResource = { 0 };		// �Ϲ����� ����ü �ʱ�ȭ
	subResource.pSysMem = vertices;

	Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer));
	// Device		  : RAM�� ����Ǵ� ������ ������ �����ϹǷ� CPU�� ����
	// Device context : VRAM�� ����Ǵ� ���̴� ������ ���õǹǷ� GPU�� ����
}

void Vertex_Line2::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
}

void Vertex_Line2::Update()
{

}

void Vertex_Line2::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	//D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);

	shader->Draw(0, 0, 6);
	//shader->Draw(1, 0, 6, 2);
}