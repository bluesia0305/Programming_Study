#pragma once

class Mesh
{
public:
	typedef	VertexTextureNormal	MeshVertex;

	Mesh(Shader* shader);
	virtual ~Mesh();

	void Update();
	void Render();

public:
	void Pass(UINT val) { pass = val; }

	void Position(float x, float y, float z);
	void Position(Vector3& vec);
	void Position(Vector3* vec);

	void Rotation(float x, float y, float z);
	void Rotation(Vector3& vec);
	void Rotation(Vector3* vec);

	void RotationDegree(float x, float y, float z);
	void RotationDegree(Vector3& vec);
	void RotationDegree(Vector3* vec);

	void Scale(float x, float y, float z);
	void Scale(Vector3& vec);
	void Scale(Vector3* vec);

	Matrix World() { return world; }

	Vector3 Forward();
	Vector3 Up();
	Vector3 Right();

	void DiffuseMap(wstring file);

protected:
	virtual void Create();
	void CreateBuffer();

private:
	void UpdateWorld();

protected:
	MeshVertex*								vertices		= NULL;
	UINT*									indices			= NULL;
	
	UINT									vertexCount;
	UINT									indexCount;

private:
	Shader*									shader;
	UINT									pass			= 0;
	Vector3									position		= Vector3(0, 0, 0);
	Vector3									scale			= Vector3(0, 0, 0);
	Vector3									rotation		= Vector3(0, 0, 0);

	Matrix									world;

	ID3D11Buffer*							vertexBuffer	= NULL;
	ID3D11Buffer*							indexBuffer		= NULL;
	Texture*								diffuseMap		= NULL;
	ID3DX11EffectMatrixVariable*			sWorld;
	ID3DX11EffectMatrixVariable*			sView;
	ID3DX11EffectMatrixVariable*			sProjection;
	ID3DX11EffectShaderResourceVariable*	sDiffuseMap;
};