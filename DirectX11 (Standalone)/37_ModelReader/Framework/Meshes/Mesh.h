#pragma once

class Mesh : public Renderer
{
public:
	typedef	VertexTextureNormal	MeshVertex;

	Mesh(Shader* shader);
	virtual ~Mesh();

	void Update();
	void Render();

protected:
	virtual void Create() = 0;

public:
	void DiffuseMap(wstring file);

protected:
	MeshVertex*								vertices		= NULL;
	UINT*									indices			= NULL;

private:
	Texture*								diffuseMap		= NULL;
	ID3DX11EffectShaderResourceVariable*	sDiffuseMap;
};