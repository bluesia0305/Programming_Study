#include "stdafx.h"
#include "CubeDemo.h"

void CubeDemo::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(13, 0, 0);
	Context::Get()->GetCamera()->Position(0, 7, -19);

	shader = new Shader(L"15_Cube.fx");

	float w = 0.5f, h = 0.5f, d = 0.5f;

	//// Generate Vertex Data
	//vertexCount = 24;
	//vertices	= new Vertex[vertexCount];
	//
	//// Front
	//vertices[0].Position = Vector3(-w, -h, -d);
	//vertices[1].Position = Vector3(-w, +h, -d);
	//vertices[2].Position = Vector3(+w, -h, -d);
	//vertices[3].Position = Vector3(+w, +h, -d);
	//
	//// Left
	//vertices[4].Position = Vector3(-w, -h, +d);
	//vertices[5].Position = Vector3(-w, +h, +d);
	//vertices[6].Position = Vector3(-w, -h, -d);
	//vertices[7].Position = Vector3(-w, +h, -d);
	//
	//// Right
	//vertices[8].Position = Vector3(+w, -h, -d);
	//vertices[9].Position = Vector3(+w, +h, -d);
	//vertices[10].Position = Vector3(+w, -h, +d);
	//vertices[11].Position = Vector3(+w, +h, +d);
	//
	//// Back
	//vertices[12].Position = Vector3(+w, -h, +d);
	//vertices[13].Position = Vector3(+w, +h, +d);
	//vertices[14].Position = Vector3(-w, -h, +d);
	//vertices[15].Position = Vector3(-w, +h, +d);
	//
	//// Top
	//vertices[16].Position = Vector3(-w, +h, -d);
	//vertices[17].Position = Vector3(-w, +h, +d);
	//vertices[18].Position = Vector3(+w, +h, -d);
	//vertices[19].Position = Vector3(+w, +h, +d);
	//
	//// Bottom
	//vertices[20].Position = Vector3(-w, -h, +d);
	//vertices[21].Position = Vector3(-w, -h, -d);
	//vertices[22].Position = Vector3(+w, -h, +d);
	//vertices[23].Position = Vector3(+w, -h, -d);
	//
	//
	//indexCount = 36;
	//indices = new UINT[indexCount]
	//{
	//	0, 1, 2, 2, 1, 3,			// Forward
	//	4, 5, 6, 6, 5, 7,			// Left
	//	8, 9, 10, 10, 9, 11,		// Right
	//	12, 13, 14, 14, 13, 15,		// Back
	//	16, 17, 18, 18, 17, 19,		// Top
	//	20, 21, 22, 22, 21, 23		// Bottom
	//};


	// Test
	vertexCount = 8;
	vertices	= new Vertex[vertexCount];

	vertices[0].Position  = Vector3(-w, +h, -d);
	vertices[1].Position  = Vector3(-w, +h, +d);
	vertices[2].Position  = Vector3(+w, +h, +d);
	vertices[3].Position  = Vector3(+w, +h, -d);
	vertices[4].Position  = Vector3(-w, -h, -d);
	vertices[5].Position  = Vector3(-w, -h, +d);
	vertices[6].Position  = Vector3(+w, -h, +d);
	vertices[7].Position  = Vector3(+w, -h, -d);


	indexCount = 36;
	indices = new UINT[indexCount]
	{
		4, 0, 7, 7, 0, 3,			// Forward
		5, 1, 4, 4, 1, 0,			// Left
		7, 3, 6, 6, 3, 2,			// Right
		6, 2, 5, 5, 2, 1,			// Back
		0, 1, 3, 3, 1, 2,			// Top
		5, 4, 6, 6, 4, 7			// Bottom
	};


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

void CubeDemo::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
	SafeRelease(indexBuffer);
}

void CubeDemo::Update()
{
	static float rotSpeed = 2.0f;
	ImGui::SliderFloat("Rotation Speed", &rotSpeed, 1, 5);

	static float moveSpeed = 10.0f;
	ImGui::SliderFloat("Move Speed", &moveSpeed, 5, 20);

	if (Keyboard::Get()->Press(VK_SHIFT))
	{
		if (Keyboard::Get()->Press(VK_RIGHT))
			rotation.z -= rotSpeed * Time::Delta();
		else if (Keyboard::Get()->Press(VK_LEFT))
			rotation.z += rotSpeed * Time::Delta();

		if (Keyboard::Get()->Press(VK_UP))
			rotation.x += rotSpeed * Time::Delta();
		else if (Keyboard::Get()->Press(VK_DOWN))
			rotation.x -= rotSpeed * Time::Delta();
	}
	else
	{
		if (Keyboard::Get()->Press(VK_RIGHT))
			position.x += moveSpeed * Time::Delta();
		else if (Keyboard::Get()->Press(VK_LEFT))
			position.x -= moveSpeed * Time::Delta();

		if (Keyboard::Get()->Press(VK_UP))
			position.z += moveSpeed * Time::Delta();
		else if (Keyboard::Get()->Press(VK_DOWN))
			position.z -= moveSpeed * Time::Delta();
	}
	
	Matrix R, T;
	D3DXMatrixRotationYawPitchRoll(&R, rotation.y, rotation.x, rotation.z);
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = R * T;
}

void CubeDemo::Render()
{
	// Vertex shader로 전달할 W, V, P 행렬 설정
	shader->AsVector("Color")->SetFloatVector(color);
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