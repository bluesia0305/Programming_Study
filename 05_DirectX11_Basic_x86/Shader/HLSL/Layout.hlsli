// <HLSL ���α׷��� ���Ǽ��� ���� ����>
// 1) �޴� - Ȯ�� - Ȯ�� ����
//	  - 'HLSL' �˻� �� ������ �� 'HLSL Tools for Visual Studio' �ٿ�ε� �� ��ġ.

namespace Layout
{
	struct Vertex
	{
		// �ø�ƽ ����(Semantic name)
		// : {variable} : {semantic_name}
		//	 HLSL���� �������� �����̳� �ǹ̸� �ο��ϴ� �������,
		//	 ��ǻ�ʹ� �ش� �ø�ƽ ������ ���� � �������� Ȯ���Ѵ�.
		float4 Position : POSITION;
		//float4 Color	: COLOR;
		float4 Texcoord : TEXCOORD;
	};
	
	// RS �ܰ�� ��ǻ�Ϳ� ���� ó���Ǵ� �ܰ��̹Ƿ�, ��ǻ�Ͱ� ó���� �����͸� �ø�ƽ ���ӿ� ����ؾ�(SV_~) �Ѵ�.
	struct Pixel
	{
		// SV_~: ��ǻ�Ͱ� ó���ؾ� �ϴ� ������(System Value)���� ����ϴ� �ø�ƽ ����.
		float4 Position : SV_POSITION;
		//float4 Color	: COLOR;
		float4 Texcoord : TEXCOORD;
	};
    
    typedef float4 Color;
}