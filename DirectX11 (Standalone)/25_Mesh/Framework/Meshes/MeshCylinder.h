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
	UINT	stackCount;		// XZ 평면에 평행하게 자르는 갯수(위도 latitude 등분)
	UINT	sliceCount;		// Y축에 평행하게 자르는 갯수(경도 longitude 등분)
};