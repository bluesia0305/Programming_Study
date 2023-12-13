// 2022-08-11 과제


#include <iostream>
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
	RECT rt = { 0, 0, WINSIZEX, WINSIZEY };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);

	UINT xSize = rt.right - rt.left;
	UINT ySize = rt.bottom - rt.top;
	
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, xSize, ySize, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{ return FALSE; }

	ShowWindow(hWnd, nCmdShow);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static const int Grid = 40;
	static const int boxSize = 30;
	static const int Space = (Grid - boxSize) / 2;
	static POINT point = { 0, 0 };

	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		int maxLineH = WINSIZEY / Grid;
		int maxLineV = WINSIZEX / Grid;
		int maxLine = maxLineH;
		if (maxLineV > maxLineH) maxLine = maxLineV;

		for (int i = 0; i <= maxLine; i++)
		{
			if (i <= maxLineH)
			{
				MoveToEx(hdc, 0, Grid * i, NULL);
				LineTo(hdc, WINSIZEX, Grid * i);
			}
			if (i <= maxLineV)
			{
				MoveToEx(hdc, Grid * i, 0, NULL);
				LineTo(hdc, Grid * i, WINSIZEY);
			}
		}

		Rectangle(hdc, point.x + Space, point.y + Space, point.x + Grid - Space, point.y + Grid - Space);
		EndPaint(hWnd, &ps);
		break;
	}

	case WM_KEYDOWN:
	{
		printf("KEYDOWN >> 상자 이동.\n");
		switch (wParam)
		{
		case 'A': if (point.x >= Grid) point.x -= Grid; break;
		case 'D': if (point.x < WINSIZEX - Grid) point.x += Grid; break;
		case 'W': if (point.y >= Grid) point.y -= Grid; break;
		case 'S': if (point.y < WINSIZEY - Grid) point.y += Grid; break;
		}

		InvalidateRect(hWnd, NULL, true);
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