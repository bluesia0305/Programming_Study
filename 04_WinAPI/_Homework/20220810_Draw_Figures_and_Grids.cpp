// 2022-08-10 과제


#include <Windows.h>
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#define MAX_LOADSTRING 100
#define WINSIZEX 1280
#define WINSIZEY 720

WCHAR szTitle[MAX_LOADSTRING] = L"Window";
WCHAR szWindowClass[MAX_LOADSTRING] = L"Window";

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{

	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{ return FALSE; }

	MSG msg = MSG();

	while (GetMessage(&msg, nullptr, 0, 0))
	{ DispatchMessage(&msg); }

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowClass;

	return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, WINSIZEX, WINSIZEY, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{ return FALSE; }

	RECT rt = { 100, 100, 1380, 820 };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	MoveWindow(hWnd, rt.left, rt.top, rt.right - rt.left, rt.bottom - rt.top, true);
	ShowWindow(hWnd, nCmdShow);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		static UINT Size;
		static UINT X;
		static UINT Y;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// 1) 사각형-원형 번갈아 그리기
		Size = 100;
		static UINT Space = 0.2 * Size;

		for (int i = 0; i < 25; i++)
		{
			X = (i % 5 + 1) * Space + i % 5 * Size;
			Y = (i / 5 + 1) * Space + i / 5 * Size;

			if ((i / 5) % 2) Ellipse(hdc, X, Y, X + Size, Y + Size);
			else Rectangle(hdc, X, Y, X + Size, Y + Size);
		}

		// 2) 격자 그리기
		Size = 40;
		X = 0;
		Y = 0;

		while (true)
		{
			Rectangle(hdc, X, Y, X + Size, Y + Size);
			X += Size;
			if (X >= WINSIZEX)
			{
				X = 0;
				Y += Size;
				if (Y >= WINSIZEY) break;
			}
		}


		EndPaint(hWnd, &ps);
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}