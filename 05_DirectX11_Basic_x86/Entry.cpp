// <������Ʈ �Ӽ� ���� ����>
// 1) ���� �Ӽ� - �Ϲ�
//	  - ��� ���͸�: $(SolutionDir).out\
//	  - �߰� ���͸�: $(SolutionDir).int\
//	  - C++ ��� ǥ��: ISO C++17 ǥ��(/std:c++17)
// 
// 2) ���� �Ӽ� - ���
//	  - ���� ����: ��Ƽ����Ʈ ���� ���� ���
//
// 3) ���� �Ӽ� - C/C++
//	  - ��� ������ ó��: ��(/WX)
//	  - ���� ���μ��� ������: ��(/MP)
//
// 4) ���� �Ӽ� - ��Ŀ - ��� �ɼ�
//	  - ��Ŀ ��� ������ ó��: ��(/WX)
//	  - ���� �ý���: â(/SUBSYSTEM:WINDOWS)


#include <Windows.h>

// ������ ���ν��� �Լ��� Pipeline.cpp�� �ű�鼭 �۷ι� ���ӽ����̽��� �ƴ�
// Pipeline�̶�� namespace ������ �Ű�� ������ ���⼭�� ���������� ������ �̸��� namespace ���� �������־���Ѵ�.
namespace Pipeline
{
	// CALLBACK == __stdcall(��ũ�� ���).
	LRESULT CALLBACK Procedure(HWND const, UINT const, WPARAM const, LPARAM const);
}

int APIENTRY WinMain(_In_ HINSTANCE const hInstance,
					 _In_opt_ HINSTANCE const hInstancePrev,
					 _In_ LPSTR const lpCmdLine,
					 _In_ int const nCmdShow)
{
	HWND hWnd = nullptr;

	// ������ Ŭ���� ���� �ڵ��.
	// : ������ Ŭ������ ���, Ŭ������ �Լ��� ���� ����ϱ⸸ �ϸ�
	//   ���Ŀ��� ���̻� ����� ���� �����Ƿ� ������ �����Ͽ� ���� ������ ����� ��
	//   Ŭ���� ����� �ϰ� ������ �������� ���ŵ� �� �ֵ��� �Ʒ��� ���� ����� �� �ִ�.
	{
		WNDCLASSEX wndClass = WNDCLASSEX();

		wndClass.cbSize			= sizeof(WNDCLASSEX);
		wndClass.style			= CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc	= Pipeline::Procedure;
		wndClass.hInstance		= hInstance;
		wndClass.hIcon			= LoadIcon(nullptr, IDI_APPLICATION);
		wndClass.hIconSm		= LoadIcon(nullptr, IDI_APPLICATION);
		wndClass.hCursor		= LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground	= static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));		// GetStockObject(): ��ü�� �������� �Լ�
		wndClass.lpszClassName	= "Window";

		RegisterClassEx(&wndClass);
	}
	
	// ������ ���� �ڵ��.
	{
		// ������ ����ü
		CREATESTRUCT window = CREATESTRUCT();

		window.lpszClass		= "Window";
		window.lpszName			= "Game";
		window.style			= WS_CAPTION | WS_SYSMENU;		// WS_SYSMENU = ������ ���� ��� - �� x ��ư�� Ȱ��ȭ.
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

		// SW_RESTORE: Ȱ��ȭ �� ���·� â�� ǥ���ϰ�, â�� �ּ�ȭ�� �� �ٽ� ����� ũ�⸦ ������Ű�� ���� ����ϴ� ��ũ�� ���.
		ShowWindow(hWnd, SW_RESTORE);
	}

	MSG msg;

	// �޼��� ó�� ���� �ڵ��.
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