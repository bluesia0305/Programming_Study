// <VertexShader.hlsl 파일에 대한 HLSL 컴파일러 설정>
// 1) 구성 속성 - HLSL 컴파일러 - 모든 옵션
//    - 셰이더 형식: 꼭짓점 셰이더(/vs)
//	  - 셰이더 모델: Shader Model 5.0(/5_0)
//	  - 진입점 이름: Shader::Vertex
//	  - 헤더 변수 이름: Bytecode
//	  - 헤더 파일 이름: $(ProjectDir)\Shader\Bytecode\VertexShader.h

#include "Layout.hlsli"

namespace Shader
{
	// Constant buffer를 불러온 뒤(register), matrix 형식 변수에 저장(buffer 상태로 행렬을 곱할 수 없으므로).
    // * column_major : 열우선순위로 데이터를 저장(기본값).
    // * row_major    : 행우선순위로 데이터를 저장.
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
        
		// 변환행렬 곱셈.
		Output.Position = mul(Output.Position, World);
        Output.Position = mul(Output.Position, View);
		Output.Position = mul(Output.Position, Projection);

		return Output;	// RS Stage로 전달하는 값.
	}
}