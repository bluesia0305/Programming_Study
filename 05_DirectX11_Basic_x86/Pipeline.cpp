#include <d3d11.h>		// d3d11 헤더 내에 Windows 헤더가 포함되어있음(중복 include 안해도 됨).
#include <cassert>		// 매크로 함수 assert()를 사용하기 위해 추가하는 헤더.
#include "FreeImage.h"	// 다양한 이미지 파일 형식에 대해 간편하게 프로그래밍할 수 있도록 만든 헤더(라이브러리 별도 추가 필요).
#pragma comment(linker, "/entry:WinMainCRTStartup /subSystem:console")

// <라이브러리 연결 방법>
// - d3d11.h 헤더 내에는 함수의 정의가 없이 선언만 되어있으므로 함수를 사용하기 위해 라이브러리와 연결이 필요.
//   * 프로젝트 속성 -> 링커 - 모든 옵션 - 추가 종속성 의 '맨 앞'에 d3d11.lib; 를 추가하거나 아래와 같은 코드 작성.
#pragma comment(lib, "d3d11.lib")
//   (사용자 라이브러리 폴더를 추가하는 경우)
//	 * 프로젝트 속성 -> 링커 - 모든 옵션 - 추가 라이브러리 디렉터리 에서 설정 가능함.


// 반환형이 HRESULT 형식인 함수에 대해 오류 발생 시 프로그램 파괴를 위해 아래와 같은 매크로 함수 작성 후 사용.
#ifndef _DEBUG												// #ifndef == #if not defined.
#define MUST(expression) (expression)						// Release 모드일 때 실행문.
#else
#define MUST(expression) assert(SUCCEEDED(expression))		// Debug 모드일 때 실행문.
#endif

namespace Input
{
	void Procedure(HWND const, UINT const, WPARAM const, LPARAM const);

	namespace Get
	{ bool Down(WPARAM const); }
}

namespace Pipeline
{
	// 렌더링 파이프라인(Rendering pipeline)
	// : 화면에 그래픽이 그려지는 단계별 과정.
	//	  1) IA(Input assembler) Stage
	//	  2) VS(Vertex shader) Stage
	//	  3) HS(Hull shader) Stage  ────────┐
	//	  4) TS(Tessellator) Stage			│	직접적인 코딩으로
	//	  5) DS(Domain shader) Stage		│	이루어지는 작업이 아님.
	//	  6) GS(Geometric shader) Stage		│
	//	  7) SO(Stream output) Stage  ──────┘
	//	  8) RS(Rasterizer) Stage
	//	  9) PS(Pixel shader) Stage
	//	 10) OM(Output merge) Stage

