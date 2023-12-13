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
	UINT	stackCount;		// XZ ��鿡 �����ϰ� �ڸ��� ����(���� latitude ���)
	UINT	sliceCount;		// Y�࿡ �����ϰ� �ڸ��� ����(�浵 longitude ���)
};