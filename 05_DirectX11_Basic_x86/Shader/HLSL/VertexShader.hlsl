// <VertexShader.hlsl ���Ͽ� ���� HLSL �����Ϸ� ����>
// 1) ���� �Ӽ� - HLSL �����Ϸ� - ��� �ɼ�
//    - ���̴� ����: ������ ���̴�(/vs)
//	  - ���̴� ��: Shader Model 5.0(/5_0)
//	  - ������ �̸�: Shader::Vertex
//	  - ��� ���� �̸�: Bytecode
//	  - ��� ���� �̸�: $(ProjectDir)\Shader\Bytecode\VertexShader.h

#include "Layout.hlsli"

namespace Shader
{
	// Constant buffer�� �ҷ��� ��(register), matrix ���� ������ ����(buffer ���·� ����� ���� �� �����Ƿ�).
    // * column_major : ���켱������ �����͸� ����(�⺻��).
    // * row_major    : ��켱������ �����͸� ����.
	cbuffer Transform : register(B0) { column_major matrix World; }
    cbuffer Transform : register(B1) { column_major matrix View; }
	cbuffer Transform : register(B2) { column_major matrix Projection; }
	Layout::Pixel Vertex(const Layout::Vertex Input)
	{
		Layout::Pixel Output =
		{
			Input.Position,
			Input.Texcoord
		};
        
		// ��ȯ��� ����.
		Output.Position = mul(Output.Position, World);
        Output.Position = mul(Output.Position, View);
		Output.Position = mul(Output.Position, Projection);

		return Output;	// RS Stage�� �����ϴ� ��.
	}
}