	namespace
	{
		// <DirectX11의 이해를 위한 기본 개념>====================================================================================================
		//
		// (★중요)
		// 1) COM 인터페이스 관련
		//	  - COM 인터페이스(COM Interface)
		//		: 사용자가 임의로 만들 수 있는 자료형이 아님(인터페이스 = 구현에 대해 아무 것도 지시하지 않고 개체가 지원할 수 있는 메서드 집합).
		//		  * 해당 자료형으로 동적할당이 불가능하다(인터페이스이기도 하지만, 불가능하도록 동적할당 연산자 자체를 오버로딩).
		//		  * COM 인터페이스 형식의 객체의 생성/해제
		//			- 생성: Descriptor 선언 후 Create~ 함수를 이용해 생성(디바이스, 디바이스 컨텍스트, 스왑 체인의 경우에는 D3D11Create~ 함수).
		//			- 해제: {object}->Release() 메서드를 이용해 해제.
		//
		//	  - 설명자(Descriptor, 서술자)
		//		: 리소스를 GPU별로 특정되는 형식에 맞게 서술해주는 경량의 자료구조.
		//
		//--------------------------------------------------------------------------------------------------------------------------------------
		//
		// (★중요)
		// 2) 렌더링 파이프라인 내의 주요 객체들
		//	  - 디바이스(Device) ▶ ID3D11Device* 형식
		//		: 리소스를 만들고 디스플레이 어댑터(그래픽 카드)의 기능을 추상화 한 객체.
		//		  * 그래픽 리소스의 생성, 그래픽스 파이프라인 구성, 셰이더 생성.
		// 
		//	  - 디바이스 컨텍스트(Device context) ▶ ID3D11DeviceContext* 형식
		//		: 디바이스가 사용되는 상황 또는 설정을 포함하는 객체.
		//		  더 구체적으로, 디바이스 컨텍스트는 디바이스가 소유한 리소스를 사용하여
		//		  파이프라인 상태를 설정하고 렌더링 명령을 생성한다.
		//		  * 디바이스를 통해 생성한 객체(그래픽 리소스, 셰이더)를 파이프라인 상에 결합(Set~ 함수)하고 렌더링을 수행.
		//
		//	  - 스왑 체인(Swap chain) ▶ IDXGISwapChain* 형식
		//		: 사용자에게 프레임을 표시하는 데 사용되는 프레임 버퍼(frame buffer)의 컬렉션.
		//		  * 전면 버퍼(Front buffer): 현재 화면에 출력되고 있는 프레임 버퍼.
		//		  * 후면 버퍼(Back buffer) : 전면 버퍼가 아닌 버퍼(응용 프로그램은 전면 버퍼에 직접 출력하지 않고 후면 버퍼에만 출력).
		//
		//	  - 셰이더(Shader)
		//		: 그래픽 하드웨어의 렌더링 효과를 계산하는 데 사용되는 소프트웨어 명령의 집합.
		//		  * 꼭짓점 셰이더(Vertex shader) ▶ ID3D11VertexShader* 형식
		//			: 꼭짓점(=정점) 데이터에 수학적인 연산을 수행하여 특별한 효과를 주는 데 쓰인다.
		//		  * 픽셀 셰이더(Pixel shader) ▶ ID3D11PixelShader* 형식
		//			: 픽셀 셰이더 단계는 상수 변수, 텍스처 데이터, 또는 픽셀 출력을 위한 데이터 등을 결합하여 각 픽셀의 데이터(기본적으로 색상)을 생성.
		// 
		//	  - 리소스(Resource)
		//		: 리소스는 장면을 렌더링하는 데 사용되는 텍스처 및 버퍼(즉, 셰이더로 전달되는 데이터)를 의미한다.
		//		  * 버퍼(Buffer) ▶ ID3D11Buffer* 형식
		//			: 기하 도형, 인덱싱 기하 도형 정보 및 셰이더 상수 설명에 사용되는 데이터(이미지가 아닌 데이터).
		//			  (1) 꼭짓점 버퍼(Vertex buffer)	: 기하 도형을 정의하는 데 사용되는 꼭짓점 데이터를 저장.
		//			  (2) 인덱스 버퍼(Index buffer)	: 꼭짓점 버퍼에 대한 정수 오프셋을 저장(원형을 효율적으로 렌더링하는 데 사용).
		//			  (3) 상수 버퍼(Constant buffer)	: 셰이더 상수 데이터를 저장.
		//		  * 텍스처(Texture) ▶ ID3D11Texture1D*(또는 2D, 3D) 형식
		//			: 텍스처 리소스는 텍셀을 저장하도록 구조화된 데이터 모음(즉, 이미지 데이터)이다.
		// 
		//	  - 리소스 뷰(Resource View) ▶ 각각 ID3D11~* 형식
		//		: 리소스를 렌더링 파이프라인에 바인딩해줄 수 있는 객체로,
		//		  리소스를 어떻게 사용할 것(= 바라 볼 것인지, View)인지에 대하여 정의할 수 있다.
		//		  * 렌더 타겟 뷰(Render target view, RTV)		: 후면 버퍼를 출력하기 위해 파이프라인에 바인딩하는 용도(색상 값들을 담는다).
		//		  * 깊이 스텐실 뷰(Depth stencil view, DSV)		: 깊이 및 스텐실 리소스를 읽기 위해 사용(깊이와 스텐실 값을 담는다).
		//		  * 셰이더 리소스 뷰(Shader resource view, SRV)  : 이미지를 읽기 위해 사용.
		//		  * 비정렬 액세스 뷰(Unordered access view, UAV) : (간단한 이미지의) 텍스처를 읽는 동시에 쓰기 위해 사용.
		// 
		//	  - 입력 레이아웃(Input layout) ▶ ID3D11InputLayout* 형식
		//		: 꼭짓점 버퍼에 저장된 서브 리소스(Sub resource)를 읽기 위해 지정한 1 stride 내에서,
		//		  추가적으로 어떤 데이터가 좌표 또는 색상을 나타내는지를 설정해주는 작업.
		//	
		//	  - 뷰 포트(View port) ▶ D3D11_VIEWPORT 형식
		//		: 렌더링할 대상의 화면 영역을 표시하는 폴리곤(polygon).
		// 
		// 
		// 
		//--------------------------------------------------------------------------------------------------------------------------------------
		// 
		// 3) 기타
		//	  - 더블 버퍼링(Double buffering, Swap chain 관련)
		//		: 깜빡이는 현상(명령을 받는 시간이 너무 짧아 화면을 지우는 과정까지 내보내어 발생)을 해결하기 위해,
		//		  front/back buffer를 사용하여 1) 그리는 작업과, 2) 완성된 그림을 내보내는 역할을 분리하는 것.
		// 
		//	  - DirectX 그래픽 인프라(DirectX Graphics Infrastructure, DXGI)
		//		: 특정 그래픽 API와 그래픽 커널 간의 매핑(호환성)을 제공하는 Microsoft Windows의 사용자 모드 구성 요소.
		//		  DXGI는 그래픽 어댑터 및 모니터 열거, 디스플레이 모드 열거, 버퍼 형식 선택, 프로세스 간 리소스 공유,
		//		  렌더링된 프레임을 표시하기 위해 창 또는 모니터에 표시하는 등의 작업을 처리할 개체를 제공.
		// 
		//======================================================================================================================================


		ID3D11Device*				Device;
		ID3D11DeviceContext*		DeviceContext;
		IDXGISwapChain*				SwapChain;

		namespace Buffer
		{
			ID3D11Buffer*			Vertex;
			ID3D11Buffer*			Constant[3];

