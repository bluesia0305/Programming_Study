// Windows.h: WinAPI�� ����ϱ� ���� ��ɵ��� ��Ƴ��� ���.
#include <Windows.h>

// APIENTRY == __stdcall(��ũ�� ���).
// WinMain: WinAPI������ main �Լ��� ���� ����.
int APIENTRY WinMain(_In_ HINSTANCE const hInstance,	// ���� �ν��Ͻ� �ڵ�.
	_In_opt_ HINSTANCE const hInstancePrev,				// ���� �ν��Ͻ� �ڵ�.
	_In_ LPSTR const lpCmdLine,							// �ڸ𸧡�
	_In_ int const nCmdShow)							// �ڸ𸧡�
{
	HWND hWnd = nullptr;	// ������ �ڵ�.

	// �ڸ𸧡�: ������ Ŭ������ ������ �ڵ��� ��Ī ���̸� �˰� ��Ȯ�� ���� ������ �ǹ��ϴ����� ��.

	// ������ Ŭ���� ��� ���Ŀ��� ������ ���� ������
	// ������ ������ �� ���� ������ ����/����Ͽ� �޸� ����.
	{
		// WNDCLASSEX: â ���α׷��� ���赵�� ���� �� �ִ� Ŭ����(�ڷ���).
		// wndClass: â ���α׷��� ���赵 ����(������ Ŭ����).
		WNDCLASSEX wndClass = WNDCLASSEX();

		wndClass.cbSize = sizeof(WNDCLASSEX);										// ������ Ŭ������ ũ��(����Ʈ) ����.
		wndClass.style = CS_HREDRAW | CS_VREDRAW;									// ������ Ŭ���� ��Ÿ�� ����.
		wndClass.lpfnWndProc = nullptr;												// �޼��� ó�� �Լ��� ���� �Լ� ������ ����.
		wndClass.hInstance = hInstance;												// �ν��Ͻ� �ڵ� ����.
		wndClass.hIcon = LoadIcon(nullptr, IDI_APPLICATION);						// �۾�ǥ���� ������ ��� ����.
		wndClass.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);						// Ÿ��Ʋ �� ������ ��� ����.
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);							// Ŀ�� ��� ����.
		wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));	// ���� ����.
		wndClass.lpszClassName = "Window";											// ������ Ŭ������ �̸�.

		// RegisterClassEx: ������ Ŭ���� ������ ����� ���� ���� Ŭ������ ��Ͻ�Ű�� �Լ�(���� ����ϴ� ������ ��).
		RegisterClassEx(&wndClass);
	}


	// wndClass�� ���������� �Ʒ� window ������ �ѹ� �����ϸ� �̿����� �����Ƿ� ������ �����Ͽ� ���� ������ ����.
	{
		// CREATESTRUCT: ������ Ư���� �����ϴ� �� ����ϴ� �ڷ���.
		// window: ������ �ڵ��� ����� ���� ���赵?
		CREATESTRUCT window = CREATESTRUCT();

		window.lpszClass = "Window";	// ������ Ŭ���� �̸�.
		window.lpszName = "Game";		// ������ Ÿ��Ʋ �̸�.
		window.style = WS_CAPTION;		// ������ ��Ÿ��.
		window.hInstance = hInstance;	// �ν��Ͻ� �ڵ�.
		window.cx = 500;				// ������ ���� ũ��(�۾����� �� ����ǥ���� ���� ������ ũ��).
		window.cy = 500;				// ������ ���� ũ��(�۾����� �� ����ǥ���� ���� ������ ũ��).

		{
			// RECT: ���簢�� ��ǥ�� ���� �� �ִ� �ڷ���(left, top, right, bottom ��� ������ ����).
			// rect: ������ ũ�� ������ ���� ������ ����.
			RECT rect = RECT();

			// �Ʒ� �Լ��� ���� ���� �۾������� ũ�⸦ ��� ������ ��� �����ϱ� ���� ũ�⸦ �ٽ� ���ϴ� ����.
			rect.right = window.cx;
			rect.bottom = window.cy;

			// AdjustWindowRectEx: �������� ����, ���� ũ�⸦ �缳���ϴ� �Լ�(�Լ� ��ü�� ��ȯ���� bool��).
			//					   3��° ���ڰ� ���� 0(false)���� �����Ǿ������Ƿ�
			//					   ���� �۾������� ũ�⸦ 500 x 500���� �����ϱ� ���� ������ ũ�⸦ rect�� �ٽ� �����Ѵ�.
			AdjustWindowRectEx(&rect, window.style, static_cast<bool>(window.hMenu), window.dwExStyle);

			// ���� �Լ��� ���� �缳���� ���� rect�� ���ŵǾ����Ƿ� ������ ����, ���� ũ�⸦ �����ϴ� ����.
			window.cx = rect.right - rect.left;
			window.cy = rect.bottom - rect.top;
			window.x = 0;
			window.y = 0;
		}

		// hWnd: ������ �ڵ�.
		// CreateWindowEx: �����츦 �����ϴ� �Լ�.
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

	// MSG: ���α׷��� ���޵Ǵ� �޼����� ��Ÿ���� ���� �ڷ���.
	//MSG msg;

	// WinMain �Լ� ����.
	return 0;
}