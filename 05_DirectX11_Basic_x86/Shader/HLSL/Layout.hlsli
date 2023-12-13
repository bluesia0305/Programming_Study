// <HLSL 프로그래밍 편의성을 위한 설정>
// 1) 메뉴 - 확장 - 확장 관리
//	  - 'HLSL' 검색 을 수행한 뒤 'HLSL Tools for Visual Studio' 다운로드 및 설치.

namespace Layout
{
	struct Vertex
	{
		// 시맨틱 네임(Semantic name)
		// : {variable} : {semantic_name}
		//	 HLSL에서 데이터의 역할이나 의미를 부여하는 기능으로,
		//	 컴퓨터는 해당 시맨틱 네임을 통해 어떤 역할인지 확인한다.
		float4 Position : POSITION;
		//float4 Color	: COLOR;
		float4 Texcoord : TEXCOORD;
	};
	
	// RS 단계는 컴퓨터에 의해 처리되는 단계이므로, 컴퓨터가 처리할 데이터를 시맨틱 네임에 명시해야(SV_~) 한다.
	struct Pixel
	{
		// SV_~: 컴퓨터가 처리해야 하는 데이터(System Value)임을 명시하는 시맨틱 네임.
		float4 Position : SV_POSITION;
		//float4 Color	: COLOR;
		float4 Texcoord : TEXCOORD;
	};
    
    typedef float4 Color;
}