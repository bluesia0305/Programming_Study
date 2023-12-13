// <PixelShader.hlsl 파일에 대한 HLSL 컴파일러 설정>
// 1) 구성 속성 - HLSL 컴파일러 - 모든 옵션
//    - 셰이더 형식: 픽셀 셰이더(/ps)
//	  - 셰이더 모델: Shader Model 5.0(/5_0)
//	  - 진입점 이름: Shader::Pixel
//	  - 헤더 변수 이름: Bytecode
//	  - 헤더 파일 이름: $(ProjectDir)\Shader\Bytecode\PixelShader.h

#include "Layout.hlsli"

namespace Shader
{
    const Texture2D Resource : register(T0);

    Layout::Color Pixel(const Layout::Pixel Input) : SV_TARGET    // SV_TARGET: 반환형이 렌더 타겟으로 전달됨을 명시.
    {
        Layout::Color Output =
        {
            Resource.Load(int3(Input.Texcoord.x, Input.Texcoord.y, 0))
        };
        
        // alpha 값(Output.a)이 0일 경우, 해당 픽셀의 값을 버린다(투명 픽셀).
        if (Output.a == 0) discard;

	    return Output;
    }   
}