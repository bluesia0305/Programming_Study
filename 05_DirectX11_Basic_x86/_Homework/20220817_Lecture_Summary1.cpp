// Windows.h: WinAPI를 사용하기 위한 기능들을 모아놓은 헤더.
#include <Windows.h>

// APIENTRY == __stdcall(매크로 상수).
// WinMain: WinAPI에서의 main 함수와 같은 역할.
int APIENTRY WinMain(_In_ HINSTANCE const hInstance,	// 현재 인스턴스 핸들.
	_In_opt_ HINSTANCE const hInstancePrev,				// 이전 인스턴스 핸들.
	_In_ LPSTR const lpCmdLine,							// ★모름★
	_In_ int const nCmdShow)							// ★모름★
{
	HWND hWnd = nullptr;	// 윈도우 핸들.

	// ★모름★: 윈도우 클래스와 윈도우 핸들의 명칭 차이만 알고 정확히 각각 무엇을 의미하는지를 모름.

	// 윈도우 클래스 등록 이후에는 사용되지 않을 변수를
	// 지역을 설정한 뒤 지역 내에서 선언/사용하여 메모리 절약.
	{
		// WNDCLASSEX: 창 프로그램의 설계도를 만들 수 있는 클래스(자료형).
		// wndClass: 창 프로그램의 설계도 역할(윈도우 클래스).
		WNDCLASSEX wndClass = WNDCLASSEX();

		wndClass.cbSize = sizeof(WNDCLASSEX);										// 윈도우 클래스의 크기(바이트) 설정.
		wndClass.style = CS_HREDRAW | CS_VREDRAW;									// 윈도우 클래스 스타일 설정.
		wndClass.lpfnWndProc = nullptr;												// 메세지 처리 함수에 대한 함수 포인터 설정.
		wndClass.hInstance = hInstance;												// 인스턴스 핸들 설정.
		wndClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);						// 작업표시줄 아이콘 모양 설정.
		wndClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);						// 타이틀 옆 아이콘 모양 설정.
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);							// 커서 모양 설정.
		wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));	// 배경색 설정.
		wndClass.lpszClassName = "Window";											// 윈도우 클래스의 이름.

		// RegisterClassEx: 윈도우 클래스 변수에 저장된 값에 따라 클래스를 등록시키는 함수(어디다 등록하는 건지는 모름).
		RegisterClassEx(&wndClass);
	}


	// wndClass와 마찬가지로 아래 window 변수도 한번 설정하면 이용하지 않으므로 지역을 설정하여 지역 내에서 선언.
	{
		// CREATESTRUCT: 윈도우 특성을 설정하는 데 사용하는 자료형.
		// window: 윈도우 핸들을 만들기 위한 설계도?
		CREATESTRUCT window = CREATESTRUCT();

		window.lpszClass = "Window";	// 윈도우 클래스 이름.
		window.lpszName = "Game";		// 윈도우 타이틀 이름.
		window.style = WS_CAPTION;		// 윈도우 스타일.
		window.hInstance = hInstance;	// 인스턴스 핸들.
		window.cx = 500;				// 윈도우 수평 크기(작업영역 및 제목표시줄 까지 포함한 크기).
		window.cy = 500;				// 윈도우 수직 크기(작업영역 및 제목표시줄 까지 포함한 크기).

		{
			// RECT: 직사각형 좌표를 담을 수 있는 자료형(left, top, right, bottom 멤버 변수를 포함).
			// rect: 윈도우 크기 설정을 위해 선언한 변수.
			RECT rect = RECT();

			// 아래 함수를 통해 순수 작업영역의 크기를 상기 설정한 대로 적용하기 위해 크기를 다시 구하는 과정.
			rect.right = window.cx;
			rect.bottom = window.cy;

			// AdjustWindowRectEx: 윈도우의 수평, 수직 크기를 재설정하는 함수(함수 자체의 반환값은 bool형).
			//					   3번째 인자가 현재 0(false)으로 설정되어있으므로
			//					   순수 작업영역의 크기를 500 x 500으로 설정하기 위한 윈도우 크기를 rect에 다시 저장한다.
			AdjustWindowRectEx(&rect, window.style, static_cast<bool>(window.hMenu), window.dwExStyle);

			// 위의 함수를 통해 재설정된 값이 rect에 갱신되었으므로 윈도우 수평, 수직 크기를 재계산하는 과정.
			window.cx = rect.right - rect.left;
			window.cy = rect.bottom - rect.top;
			window.x = 0;
			window.y = 0;
		}

		// hWnd: 윈도우 핸들.
		// CreateWindowEx: 윈도우를 생성하는 함수.
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

	// MSG: 프로그램에 전달되는 메세지를 나타내기 위한 자료형.
	//MSG msg;

	// WinMain 함수 종료.
	return 0;
}