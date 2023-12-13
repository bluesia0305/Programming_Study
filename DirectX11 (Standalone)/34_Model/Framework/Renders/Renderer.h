#pragma once

class Renderer
{
public:
	Renderer(Shader* shader);
	Renderer(wstring shaderFile);
	virtual ~Renderer();

	Shader* GetShader() { return shader; }

	UINT& Pass() { return pass; }
	void Pass(UINT val) { pass = val; }

	virtual void Update();
	virtual void Render();

	Transform* GetTransform() { return transform; }

private:
	void Initialize();

protected:
	void Topology(D3D11_PRIMITIVE_TOPOLOGY val) { topology = val; }

protected:
	Shader* shader;

	Transform* transform;
	VertexBuffer* vertexBuffer = NULL;
	IndexBuffer* indexBuffer = NULL;

	UINT vertexCount = 0;
	UINT indexCount = 0;

private:
	// 기존에 동적할당 된 셰이더를 사용할 것인지 새로 동적할당을 할 것인지 여부
	bool bCreateShader = false;

	D3D11_PRIMITIVE_TOPOLOGY topology = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	UINT pass = 0;

	PerFrame* perFrame;
};