			template<typename Data>
			void Update(ID3D11Buffer* buffer, Data const& data)
			{
				D3D11_MAPPED_SUBRESOURCE SubResource = D3D11_MAPPED_SUBRESOURCE();
				// 꼭짓점 버퍼에 저장된 값을 변경하기 위해 CPU의 접근제한을 풀어주기 위한 함수.
				MUST(DeviceContext->Map(buffer,						// ID3D11Resource*			  pResource			  : 꼭짓점 버퍼의 포인터.
										0,							// UINT						  Subresource		  : 서브 리소스
										D3D11_MAP_WRITE_DISCARD,	// D3D11_MAP				  MapType			  : CPU에서 읽고 쓰기 위해 액세스할 리소스 식별 방법.
																	//													* ~_READ			   : 리소스를 읽기 위한 매핑(D3D11_CPU_ACCESS_READ).
																	//													* ~_WRITE			   : 리소스를 쓰기를 위한 매핑(D3D11_CPU_ACCESS_WRITE).
																	//													* ~_READ_WRITE		   : 리소스를 읽고 쓰기 위한 매핑(D3D11_CPU_ACCESS_READ | D3D11_CPU_ACCESS_WRITE).
																	//													* ~_WRITE_DISCARD	   : 리소스를 쓰기 위한 매핑(이전 리소스 제거, D3D11_USAGE_DYNAMIC, D3D11_CPU_ACCESS_WRITE).
																	//													* ~_WRITE_NO_OVERWRITE : 리소스를 쓰기 위한 매핑(덮어쓰기 불가능, D3D11_CPU_ACCESS_WRITE).
										0,							// UINT						  MapFlags			  : (생략).
										&SubResource));				// D3D11_MAPPED_SUBRESOURCE*  pMappedResource = 0 : 서브 리소스를 저장할 변수의 포인터

				memcpy_s(SubResource.pData,				// void* const		  _Destination	   : 덮어씌워질 서브 리소스의 pData.
						 SubResource.RowPitch,			// rsize_t const	  _DestinationSize : 덮어씌워질 서브 리소스의 RowPitch.
						 data,							// void const* const  _Source		   : 덮어씌울 데이터.
						 sizeof(data));					// rsize_t const	  _SourceSize	   : 덮어씌울 데이터의 크기.

				DeviceContext->Unmap(buffer, 0);
			}
		}
		ID3D11InputLayout*			InputLayout;
		ID3D11VertexShader*			VertexShader;
		ID3D11PixelShader*			PixelShader;
		ID3D11RenderTargetView*		RenderTargetView;
	}

