// <프로젝트 속성 변경 내용>
// 1) 구성 속성 - 일반
//	  - 출력 디렉터리: $(SolutionDir).out\
//	  - 중간 디렉터리: $(SolutionDir).int\
//	  - C++ 언어 표준: ISO C++17 표준(/std:c++17)
// 
// 2) 구성 속성 - 고급
//	  - 문자 집합: 멀티바이트 문자 집합 사용
//
// 3) 구성 속성 - C/C++
//	  - 경고를 오류로 처리: 예(/WX)
//	  - 다중 프로세서 컴파일: 예(/MP)
//
// 4) 구성 속성 - 링커 - 모든 옵션
//	  - 링커 경고를 오류로 처리: 예(/WX)
//	  - 하위 시스템: 창(/SUBSYSTEM:WINDOWS)


#include <Windows.h>

// 윈도우 프로시저 함수를 Pipeline.cpp에 옮기면서 글로벌 네임스페이스가 아닌
// Pipeline이라는 namespace 안으로 옮겼기 때문에 여기서도 마찬가지로 동일한 이름의 namespace 내에 선언해주어야한다.
namespace Pipeline
{
	// CALLBACK == __stdcall(매크로 상수).
	LRESULT CALLBACK Procedure(HWND const, UINT const, WPARAM const, LPARAM const);
}

int APIENTRY WinMain(_In_ HINSTANCE const hInstance,
					 _In_opt_ HINSTANCE const hInstancePrev,
					 _In_ LPSTR const lpCmdLine,
					 _In_ int const nCmdShow)
{
	HWND hWnd = nullptr;

	// 윈도우 클래스 생성 코드블럭.
	// : 윈도우 클래스의 경우, 클래스를 함수를 통해 등록하기만 하면
	//   이후에는 더이상 사용할 일이 없으므로 지역을 설정하여 지역 내에서 사용한 뒤
	//   클래스 등록을 하고 지역을 빠져나와 제거될 수 있도록 아래와 같이 사용할 수 있다.
	{
		WNDCLASSEX wndClass = WNDCLASSEX();

		wndClass.cbSize			= sizeof(WNDCLASSEX);
		wndClass.style			= CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc	= Pipeline::Procedure;
		wndClass.hInstance		= hInstance;
		wndClass.hIcon			= LoadIcon(nullptr, IDI_APPLICATION);
		wndClass.hIconSm		= LoadIcon(nullptr, IDI_APPLICATION);
		wndClass.hCursor		= LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground	= static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));		// GetStockObject(): 객체를 가져오는 함수
		wndClass.lpszClassName	= "Window";

		RegisterClassEx(&wndClass);
	}
	
	// 윈도우 생성 코드블럭.
	{
		// 윈도우 구조체
		CREATESTRUCT window = CREATESTRUCT();

		window.lpszClass		= "Window";
		window.lpszName			= "Game";
		window.style			= WS_CAPTION | WS_SYSMENU;		// WS_SYSMENU = 윈도우 우측 상단 - ㅁ x 버튼을 활성화.
		window.hInstance		= hInstance;
		window.cx				= 500;
		window.cy				= 500;

		{
			RECT rect	= RECT();
			rect.right	= window.cx;
			rect.bottom	= window.cy;
			AdjustWindowRectEx(&rect, window.style, static_cast<bool>(window.hMenu), window.dwExStyle);
			
			window.cx	= rect.right - rect.left;
			window.cy	= rect.bottom - rect.top;
			window.x	= (GetSystemMetrics(SM_CXSCREEN) - window.cx) / 2;
			window.y	= (GetSystemMetrics(SM_CYSCREEN) - window.cy) / 2;
		}

		hWnd = CreateWindowEx(window.dwExStyle,
							  window.lpszClass,
							  window.lpszName,
							  window.style,
							  window.x,
							  window.y,
							  window.cx,
							  window.cy,
							  window.hwndParent,
							  window.hMenu,
							  window.hInstance,
							  window.lpCreateParams);

		// SW_RESTORE: 활성화 된 상태로 창을 표시하고, 창을 최소화한 뒤 다시 띄워도 크기를 유지시키기 위해 사용하는 매크로 상수.
		ShowWindow(hWnd, SW_RESTORE);
	}

	MSG msg;

	// 메세지 처리 루프 코드블럭.
	while (true)
	{
		if (PeekMessage(&msg, HWND(), WM_NULL, WM_NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) return static_cast<int>(msg.wParam);
			DispatchMessage(&msg);
		}
		else
		{
			SendMessage(hWnd, WM_APP, 0, 0);
		}
	}

	return 0;
}