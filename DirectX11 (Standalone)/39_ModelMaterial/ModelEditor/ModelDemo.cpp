#include "stdafx.h"
#include "ModelDemo.h"

void ModelDemo::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(20, 0, 0);
	Context::Get()->GetCamera()->Position(1, 36, -85);

	shader = new Shader(L"38_Model.fx");
	Tank();
	Airplane();
	Tower();
	Kachujin();

	sky = new CubeSky(L"Environment/GrassCube1024.dds");

	gridShader = new Shader(L"25_Mesh.fx");
	grid = new MeshGrid(gridShader, 6, 6);
	grid->GetTransform()->Scale(12, 1, 12);
	grid->DiffuseMap(L"Floor.png");
}

void ModelDemo::Update()
{
	sky->Update();
	grid->Update();

	if (tank != nullptr) tank->Update();
	if (airplane != nullptr) airplane->Update();
	if (tower != nullptr) tower->Update();
	if (kachujin != nullptr) kachujin->Update();
}

void ModelDemo::Render()
{
	ImGui::SliderFloat3("Direction", direction, -1, 1);
	shader->AsVector("Direction")->SetFloatVector(direction);
	gridShader->AsVector("Direction")->SetFloatVector(direction);

	static int pass = 0;
	ImGui::InputInt("Pass", &pass);
	if (pass < 0) pass = abs(pass);
	pass %= 2;

	sky->Render();
	grid->Render();

	if (tank != nullptr)
	{
		tank->Pass(pass);
		tank->Render();
	}

	if (airplane != nullptr)
	{
		airplane->Pass(pass);
		airplane->Render();
	}

	if (tower != nullptr)
	{
		tower->Pass(pass);
		tower->Render();
	}

	if (kachujin != nullptr)
	{
		kachujin->Pass(pass);
		kachujin->Render();
	}
}

void ModelDemo::Tank()
{
	tank = new ModelRender(shader);
	tank->ReadMesh(L"Tank/Tank");
	tank->GetTransform()->Position(20, 0, 0);
}

void ModelDemo::Airplane()
{
	airplane = new ModelRender(shader);
	airplane->ReadMesh(L"B787/Airplane");
	airplane->GetTransform()->Scale(0.005f, 0.005f, 0.005f);
}

void ModelDemo::Tower()
{
	tower = new ModelRender(shader);
	tower->ReadMesh(L"Tower/Tower");
	tower->GetTransform()->Position(-20, 0, 0);
	tower->GetTransform()->Scale(0.01f, 0.01f, 0.01f);
}

void ModelDemo::Kachujin()
{
	kachujin = new ModelRender(shader);
	kachujin->ReadMesh(L"Kachujin/Mesh");
	kachujin->GetTransform()->Position(0, 0, -30);
	kachujin->GetTransform()->Scale(0.025f, 0.025f, 0.025f);
}
