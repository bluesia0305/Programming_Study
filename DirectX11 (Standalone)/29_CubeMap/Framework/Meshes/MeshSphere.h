#pragma once

class MeshSphere : public Mesh
{
public:
	MeshSphere(Shader* shader, float radius, UINT stackCount = 20, UINT sliceCount = 20);
	~MeshSphere();

private:
	void Create() override;

private:
	float	radius;
	UINT	stackCount;		// XZ 평면에 평행하게 자르는 갯수(위도 latitude 등분)
	UINT	sliceCount;		// Y축에 평행하게 자르는 갯수(경도 longitude 등분)
};