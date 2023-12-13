#include "stdafx.h"
#include "TextureLoadDemo.h"

void TextureLoadDemo::Initialize()
{
	Context::Get()->GetCamera()->Position(0, 0, -5.0f);

	shader = new Shader(L"16_Texture.fx");

	// Local 좌표
	vertices[0].Position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[1].Position = Vector3(-0.5f,  0.5f, 0.0f);
	vertices[2].Position = Vector3( 0.5f, -0.5f, 0.0f);
	vertices[3].Position = Vector3( 0.5f,  0.5f, 0.0f);

	vertices[0].Uv		 = Vector2(0, 1);
	vertices[1].Uv		 = Vector2(0, 0);
	vertices[2].Uv		 = Vector2(1, 1);
	vertices[3].Uv		 = Vector2(1, 0);

	// Create Vertex Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = sizeof(VertexTexture) * 4;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = vertices;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &vertexBuffer));
	}

	// Create Index Buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.ByteWidth = sizeof(UINT) * 6;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;

		D3D11_SUBRESOURCE_DATA subResource = { 0 };
		subResource.pSysMem = indices;

		Check(D3D::GetDevice()->CreateBuffer(&desc, &subResource, &indexBuffer));
	}

	D3DXMatrixIdentity(&world);
}

void TextureLoadDemo::Destroy()
{
	SafeDelete(shader);
	SafeRelease(vertexBuffer);
	SafeRelease(indexBuffer);
	//SafeRelease(srv);
	SafeDelete(texture);
}

void TextureLoadDemo::Update()
{
	if (ImGui::Button("Open") == true)
	{
		function<void(wstring)> func = bind(&TextureLoadDemo::LoadTexture, this, placeholders::_1);
		Path::OpenFileDialog(L"", Path::ImageFilter, L"../../_Textures/", func, D3D::GetDesc().Handle);
	}
}

void TextureLoadDemo::Render()
{
	// Vertex shader로 전달할 W, V, P 행렬 설정
	shader->AsMatrix("World")->SetMatrix(world);
	shader->AsMatrix("View")->SetMatrix(Context::Get()->View());
	shader->AsMatrix("Projection")->SetMatrix(Context::Get()->Projection());
	if (texture)
		shader->AsSRV("Map")->SetResource(texture->SRV());

	UINT stride = sizeof(VertexTexture);
	UINT offset = 0;

	D3D::GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	D3D::GetDC()->IASetIndexBuffer(indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	D3D::GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	
	shader->DrawIndexed(0, 0, 6);
}

void TextureLoadDemo::LoadTexture(wstring file)
{
	//MessageBox(NULL, file.c_str(), L"", MB_OK);
	SafeDelete(texture);
	texture = new Texture(file);
}
