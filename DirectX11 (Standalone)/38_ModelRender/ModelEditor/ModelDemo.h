#pragma once
#include "Systems/IExecute.h"

class ModelDemo : public IExecute
{
public:
	virtual void Initialize() override;
	virtual void Ready() override {}
	virtual void Destroy() override {}
	virtual void Update() override;
	virtual void PreRender() override {}
	virtual void Render() override;
	virtual void PostRender() override {}
	virtual void ResizeScreen() override {}

private:
	void Tank();
	void Airplane();
	void Tower();

private:
	Shader* shader;
	
	ModelRender* tank = nullptr;
	ModelRender* airplane = nullptr;
	ModelRender* tower = nullptr;

	CubeSky* sky;
	Vector3 direction = Vector3(-1, -1, 1);

	Shader* gridShader;
	MeshGrid* grid;
};