	LRESULT CALLBACK Procedure(HWND const hWnd,
							   UINT const uMessage,
							   WPARAM const wParam,
							   LPARAM const lParam)
	{
		switch (uMessage)
		{
		case WM_MOUSEWHEEL: case WM_MOUSEHWHEEL: case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN: case WM_LBUTTONUP: case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDOWN: case WM_RBUTTONUP: case WM_RBUTTONDBLCLK:
		case WM_MBUTTONDOWN: case WM_MBUTTONUP: case WM_MBUTTONDBLCLK:
		case WM_XBUTTONDOWN: case WM_XBUTTONUP: case WM_XBUTTONDBLCLK:
		case WM_SYSKEYDOWN: case WM_SYSKEYUP:	// Ctrl, Alt 버튼과 함께 키보드가 눌리는(떼어지는) 경우에 발생하는 메세지
		case WM_KEYDOWN: case WM_KEYUP:
		{
			Input::Procedure(hWnd, uMessage, wParam, lParam);
			return 0;
		}


		case WM_CREATE:
		{
			// Rendering pipeline 초기 설정.
			// - Device, DeviceContext, SwapChain 생성 코드블럭.
			{
				// Swap chain의 descriptor(device, device context, swap chain 객체가 모두 생성됨).
				DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC();	// 기본값으로 설정하기 위해 디폴트 생성자 호출하여 객체 생성.


				// <DXGI_SWAP_CHAIN_DESC 구조체의 멤버 변수>
				// : DXGI_SWAP_CHAIN_DESC 내의 멤버들이 기본값으로 초기화가 되면, 아래와 같은 설정으로 자동으로 적용된다.
				// 
				// 1) DXGI_MODE_DESC BufferDesc
				//	  - UINT Width, Height		  : 기본값(= 0)일 경우: 현재 창의 전체 '작업영역' 디스플레이 크기로 자동 설정됨.
				//	  - DXGI_RATIONAL RefreshRate : 기본값(= 0, 이때 Numerator = 0, Denominator = 1)일 경우, 자동 프레임(FPS)으로 설정됨.
				//	  - DXGI_MODE_SCALING Scaling :
				//		* ~_UNSPECIFIED : (기본값) 창 크기 변화에 따른 배율 변화 없으며 좌상단 좌표계 기준 출력.
				//		* ~_CENTERED = 창 크기 변화에 따른 배율 변화가 없으며, 화면 상의 중점을 기준으로 확장 및 축소
				//		* ~_STRETCHED = 창 크기 변화에 따른 배율이 변경.
				//	  - DXGI_MODE_SCANLINE_ORDER ScanlineOrdering :
				//		* ~_UNSPECIFIED : (기본값) 디스플레이에 따라 아래 설정 중에서 자동으로 설정.
				// 		* ~_PROGRESSIVE : 순차주사.
				//		* ~_UPPER_FIELD_FIRST: 비월주사(interlaced) -> 홀수 필드(upper field)를 먼저 출력한 뒤 나머지 출력.
				//		* ~_LOWER_FIELD_FIRST: 비월주사(interlaced) -> 짝수 필드(lower field)를 먼저 출력한 뒤 나머지 출력.
				//
				// 2) UINT Flags: 추가적인 기능을 사용할 것인지를 설정(사용하지 않을 때 기본값 = 0으로 사용).
				//
				// 3) DXGI_SWAP_EFFECT SwapEffect: 화면을 넘겨주고 나서 데이터를 가지고 있을 것인지를 설정.
				//	  - DXGI_SWAP_EFFECT_DISCARD = 기본값. 화면을 넘겨주고 나면 데이터를 제거.
				//	  - DXGI_SWAP_EFFECT_SEQUENTIAL = 화면을 넘겨준 뒤에도 데이터를 가지고 있음.
				//
				// 4) DXGI_SAMPLE_DESC SampleDesc: SampleDesc를 얼마나 정교하게 다룰 것인지를 설정(계단 현상과 관련).
				//	  (Super-sampling: 화면을 확장시키고 나서 초기 픽셀 크기대로 확장된 픽셀을 쪼갠 후 화면을 축소(비용이 매우 높음, DX에서는 지원 안하는듯?),
				//	   Multi-sampling: 테두리에 대해서만 픽셀을 쪼개어 계단 현상을 해결 -> 모든 DX11 디바이스에서 지원)
				//	  - Count = 픽셀을 몇 개로 쪼갤 것인지를 설정(1 = 멀티 샘플링을 사용하지 않음).
				//	  - Quality = 멀티 샘플링을 얼마나 사용할지를 설정(0 ~ 1 사이의 값, 높을수록 더 많이 사용).


				// BufferDesc.Format: 픽셀에 할당된 값을 어떤 형식으로 읽을 것인지에 대한 포맷을 설정할 수 있는(즉, 색상표를 어떻게 설정할 것인지) 멤버 변수.
				Descriptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;		// RGBA(R, G, B, Alpha = 투명도) 값을 0 ~ 255의 256 단계(unsigned char = 8 bit)로 설정.
																				// UNORM: Unsigned, normalized(최대값이 1로 표준화된 값) 를 의미.

				Descriptor.BufferCount		= 1;								// 버퍼를 '추가'할 갯수를 설정(기본값 = 0 -> 1 개의 버퍼를 사용).
				Descriptor.BufferUsage		= DXGI_USAGE_RENDER_TARGET_OUTPUT;	// 버퍼를 어디에 사용할 것인지를 설정(렌더 타겟 출력하는 용도로 설정).
				Descriptor.OutputWindow		= hWnd;								// 출력할 윈도우의 핸들.
				Descriptor.Windowed			= true;								// 창 모드를 사용할 것인지 여부.
				Descriptor.SampleDesc.Count = 1;								// 생성자를 통해 객체 생성시, 기본값이 0으로 초기화 되므로 1로 변경한 것.

				// <DirectX의 기능 수준(feature level) 설정 관련>
				// : 일반적으로 버전이 높은 순으로 기능 수준 배열의 요소를 초기화한다.
				//	 기능 수준 배열(featureLevels)을 아래 구문과 같이 직접 설정해도 되지만,
				//	 D3D11CreateDeviceAndSwapChain 함수의 인자 pFeatureLevels = nullptr로 전달하는 경우,
				//	 기본적으로 사용되는 기능 수준 배열은 아래의 배열과 동일하다.
				D3D_FEATURE_LEVEL featurelevels[] = { D3D_FEATURE_LEVEL_11_0,
													  D3D_FEATURE_LEVEL_10_1,
													  D3D_FEATURE_LEVEL_10_0,
													  D3D_FEATURE_LEVEL_9_3,
													  D3D_FEATURE_LEVEL_9_2,
													  D3D_FEATURE_LEVEL_9_1 };

				// HRESULT: S_OK, S_FALSE의 값으로 반환하는 자료형(long의 typedef 형태).
				// assert(expression): (cassert 헤더 내의 매크로 함수)
				//					   - Debug 모드: expression이 참이면 넘어가고 거짓이면 터짐.
				//					   - Release 모드: 아무 동작도 수행하지 않음((void)0 으로 치환됨).
				//					     * 즉, Debug 모드(디버깅 모드)와 Release 모드(실제 빌드)일 때 작동 방식이 다르므로
				//						   전처리기 사용을 통한 구분된 함수 사용이 필요하다(전처리기 MUST 매크로 함수 참고).
				// 
				// SUCCEEDED(): (cassert 헤더 내의 매크로 함수)
				//				HRESULT의 형식이 long이므로, 이를 bool 형식으로 바꿔주기 위한 함수(S_OK일 때 true 반환, S_FALSE일 때 false 반환).
				MUST(D3D11CreateDeviceAndSwapChain(nullptr,						// IDXGIAdapter*				pAdapter		   : 그래픽 카드를 연결할 때 사용(내장 그래픽 카드 사용시 nullptr).
												   D3D_DRIVER_TYPE_HARDWARE,	// D3D_DRIVER_TYPE				DriverType		   : 드라이버 타입.
												   								//												     * ~_HARDWARE  : 하드웨어에서 뽑아냄(빠른 속도, 정확성 낮음).
												   								//												     * ~_REFERENCE : 하드웨어에서 레퍼런스를 거친다(느린 속도, 정확성 높음).
												   								//												     * ~_NULL	   : 드라이버 타입이 없음(디버깅 목적).
												   								//												     * ~_SOFTWARE  : DirectX가 아닌 다른 소프트웨어로부터 불러옴(매우 느린 속도).
												   								//												     * ~_WARP	   : Rasterizing 에서 최고성능으로 뽑을 때 사용(수업에서는 논외).
												   nullptr,						// HMODULE						Software		   : 설정을 가져올 software의 hInstance(사용하지 않으면 nullptr).
												   0,							// UINT							Flags			   : 추가적인 정보(없으므로 0 사용).
												   featurelevels,				// const D3D_FEATURE_LEVEL*		pFeatureLevels	   : DirectX 버전의 호환성(기능 수준)을 설정(기능 수준 배열(featurelevels) 참고).
												   6,							// UINT							FeatureLevels	   : pFeatureLevels의 요소의 갯수(nullptr일 때는 0 전달).
												   D3D11_SDK_VERSION,			// UINT							SDKVersion		   : (항상) D3D11_SDK_VERSION 으로 설정.
												   &Descriptor,					// const DXGI_SWAP_CHAIN_DESC*	pSwapChainDesc	   : Swap chain의 descriptor의 포인터.
												   &SwapChain,					// IDXGISwapChain**				ppSwapChain		   : (이중 포인터) Swap chain의 포인터.
												   &Device,						// ID3D11Device**				ppDevice		   : (이중 포인터) Device의 포인터.
												   nullptr,						// D3D_FEATURE_LEVEL*			pFeatureLevel	   : 지원하는 기능 수준 배열의 첫 번째 요소를 나타내는 D3D_FEATURE_LEVEL의
												   								//													 포인터를 반환할 변수(기능 수준을 결정할 필요 없으면 nullptr).
												   &DeviceContext));			// ID3D11DeviceContext**		ppImmediateContext : (이중 포인터) Device context의 포인터.
												   
												   // <Device, DeviceContext, SwapChain과 관련된 인자를 이중 포인터 형식으로 전달하는 이유?>
												   // : D3D11CreateDeviceAndSwapChain 함수 내에서 매개변수로 전달되어 받은 값을 다른 값으로 변경해야하는데
												   //   이때, 해당 함수가 종료되면 매개변수는 메모리 공간이 해제되므로 값이 변경되지 않는다.
												   //   따라서 기존의 포인터 변수에 저장된 값을 함수 내에서 변경할 수 있도록 하기 위해 인자로 이중 포인터 형식으로 전달한다.
			}

			// Vertex buffer(꼭짓점 좌표) 생성 코드블럭.
			{
				// 정점별 좌표만을 저장할 변수 선언(이미지 파일 로드 -> 색상은 텍스처로).
				float const Coordinates[4][2]
				{
					{ -0.5f,  0.5f },
					{  0.5f,  0.5f },
					{ -0.5f, -0.5f },
					{  0.5f, -0.5f },
				};

				// Vertex buffer의 descriptor(슬롯 0에 정점 데이터만을 입력).
				D3D11_BUFFER_DESC Descriptor
				{
					sizeof(Coordinates),			// UINT			ByteWidth			: 정점에 대한 데이터를 담을 크기.
					D3D11_USAGE_IMMUTABLE,			// D3D11_USAGE	Usage				: 렌더링 중 예상되는 리소스의 사용 목적을 식별.
					 								//									  * ~_DEFAULT   : GPU의 읽기 및 쓰기 액세스가 필요한 리소스.
					 								//									  * ~_IMMUTABLE : GPU에서만 읽을 수 있는 리소스입니다.
					 								//									  * ~_DYNAMIC   : GPU와 CPU 동시에 읽고 쓰기 가능.
					 								//									  * ~_STAGING   : GPU에서 CPU로의 값 복사 형식으로 전달.
					D3D11_BIND_VERTEX_BUFFER		// UINT			BindFlags			: 리소스를 파이프라인에 바인딩하는 방법을 식별.
													// UINT			CPUAccessFlags		: 리소스에 허용되는 CPU 액세스 유형을 지정.
													//									  * ~_WRITE : CPU에서 읽고 쓰기 가능한 리소스.
													//									  * ~_READ  : CPU에서 읽기 가능한 리소스.
					 								// UINT			MiscFlags			: (현재는 사용 안 함).
					 								// UINT			StructureByteStride	: (현재는 사용 안 함) 구조화된 형식일 경우 몇 바이트씩 끊어 읽을지 설정.
				};

				D3D11_SUBRESOURCE_DATA SubResource
				{
					Coordinates						// const void*  pSysMem			 : 해당 포인터에 저장되어있는 주소를 참조하여 메모리를 읽음.
													// UINT			SysMemPitch		 : .
													// UINT			SysMemSlicePitch : .
				};

				ID3D11Buffer* Buffer = nullptr;		// 이미지를 띄울 직사각형의 좌표를 저장하는 데 사용할 vertex buffer.
				MUST(Device->CreateBuffer(&Descriptor,		// const D3D11_BUFFER_DESC*		  pDesc		   : 버퍼의 descriptor의 포인터.
										  &SubResource,		// const D3D11_SUBRESOURCE_DATA*  pInitialData : 값을 초기화하기 위해 필요한 서브 리소스(위 참고).
										  &Buffer));		// ID3D11Buffer**				  ppBuffer	   : (이중 포인터) Vertex buffer의 포인터.

				const UINT Stride = sizeof(*Coordinates);
				const UINT Offset = 0;
				DeviceContext->IASetVertexBuffers(0,				// UINT					 StartSlot		 : 바인딩을 위한 첫 번째 입력 슬롯(0에서 시작).
												  1,				// UINT					 NumBuffers		 : 배열 내의 정점 버퍼의 수.
												  &Buffer,			// ID3D11Buffer* const*	 ppVertexBuffers : Vertex buffer의 배열에 대한 포인터.
												  &Stride,			// const UINT*			 pStrides		 : 보폭 값의 배열에 대한 포인터(정점 하나의 데이터를 읽을 때 몇 바이트씩 끊어읽을지).
												  &Offset);			// const UINT*			 pOffsets		 : 오프셋 값의 배열에 대한 포인터(시작점이랑 첫 요소랑 다를 때만 사용).
				Buffer->Release();
			}

			// Vertex buffer(텍스처 리소스) 생성 코드블럭.
			{
				//// 고정 이미지 - 서브 리소스 필요.
				//float const Texcoord[4][2]
				//{
				//	{ 0.0f, 0.0f },
				//	{ 500.0f, 0.0f },
				//	{ 0.0f, 500.0f },
				//	{ 500.0f, 500.0f }
				//};
				//D3D11_BUFFER_DESC Descriptor{ sizeof(Texcoord), D3D11_USAGE_IMMUTABLE, D3D11_BIND_VERTEX_BUFFER };
				//D3D11_SUBRESOURCE_DATA SubResource{ Texcoord };
				//MUST(Device->CreateBuffer(&Descriptor, &SubResource, &Buffer::Vertex));
				
				// 동적 이미지 - 서브 리소스가 필요 없음.
				D3D11_BUFFER_DESC Descriptor{ sizeof(float[4][2]), D3D11_USAGE_DYNAMIC, D3D11_BIND_VERTEX_BUFFER, D3D11_CPU_ACCESS_WRITE };
				MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Vertex));

				const UINT Stride = sizeof(float[2]);
				const UINT Offset = 0;
				DeviceContext->IASetVertexBuffers(1, 1, &Buffer::Vertex, &Stride, &Offset);
			}

			// 기본 토폴로지 설정 코드블럭.
			{
				// 기본 토폴로지(Primitive topology)
				// : 정점을 어떤 도형으로 해석할 것인지에 대한 설정.
				//	 * ~_TRIANGLELIST  : 각각의 정점을 별개의 삼각형으로 인식
				//	 * ~_TRIANGLESTRIP : 각각의 정점을 모두 연결된 삼각형으로 인식.
				DeviceContext->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
			}

			// Vertex shader 생성 코드블럭.
			{
#include "Shader/Bytecode/VertexShader.h"
				// 레이아웃 설정.
				{
					// InputLayout의 descriptor 배열(꼭짓점 데이터가 좌표와 색상 두 가지 데이터로 구성되므로, 2개 요소를 갖는 배열로 선언)
					D3D11_INPUT_ELEMENT_DESC Descriptor[2]
					{
						{
							"POSITION",					// LPCSTR					   SemanticName			: 해당 데이터(좌표 또는 색상)의 HLSL에서의 시맨틱 네임.
							0,							// UINT						   SemanticIndex		: 해당 데이터의 시맨틱 인덱스(설정 안했으므로 0).
							DXGI_FORMAT_R32G32_FLOAT,	// DXGI_FORMAT				   Format				: 좌표(또는 색상)을 어떤 형식으로 읽을 것인지 설정.
							0							// UINT						   InputSlot			: 
														// UINT						   AlignedByteOffset	: 데이터를 읽는 시작지점의 초기 주소로부터의 바이트 주소 차이(오프셋).
														// D3D11_INPUT_CLASSIFICATION  InputSlotClass		: 
														// UINT						   InstanceDataStepRate : (생략).
						},

						// 위와 동일한 구조체형의 요소
						{
							"TEXCOORD",
							0,
							DXGI_FORMAT_R32G32_FLOAT,
							1
						}
					};

					MUST(Device->CreateInputLayout(Descriptor,			// const D3D11_INPUT_ELEMENT_DESC*  pInputElementDescs				  : Input layout의 descriptor의 포인터(현재 배열이므로 이름 전달).
												   2,					// UINT								NumElements						  : Input layout의 descriptor 배열의 요소의 갯수.
												   Bytecode,			// const void*						pShaderBytecodeWithInputSignature : 셰이더 이진코드의 포인터.
												   sizeof(Bytecode),	// SIZE_T							BytecodeLength					  : 이진코드의 길이
												   &InputLayout));		// ID3D11InputLayout**				ppInputLayout					  : Input layout의 포인터.

					// 레이아웃 설정 함수 자체는 IA 단계에 속하지만, 이진코드 관련 변수가 필요하므로 VS 단계에서 설정.
					DeviceContext->IASetInputLayout(InputLayout);		// 상기 구문에서 인스턴스화 한 input layout.
				}

				// Vertex shader 생성.
				{
					MUST(Device->CreateVertexShader(Bytecode,			// const void*			 pShaderBytecode : 셰이더 이진코드의 포인터.
													sizeof(Bytecode),	// SIZE_T				 BytecodeLength  : 이진코드의 길이.
													nullptr,			// ID3D11ClassLinkage*	 pClassLinkage   : (생략).
													&VertexShader));	// ID3D11VertexShader**  ppVertexShader  : Vertex shader의 포인터.
					DeviceContext->VSSetShader(VertexShader, nullptr, 0);
				}
			}

			// Constant buffer 생성 코드블럭(D3D11_USAGE_DYNAMIC).
			{
				D3D11_BUFFER_DESC Descriptor{ sizeof(float[4][4]), D3D11_USAGE_DYNAMIC, D3D11_BIND_CONSTANT_BUFFER, D3D11_CPU_ACCESS_WRITE };
				for (UINT8 i = 0; i < 3; ++i)
				{
					MUST(Device->CreateBuffer(&Descriptor, nullptr, &Buffer::Constant[i]));
					DeviceContext->VSSetConstantBuffers(i, 1, &Buffer::Constant[i]);
				}
			}

			// Pixel shader 생성 코드블럭.
			{
#include "Shader/Bytecode/PixelShader.h"
				MUST(Device->CreatePixelShader(Bytecode,			// const void*			pShaderBytecode : 셰이더 이진코드의 포인터.
											   sizeof(Bytecode),	// SIZE_T				BytecodeLength  : 이진코드의 길이.
											   nullptr,				// ID3D11ClassLinkage*  pClassLinkage   : (생략).
											   &PixelShader));		// ID3D11PixelShader**  ppPixelShader   : Pixel shader의 포인터.

				DeviceContext->PSSetShader(PixelShader,		// ID3D11PixelShader*			pPixelShader	  : 상기 구문에서 인스턴스화 한 pixel shader.
										   nullptr,			// ID3D11ClassInstance* const*  ppClassInstances  : (생략).
										   0);				// UINT							NumClassInstances : (생략).
			}

			// 이미지 띄우기 코드블럭.
			{
				FreeImage_Initialise();
				{
					// (참고) PNG, WAV 파일의 경우 원본 데이터를 압축하지 않는 형식으로, 게임 개발에서 가장 많이 이용한다.

					FIBITMAP* Bitmap = FreeImage_Load(FREE_IMAGE_FORMAT::FIF_PNG,	// FREE_IMAGE_FORMAT  fif	   : 이미지 파일의 형식(확장자에 따라 설정).
													  "Image/Player.png");			// const char*		  filename : 이미지 파일 (상대)경로.

					// 로드한 이미지를 텍스처로 만드는 코드블럭.
					{
						// 이미지를 처음 로드하면 수평으로 뒤집어져있으므로, 다시 뒤집어줌.
						FreeImage_FlipVertical(Bitmap);

						D3D11_TEXTURE2D_DESC Descriptor = D3D11_TEXTURE2D_DESC();
						Descriptor.Width			= FreeImage_GetWidth(Bitmap);
						Descriptor.Height			= FreeImage_GetHeight(Bitmap);
						Descriptor.MipLevels		= 1;								// (참고) 밉맵(MipMap) -> 미리 축소시켜서 보여주는 기능 관련(사용하지 않으므로 1).
						Descriptor.ArraySize		= 1;								// (참고) 스카이 박스(Sky box)
						Descriptor.Format			= DXGI_FORMAT_B8G8R8A8_UNORM;
						Descriptor.SampleDesc.Count = 1;
						Descriptor.Usage			= D3D11_USAGE_IMMUTABLE;
						Descriptor.BindFlags		= D3D11_BIND_SHADER_RESOURCE;

						D3D11_SUBRESOURCE_DATA SubResource
						{
							FreeImage_GetBits(Bitmap),		// const void *pSysMem	 : .
							FreeImage_GetPitch(Bitmap)		// UINT SysMemPitch		 : BITMAP의 보폭이 몇인지를 설정(stride와 비슷한 개념).
															// UINT SysMemSlicePitch : .
						};

						ID3D11Texture2D* Texture2D = nullptr;
						MUST(Device->CreateTexture2D(&Descriptor,	// const D3D11_TEXTURE2D_DESC*	  pDesc		   : Texture2D의 descriptor의 포인터.
													 &SubResource,	// const D3D11_SUBRESOURCE_DATA*  pInitialData : Texture2D의 서브 리소스 데이터(이미지 데이터)의 포인터.
													 &Texture2D));	// ID3D11Texture2D**			  ppTexture2D  : (이중 포인터) Texture2D의 포인터.
						{
							ID3D11ShaderResourceView* ShaderResourceView = nullptr;
							MUST(Device->CreateShaderResourceView(Texture2D,				// ID3D11Resource*						   pResource			: .
																  nullptr,					// const D3D11_SHADER_RESOURCE_VIEW_DESC*  pDesc				: .
																  &ShaderResourceView));	// ID3D11ShaderResourceView**			   ppShaderResourceView : (이중 포인터) ShaderResourceView의 포인터. 
							{
								DeviceContext->PSSetShaderResources(0,						// UINT								StartSlot			 : .
																	1,						// UINT								NumViews			 : .
																	&ShaderResourceView);	// ID3D11ShaderResourceView* const  ppShaderResourceView : .
							}
							ShaderResourceView->Release();
						}
						Texture2D->Release();
					}
					FreeImage_Unload(Bitmap);
				}
				FreeImage_DeInitialise();
			}

			return 0;
		}


