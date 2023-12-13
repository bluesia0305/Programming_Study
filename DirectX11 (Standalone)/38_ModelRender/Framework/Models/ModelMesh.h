#pragma once

class ModelBone
{
public:
	// 생성자, 소멸자를 private으로 만들고 Model 클래스를 프렌드로 설정
	// -> Model 클래스 내에서만 ModelBone 인스턴스화 가능하도록 하는 것
	friend class Model;

private:
	ModelBone();
	~ModelBone();

public:
	int Index()						{ return index; }
	int ParentIndex()				{ return parentIndex; }
	ModelBone* Parent()				{ return parent; }
	wstring Name()					{ return name; }
	Matrix& Transform()				{ return transform; }
	void Transform(Matrix& matrix)	{ transform = matrix; }
	vector<ModelBone *>& Childs()	{ return childs; }

private:
	int index;
	wstring name;

	int parentIndex;
	ModelBone* parent;

	Matrix transform;
	vector<ModelBone*> childs;
};

/////////////////////////////////////////////////////////////////////////////////////////

class ModelMesh
{
public:
	friend class Model;

private:
	ModelMesh();
	~ModelMesh();

	void Binding(Model* model);

public:
	void Pass(UINT val)		{ pass = val; }
	void SetShader(Shader* shader);

	void Update();
	void Render();

	wstring Name()			{ return name; }

	int BoneIndex()			{ return boneIndex; }
	class ModelBone* Bone() { return bone; }

	void Transforms(Matrix* transforms);
	void SetTransform(Transform* transform);

private:
	struct BoneDesc
	{
		Matrix Transforms[MAX_MODEL_TRANSFORMS];
		UINT Index;
		float Padding[3];
	} boneDesc;

private:
	wstring name;

	Shader* shader;
	UINT pass = 0;

	Transform* transform = nullptr;
	PerFrame* perFrame = nullptr;

	wstring materialName = L"";

	int boneIndex;
	class ModelBone* bone;

	UINT vertexCount;
	Model::ModelVertex* vertices;
	VertexBuffer* vertexBuffer;

	UINT indexCount;
	UINT* indices;
	IndexBuffer* indexBuffer;

	ConstantBuffer* boneBuffer;
	ID3DX11EffectConstantBuffer* sBoneBuffer;
};