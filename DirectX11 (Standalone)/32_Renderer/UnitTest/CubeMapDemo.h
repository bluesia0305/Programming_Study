#pragma once
#include "Systems/IExecute.h"

class CubeMapDemo : public IExecute
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
	void CreateMesh();

private:
	Shader*							shader;

	Vector3							direction = Vector3(-1, -1, 1);
	ID3DX11EffectVectorVariable*	sDirection;
	
	MeshQuad*						quad;
	MeshCube*						cube;
	MeshGrid*						grid;
	MeshSphere*						sphere[10];
	MeshCylinder*					cylinder[10];

	Shader*							cubeMapShader;
	CubeMap*						cubeMap;
};