		case WM_APP:
		{
			MUST(SwapChain->Present(0,		// UINT	 SyncInterval : 수직 공백과 프레임 표시를 동기화하는 방법을 지정(버퍼로 보내는 간격, 즉 커질 수록 대기시간이 길어지는 효과).
									0));	// UINT	 Flags		  : 추가적인 정보(없으므로 0).

			// 컬러 배열(RGBA 순) 생성 코드블럭.
			float Color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
				
			// 렌더 타겟의 모든 요소를 하나의 값으로 설정하는 함수.
			DeviceContext->ClearRenderTargetView(RenderTargetView,		// ID3D11RenderTargetView*	pRenderTargetView : Render target view.
												 Color);				// const float*				ColorRGBA		  : 색상을 나타내는 배열(RGBA).

			// 스프라이트 이미지 내에서의 TEXCOORD 설정 코드블럭.
			{
				// 구조체 자료형을 만드는 것이 아닌, 단일로 존재하게 되는 구조체형 변수를 선언.
				static struct
				{
					float const Width  = 84;
					float const Height = 120;
				}Frame;

				static unsigned Count		   = 0;		// 현재 프레임 카운트
				static unsigned CountPerMotion = 500;	// Frame per motion
				static unsigned Motion		   = 12;	// 애니메이션이 12 개로 구성되어있기 때문.

				float const Coordinates[4][2] =
				{
					{ Frame.Width * (Count / CountPerMotion + 0), Frame.Height * 0 },	// 좌상단
					{ Frame.Width * (Count / CountPerMotion + 1), Frame.Height * 0 },	// 우상단
					{ Frame.Width * (Count / CountPerMotion + 0), Frame.Height * 1 },	// 좌하단
					{ Frame.Width * (Count / CountPerMotion + 1), Frame.Height * 1 }	// 우하단
				};

				Count += 1;
				if (Count > CountPerMotion * Motion - 1) Count = 0;

				Buffer::Update(Buffer::Vertex, Coordinates);
			}

			// Constant buffer(월드 좌표 변환) 변경 코드블럭.
			{
				static float sx = 84;
				static float sy = 120;
				
				static float dx = 0.0f;
				static float dy = 0.0f;

				if (Input::Get::Down(VK_UP)) dy += 0.03f;
				if (Input::Get::Down(VK_DOWN)) dy -= 0.03f;
				if (Input::Get::Down(VK_LEFT)) dx -= 0.03f;
				if (Input::Get::Down(VK_RIGHT)) dx += 0.03f;

				// (Linear) Transform: Scale(신축), rotation(자전), translation(평행이동).
				// (★중요) 열우선순위로 데이터 입력하기 위해 원래 변환행렬의 전치행렬로 선언.
				float const Transform[4][4] =
				{
					sx,		0,		0,		dx,
					0,		sy,		0,		dy,
					0,		0,		1,		0,
					0,		0,		0,		1
				};

				Buffer::Update(Buffer::Constant[0], Transform);
			}

			// Constant buffer(카메라 좌표 변환) 변경 코드블럭.
			{
				static float dx = 0.0f;
				static float dy = 0.0f;

				//dx -= 0.005f;

				// 카메라 좌표를 캐릭터의 이동 방향과 반대로 이동시키면 캐릭터가 움직이는 것 같은 효과.
				float const Transform[4][4] =
				{
					1,	0,	0,	dx,
					0,	1,	0,	dy,
					0,	0,	1,	0,
					0,	0,	0,	1
				};

				Buffer::Update(Buffer::Constant[1], Transform);
			}

			// Constant buffer(프로젝션) 변경 코드블럭.
			{
				static float X = 2.0f / 500.0f;
				static float Y = 2.0f / 500.0f;

				float const Transform[4][4] =
				{
					X,	0,	0,	0,
					0,	Y,	0,	0,
					0,	0,	1,	0,
					0,	0,	0,	1
				};

				Buffer::Update(Buffer::Constant[2], Transform);
			}
			
			DeviceContext->Draw(4,		// UINT  VertexCount	: 그릴 정점의 갯수.
								0);		// UINT  VertexLocation : 정점의 위치.

			// 임시 코드블럭.
			{
				static float sx = 84 / 3;
				static float sy = 120 / 3;

				static float dx = 100;
				static float dy = 100;

				// (Linear) Transform: Scale(신축), rotation(자전), translation(평행이동).
				float const Transform[4][4] =
				{
					sx,		0,		0,		dx,
					0,		sy,		0,		dy,
					0,		0,		1,		0,
					0,		0,		0,		1
				};
				Buffer::Update(Buffer::Constant[0], Transform);
			}
			DeviceContext->Draw(4, 0);

			return 0;
		}


