#pragma once
#include "Systems/IExecute.h"

class GridDemo : public IExecute
{
public:
	virtual void Initialize() override;
	virtual void Ready() override {}
	virtual void Destroy() override;
	virtual void Update() override;
	virtual void PreRender() override {}
	virtual void Render() override;
	virtual void PostRender() override {}
	virtual void ResizeScreen() override {}

private:
	UINT			width = 3, height = 3, vertexCount, indexCount;

	Shader*			shader;
	Vertex*			vertices;		// �����Ҵ����� ����
	ID3D11Buffer*	vertexBuffer;
	
	UINT*			indices;		// �����Ҵ����� ����
	ID3D11Buffer*	indexBuffer;

	Matrix			world;
};