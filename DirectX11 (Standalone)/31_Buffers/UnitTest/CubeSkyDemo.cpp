#include "stdafx.h"
#include "CubeSkyDemo.h"

void CubeSkyDemo::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(20, 0, 0);
	Context::Get()->GetCamera()->Position(0, 40, -85);
	((Freedom*)Context::Get()->GetCamera())->Speed(75.0f, 7.5f);

	shader		= new Shader(L"25_Mesh.fx");
	sDirection	= shader->AsVector("Direction");

	sky = new CubeSky(L"Environment/GrassCube1024.dds");

	CreateMesh();

	cubeMapShader = new Shader(L"29_CubeMap.fx");
	cubeMap		  = new CubeMap(cubeMapShader);
	cubeMap->Texture(L"Environment/Earth1024.dds");
	cubeMap->Position(0, 20, 0);
	cubeMap->Scale(10, 10, 10);
}

void CubeSkyDemo::Destroy()
{
	SafeDelete(shader);
	SafeDelete(sky);

	SafeDelete(cube);
	SafeDelete(grid);
	for (UINT i = 0; i < 10; ++i)
	{
		SafeDelete(sphere[i]);
		SafeDelete(cylinder[i]);
	}

	SafeDelete(cubeMapShader);
	SafeDelete(cubeMap);
}

void CubeSkyDemo::Update()
{
	sky->Update();

	cube->Update();
	grid->Update();

	for (UINT i = 0; i < 10; ++i)
	{
		sphere[i]->Update();
		cylinder[i]->Update();
	}

	cubeMap->Update();
}

void CubeSkyDemo::Render()
{
	ImGui::SliderFloat3("Direction", direction, -1, 1);
	sDirection->SetFloatVector(direction);

	sky->Render();

	cube->Render();
	grid->Render();

	for (UINT i = 0; i < 10; ++i)
	{
		sphere[i]->Render();
		cylinder[i]->Render();
	}

	cubeMap->Render();
}

void CubeSkyDemo::CreateMesh()
{
	cube = new MeshCube(shader);
	cube->Position(0, 5, 0);
	cube->Scale(20, 10, 20);
	cube->DiffuseMap(L"Stones.png");

	grid = new MeshGrid(shader, 5, 5);
	grid->Scale(12, 1, 12);
	grid->DiffuseMap(L"Floor.png");

	for (UINT i = 0; i < 5; ++i)
	{
		cylinder[i * 2] = new MeshCylinder(shader, 0.5f, 3.0f, 20, 20);
		cylinder[i * 2]->Position(-30, 6, (float)i * 15.0f - 15.0f);
		cylinder[i * 2]->Scale(5, 5, 5);
		cylinder[i * 2]->DiffuseMap(L"Bricks.png");

		cylinder[i * 2 + 1] = new MeshCylinder(shader, 0.5f, 3.0f, 20, 20);
		cylinder[i * 2 + 1]->Position(30, 6, (float)i * 15.0f - 15.0f);
		cylinder[i * 2 + 1]->Scale(5, 5, 5);
		cylinder[i * 2 + 1]->DiffuseMap(L"Bricks.png");

		sphere[i * 2] = new MeshSphere(shader, 0.5f, 20, 20);
		sphere[i * 2]->Position(-30, 15.5f, (float)i * 15.0f - 15.0f);
		sphere[i * 2]->Scale(5, 5, 5);
		sphere[i * 2]->DiffuseMap(L"Wall.png");

		sphere[i * 2 + 1] = new MeshSphere(shader, 0.5f, 20, 20);
		sphere[i * 2 + 1]->Position(30, 15.5f, (float)i * 15.0f - 15.0f);
		sphere[i * 2 + 1]->Scale(5, 5, 5);
		sphere[i * 2 + 1]->DiffuseMap(L"Wall.png");
	}
}