		case WM_SIZE:
		{
			// 뷰 포트 생성 코드블럭.
			{
				// 뷰 포트의 크기를 버퍼와 동일하게 설정
				D3D11_VIEWPORT Viewport
				{
					0.0f,									// FLOAT TopLeftX;
					0.0f,									// FLOAT TopLeftY;
					static_cast<FLOAT>LOWORD(lParam),		// FLOAT Width;
					static_cast<FLOAT>HIWORD(lParam)		// FLOAT Height;
															// FLOAT MinDepth;
															// FLOAT MaxDepth;
				};
				
				DeviceContext->RSSetViewports(1,			// UINT					  NumViewports : View port의 갯수.
											  &Viewport);	// const D3D11_VIEWPORT*  pViewports   : View port의 포인터.
			}

			// Buffer Resizing.
			{
				MUST(SwapChain->ResizeBuffers(1,							// UINT			BufferCount	   : Descriptor.BufferCount 에서 설정한 값(buffer가 1개면 0, 2개면 1, ... / index로 생각하면 편함).
											  LOWORD(lParam),				// UINT			Width		   : 마우스의 현재 x 좌표.
											  HIWORD(lParam),				// UINT			Height		   : 마우스의 현재 y 좌표.
											  								//								 * 창이 변경될 때 마우스가 항상 right, bottom에 위치하게 되므로
																			//								   마우스의 변경된 좌표는 창의 변경되는 width, height와 항상 같다.
											  DXGI_FORMAT_B8G8R8A8_UNORM,	// DXGI_FORMAT	NewFormat	   : 데이터를 읽는 format(DXGI_SWAP_CHAIN_DESC 참고).
											  0));							// UINT			SwapChainFlags : 추가적인 정보(없으므로 0 사용).
			}


			// 렌더 타겟 뷰 생성 코드블럭.
			{
				ID3D11Texture2D* texture = nullptr;
				MUST(SwapChain->GetBuffer(0,							// UINT		  Buffer	  : DISCARD 옵션을 사용하는 경우 0을 전달.
										  IID_PPV_ARGS(&texture)));		// const IID  &riid		  : Texture2D 구조체의 ID를 전달.
																		// void		  **ppSurface : (생략).
				{
					Device->CreateRenderTargetView(texture,				// ID3D11Resource*						pResource : Render target을 나타내는 ID3D11Resource의 포인터.
												   nullptr,				// const D3D11_RENDER_TARGET_VIEW_DESC	pDesc	  : Render target view를 나타내는 D3D11_RENDER_TARGET_VIEW_DESC의 포인터.
												   &RenderTargetView);	// ID3D11RenderTargetView**				ppRTView  : (이중 포인터) Render target view의 포인터.
				}
				texture->Release();

				DeviceContext->OMSetRenderTargets(1,					// UINT							   NumViews			   : 바인드할 render target의 수(ppRenderTargetViews 배열의 요소의 갯수와 동일).
												  &RenderTargetView,	// ID3D11RenderTargetView* const*  ppRenderTargetViews : (이중 포인터) Render target view의 포인터(없을 경우 nullptr).
												  nullptr);				// ID3D11DepthStencilView*		   pDepthStencilView   : Depth stencil view(없을 경우 nullptr).
			}

			return 0;
		}


		case WM_DESTROY:
		{
			// 일반적으로 COM interface의 객체는 생성 순서의 역순으로 해제한다(파생 클래스의 소멸자 호출과 비슷한 원리).
			RenderTargetView->Release();
			PixelShader->Release();
			VertexShader->Release();
			InputLayout->Release();
			Buffer::Vertex->Release();

			Device->Release();
			DeviceContext->Release();
			SwapChain->Release();

			PostQuitMessage(0);
			return 0;
		}


		default:
		{ return DefWindowProc(hWnd, uMessage, wParam, lParam); }
		}
	}
}