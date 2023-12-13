#pragma once

class MeshCylinder : public Mesh
{
public:
	MeshCylinder(Shader* shader, float radius, float height, UINT stackCount, UINT sliceCount);
	MeshCylinder(Shader* shader, float topRadius, float botRadius, float height, UINT stackCount, UINT sliceCount);
	~MeshCylinder();

private:
	void Create() override;

private:
	void BuildTopCap(vector<MeshVertex>& vertices, vector<UINT>& indices);
	void BuildBottomCap(vector<MeshVertex>& vertices, vector<UINT>& indices);

private:
	float	topRadius;
	float	botRadius;
	float	height;
	UINT	stackCount;		// XZ ��鿡 �����ϰ� �ڸ��� ����(���� latitude ���)
	UINT	sliceCount;		// Y�࿡ �����ϰ� �ڸ��� ����(�浵 longitude ���)
};