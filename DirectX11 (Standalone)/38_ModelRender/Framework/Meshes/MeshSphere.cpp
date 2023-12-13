#include "Framework.h"
#include "MeshSphere.h"

MeshSphere::MeshSphere(Shader * shader, float radius, UINT stackCount, UINT sliceCount)
	: Mesh(shader), radius(radius), stackCount(stackCount), sliceCount(sliceCount)
{

}

MeshSphere::~MeshSphere()
{

}

void MeshSphere::Create()
{
	std::vector<MeshVertex> v;
	v.push_back(MeshVertex(0, radius, 0, 0, 0, 0, 1, 0));

	float phiStep	= Math::PI / stackCount;			// phi = latitude = x축 회전 각도
	float thetaStep = Math::PI * 2.0f / sliceCount;		// theta = longitude = y축 회전 각도

	for (UINT i = 1; i <= stackCount - 1; ++i)
	{
		float phi = i * phiStep;

		for (UINT j = 0; j <= sliceCount; ++j)
		{
			float theta = j * thetaStep;

			Vector3 p = Vector3
			(
				(radius * sinf(phi) * sinf(theta)),
				(radius * cos(phi)),
				(radius * sinf(phi) * cosf(theta))
			);

			Vector3 n;
			D3DXVec3Normalize(&n, &p);

			Vector2 uv = Vector2(theta / (Math::PI * 2), phi / Math::PI);

			v.push_back(MeshVertex(p.x, p.y, p.z, uv.x, uv.y, n.x, n.y, n.z));
		}
	}

	v.push_back(MeshVertex(0, -radius, 0, 0, 0, 0, -1, 0));

	vertices = new MeshVertex[v.size()];
	vertexCount = v.size();
	std::copy(v.begin(), v.end(), stdext::checked_array_iterator<MeshVertex*>(vertices, vertexCount));

	std::vector<UINT> i;
	for (UINT j = 1; j <= sliceCount; j++)
	{
		i.push_back(0);
		i.push_back(j);
		i.push_back(j + 1);
	}

	UINT baseIndex = 1;								// Index: 0이 극점이므로, offset을 주는 것
	UINT ringVertexCount = sliceCount + 1;			// 1 stack에 정점이 몇 개인가를 표현
	for (UINT k = 0; k < stackCount - 2; k++)
	{
		for (UINT j = 0; j < sliceCount; j++)
		{
			i.push_back(baseIndex + k		* ringVertexCount + j + 1);
			i.push_back(baseIndex + k		* ringVertexCount + j);
			i.push_back(baseIndex + (k + 1) * ringVertexCount + j);

			i.push_back(baseIndex + k		* ringVertexCount + j + 1);
			i.push_back(baseIndex + (k + 1)	* ringVertexCount + j);
			i.push_back(baseIndex + (k + 1) * ringVertexCount + j + 1);
		}
	}

	UINT southPoleIndex = v.size() - 1;				// 아래쪽 극점의 index (맨 마지막 정점)
	baseIndex = southPoleIndex - ringVertexCount;	// 극점 및 바로 위층 stack 정점의 갯수만큼 뺀 것을 offset으로 주는 것

	for (UINT k = 0; k < sliceCount; k++)
	{
		i.push_back(southPoleIndex);
		i.push_back(baseIndex + k + 1);
		i.push_back(baseIndex + k);
	}

	indices		= new UINT[i.size()];
	indexCount	= i.size();
	std::copy(i.begin(), i.end(), stdext::checked_array_iterator<UINT *>(indices, indexCount));
}