#include <d3d11.h>		// d3d11 헤더 내에 Windows 헤더가 포함되어있음(중복 include X).

namespace Pipeline
{
	namespace
	{
		// COM interface: 사용자가 임의로 만들 수 있는 자료형이 아님(인터페이스 = 구현에 대해 아무 것도 지시하지 않고 개체가 지원할 수 있는 메서드 집합).
		//				  * 해당 자료형으로 동적할당 받을 수 없음(abstract이므로 인스턴스화할 수 없다).
		//				  * Create()로 만들고 Release()로 해제한다.
		//				  * 설명자(Descriptor, 서술자): 자원을 GPU별로 특정되는 형식에 맞게 서술해주는 경량의 자료구조.

		ID3D11Device* Device;					// 렌더링 파이프라인을 구성하기 위한 재료.
		ID3D11DeviceContext* DeviceContext;		// 렌더링 파이프라인을 위한 재료들을 결합시키기 위해 사용.
		IDXGISwapChain* SwapChain;				// DXGI(DirectX Graphics Infrastructure): 커널 간의 호환성을 대신 수행하는 역할(그래픽 카드에 따라 코드 인식방법이 다르므로).
												// SwapChain: 사용자에게 프레임을 표시하는 데 사용되는 버퍼의 컬렉션.
	}


	// CALLBACK == __stdcall(매크로 상수).
	// Procedure(): 윈도우 프로시저 함수(보통은 WndProc라고 이름 지음).
	LRESULT CALLBACK Procedure(HWND const hWnd,			// 메세지를 처리할 윈도우 핸들.
		UINT const uMessage,							// 전달된 메세지.
		WPARAM const wParam,							// 메세지에 대한 추가 정보(wParam).
		LPARAM const lParam)							// 메세지에 대한 추가 정보(lParam).
	{
		switch (uMessage)
		{
		// 처음 창이 생성될 때 한 번만 호출되는 메세지.
		case WM_CREATE:
		{
			// 아래의 명령어 하나로, Device, Device context, Swap chain을 한번에 모두 생성 가능함.
			DXGI_SWAP_CHAIN_DESC Descriptor = DXGI_SWAP_CHAIN_DESC();	// 기본값으로 설정하기 위해 디폴트 생성자 호출하여 객체 생성.
			//D3D11CreateDeviceAndSwapChain();

			return 0;
		}

		// 창의 사이즈가 변경될 때 호출되는 메세지.
		case WM_SIZE:
			return 0;

		// 사용자 정의 메세지.
		case WM_APP:
			return 0;

		// 우측 상단의 종료 버튼을 누르거나 Alt + F4 입력 시 윈도우에서 발생하는 메세지.
		case WM_DESTROY:
		{
			Device->Release();			// Release를 통해 해제.
			DeviceContext->Release();	// Release를 통해 해제.
			SwapChain->Release();		// Release를 통해 해제.
			PostQuitMessage(0);			// PostQuitMessage(): 메시지 큐에 WM_QUIT 메세지를 포스트하는 함수.
			return 0;
		}

		// 상기 분류되지 않은 메세지들을 디폴트로 처리.
		default:
		{ return DefWindowProc(hWnd, uMessage, wParam, lParam); }	// DefWindowProc(): 메세지를 디폴트로 처리하는 함수.
		}

	}
}