// 2022-08-12 °úÁ¦


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
	static POINT MousePos_Prev = { 0, 0 };
	static POINT MousePos = { 0, 0 };
	static bool Draw = FALSE;

	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		if (Draw)
		{
			MoveToEx(hdc, MousePos_Prev.x, MousePos_Prev.y, NULL);
			LineTo(hdc, MousePos.x, MousePos.y);
			printf("¡Ú");
		}

		EndPaint(hWnd, &ps);
		break;
	}

	case WM_MOUSEMOVE:
		if (Draw)
		{
			MousePos_Prev = MousePos;
			MousePos.x = LOWORD(lParam);
			MousePos.y = HIWORD(lParam);
			InvalidateRect(hWnd, NULL, FALSE);
		}
		break;

	case WM_LBUTTONDOWN:
		Draw = TRUE;
		MousePos.x = LOWORD(lParam);
		MousePos.y = HIWORD(lParam);
		printf("WM_LBUTTONDOWN: (%i, %i)\n", MousePos.x, MousePos.y);
		break;

	case WM_LBUTTONUP:
		Draw = FALSE;
		printf("WM_LBUTTONUP\n");
		break;

	case WM_KEYDOWN:
		if (wParam == VK_SPACE)
		{
			InvalidateRect(hWnd, NULL, TRUE);
			printf("WM_KEYDOWN: Space\n");
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}