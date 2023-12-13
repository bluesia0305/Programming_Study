#include "stdafx.h"
#include "HeightmapDemo.h"

void HeightmapDemo::Initialize()
{
	Context::Get()->GetCamera()->RotationDegree(12, 0, 0);
	Context::Get()->GetCamera()->Position(35, 10, -55);

	shader	= new Shader(L"19_Terrain.fx");
	//terrain = new Terrain(shader, L"Terrain/Grayscale.png");
	terrain = new Terrain(shader, L"Terrain/Gray256.png");
	terrain->Pass(1);
}

void HeightmapDemo::Destroy()
{
	SafeDelete(shader);
	SafeDelete(terrain);
}

void HeightmapDemo::Update()
{
	terrain->Update();
}

void HeightmapDemo::Render()
{
	terrain->Render();
}