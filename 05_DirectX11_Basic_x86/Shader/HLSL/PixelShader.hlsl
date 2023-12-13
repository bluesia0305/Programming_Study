// <PixelShader.hlsl ���Ͽ� ���� HLSL �����Ϸ� ����>
// 1) ���� �Ӽ� - HLSL �����Ϸ� - ��� �ɼ�
//    - ���̴� ����: �ȼ� ���̴�(/ps)
//	  - ���̴� ��: Shader Model 5.0(/5_0)
//	  - ������ �̸�: Shader::Pixel
//	  - ��� ���� �̸�: Bytecode
//	  - ��� ���� �̸�: $(ProjectDir)\Shader\Bytecode\PixelShader.h

#include "Layout.hlsli"

namespace Shader
{
    const Texture2D Resource : register(T0);

    Layout::Color Pixel(const Layout::Pixel Input) : SV_TARGET    // SV_TARGET: ��ȯ���� ���� Ÿ������ ���޵��� ���.
    {
        Layout::Color Output =
        {
            Resource.Load(int3(Input.Texcoord.x, Input.Texcoord.y, 0))
        };
        
        // alpha ��(Output.a)�� 0�� ���, �ش� �ȼ��� ���� ������(���� �ȼ�).
        if (Output.a == 0) discard;

	    return Output;
    }   
}