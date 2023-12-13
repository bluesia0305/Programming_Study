#include "stdafx.h"
#include "MeshDemo.h"

void MeshDemo::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(20, 0, 0);
	Context::Get()->GetCamera()->Position(0, 40, -85);
	((Freedom*)Context::Get()->GetCamera())->Speed(50.0f, 5.0f);

	shader		= new Shader(L"25_Mesh.fx");
	sDirection	= shader->AsVector("Direction");

	CreateMesh();
}

void MeshDemo::Destroy()
{
	SafeDelete(shader);
	SafeDelete(quad);
	SafeDelete(cube);
	SafeDelete(grid);
	for (UINT i = 0; i < 10; ++i)
	{
		SafeDelete(sphere[i]);
		SafeDelete(cylinder[i]);
	}
}

void MeshDemo::Update()
{
	//Vector3 scale;
	//quad->Scale(&scale);
	//
	//ImGui::SliderFloat2("Scale", scale, -3, 3);
	//quad->Scale(scale);

	//quad->Update();

	cube->Update();
	grid->Update();

	for (UINT i = 0; i < 10; ++i)
	{
		sphere[i]->Update();
		cylinder[i]->Update();
	}
}

void MeshDemo::Render()
{
	sDirection->SetFloatVector(direction);
	ImGui::SliderFloat3("Direction", direction, -1, 1);

	static int pass = 0;
	ImGui::InputInt("Pass", &pass);
	if (pass < 0) pass = abs(pass);
	pass %= 2;

	//quad->Render();
	cube->Render();
	grid->Render();

	for (UINT i = 0; i < 10; ++i)
	{
		sphere[i]->Pass(pass);
		sphere[i]->Render();

		cylinder[i]->Pass(pass);
		cylinder[i]->Render();
	}
}

void MeshDemo::CreateMesh()
{
	//quad = new MeshQuad(shader);
	//quad->Scale(2, 2, 2);
	//quad->Position(0, 1, 0);
	//quad->DiffuseMap(L"Box.png");

	cube = new MeshCube(shader);
	cube->GetTransform()->Position(0, 5, 0);
	cube->GetTransform()->Scale(20, 10, 20);
	cube->DiffuseMap(L"Stones.png");

	grid = new MeshGrid(shader, 5, 5);
	grid->GetTransform()->Scale(12, 1, 12);
	grid->DiffuseMap(L"Floor.png");

	for (UINT i = 0; i < 5; ++i)
	{
		cylinder[i * 2] = new MeshCylinder(shader, 0.5f, 3.0f, 20, 20);
		cylinder[i * 2]->GetTransform()->Position(-30, 6, (float)i * 15.0f - 15.0f);
		cylinder[i * 2]->GetTransform()->Scale(5, 5, 5);
		cylinder[i * 2]->DiffuseMap(L"Bricks.png");

		cylinder[i * 2 + 1] = new MeshCylinder(shader, 0.5f, 3.0f, 20, 20);
		cylinder[i * 2 + 1]->GetTransform()->Position(30, 6, (float)i * 15.0f - 15.0f);
		cylinder[i * 2 + 1]->GetTransform()->Scale(5, 5, 5);
		cylinder[i * 2 + 1]->DiffuseMap(L"Bricks.png");

		sphere[i * 2] = new MeshSphere(shader, 0.5f, 20, 20);
		sphere[i * 2]->GetTransform()->Position(-30, 15.5f, (float)i * 15.0f - 15.0f);
		sphere[i * 2]->GetTransform()->Scale(5, 5, 5);
		sphere[i * 2]->DiffuseMap(L"Wall.png");

		sphere[i * 2 + 1] = new MeshSphere(shader, 0.5f, 20, 20);
		sphere[i * 2 + 1]->GetTransform()->Position(30, 15.5f, (float)i * 15.0f - 15.0f);
		sphere[i * 2 + 1]->GetTransform()->Scale(5, 5, 5);
		sphere[i * 2 + 1]->DiffuseMap(L"Wall.png");
	}
}