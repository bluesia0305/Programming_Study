// WinAPI(Windows application programming interface)
// : Windows 운영체제에서 제공하는 응용 프로그램(application)을 만들 수 있도록(programming) 제공하는 인터페이스(interface).
//   * 프로젝트 속성 -> '링커' - '모든 옵션' - 하위 시스템: '창(/subsystem:windows)' 으로 설정.


// (★중요)
// <WinAPI의 이해를 위한 기초 개념>============================================================================================================
// 
// 핸들(Handle)
// : 운영체제가 무언가를 식별하기 위해 부여하는 키 값(주소).
//	 응용 프로그램에서 운영체제의 리소스에 직접 접근(=포인터)하는 것이 위험하므로,
//	 이러한 운영체제의 리소스에 대한 주소를 정수형으로 치환한 값(=핸들)으로 대신 이용한다.
//	 * 핸들은 일반적으로 32 bit의 unsigned 정수형 값을 가지고 있다(참고: 정수형이 비교가 제일 빠르다).
//	 * 핸들번호는 운영체제가 부여하는 값으로 사용자가 임의로 부여할 수 없다.
//	 * 핸들은 같은 종류의 핸들끼리 절대 중복되는 값을 가지지 않는다(식별을 목적으로 하므로).
//
// 인스턴스 핸들(Handle instance, HINSTANCE 형식)
// : 모든 실행 파일과 DLL 파일의 프로세스가 컴파일 -> 빌드 -> 런타임 과정을 거쳐 메모리 공간 상에 로드될 때(인스턴스화),
//	 해당 프로세스가 운영체제로부터 할당받는 핸들.
//
// 윈도우 클래스(Window class, WNDCLASS(EX) 형식)
// : 인스턴스 핸들이 가리키는 프로세스에서 생성할 윈도우의 여러 가지 특성을 정의하는 구조체(또는 해당 구조체 형식의 변수).
//
// 윈도우 핸들(Handle window, HWND 형식)
// : 프로세스 내에서의 특정 윈도우의 주소를 담는 변수. 즉, 프로세스 내의 윈도우를 구분하기 위한 값이다.
//	 * 프로세스 전체에 대한 정보를 어떤 함수의 매개변수로 전달하면 메모리가 비효율적으로 사용되므로(여러 윈도우들의 정보를 전부 다 넘기므로)
//	   특정 윈도우를 식별하여 해당 윈도우에 대한 정보만 전달하기 위해 사용한다.
//
// 디바이스 컨텍스트(Device context)
// : 출력에 필요한 정보를 가지는 데이터 구조체로, 좌표, 색, 굵기 등 출력에 필요한 모든 정보를 담는다.
//	
// 디바이스 컨텍스트 핸들(Handle device context, HDC 형식)
// : 디바이스 컨텍스트의 핸들.
// 
//===========================================================================================================================================


// (★중요)
// <윈도우 프로시저/메세지 루프 관련>==========================================================================================================
// 
// ★ WinAPI 작동 방식: 윈도우 클래스 등록 -> 윈도우 생성 -> 메세지 루프(윈도우 프로시저 호출)
// 
// ★ 메세지의 종류(WM_~)
// 1) 윈도우 생성/종료 관련
//	  - WM_CREATE		 : 윈도우가 처음 생성될 때 전송되는 메세지.
//	  - WM_PAINT		 : 시스템이나 다른 응용 프로그램이 응용 프로그램 창의 일부를 그리도록 요청할 때 전송되는 메세지.
//	  - WM_APP			 : 응용 프로그램에서 사용할 수 있는, 개인적으로 정의된 메시지.
//	  - WM_DESTROY		 : 윈도우가 종료될 때 전송되는 메세지(프로그램 종료와 관련 없음).
//	  - WM_QUIT			 : 프로세스 종료 시 전송되는 메세지.
// 
// 2) 키보드/마우스 입력 관련
//	  - WM_MOUSEMOVE	 : 마우스 좌표 이동 시 전송되는 메세지.
//	  - WM_LBUTTONDOWN   : 마우스 왼쪽 버튼을 누를 때 전송되는 메세지.
//	  - WM_LBUTTONUP	 : 마우스 왼쪽 버튼을 뗄 때 전송되는 메세지.
//	  - WM_LBUTTONDBLCLK : 마우스 왼쪽 버튼을 더블 클릭할 때 전송되는 메세지.
//	  					 * 마우스 오른쪽 버튼 = RBUTTON, 휠 버튼 = MBUTTON.
//	  - WM_KEYDOWN		 : 키보드의 특정 버튼을 누를 때 전송되는 메세지.
//	  - WM_KEYUP		 : 키보드의 특정 버튼을 뗄 때 전송되는 메세지.
// 
// ------------------------------------------------------------------------------------------------------------------------------------------
// 
// ★ 메세지 처리 관련 함수
// 1) 메세지 큐에서 메세지를 가져와 저장하는 함수
//	  - GetMessage(&msg,			-> LPMSG  lpMsg			: 메세지를 저장할 변수의 포인터.
// 				   hWnd,			-> HWND   hWnd			: 메세지를 받는 윈도우의 핸들.
// 				   WM_NULL,			-> UINT   wMsgFilterMin : 메세지 필터 최소값(수업에서 WM_NULL = 필터값 없음 사용).
//				   WM_NULL)			-> UINT   wMsgFilterMax : 메세지 필터 최대값(수업에서 WM_NULL = 필터값 없음 사용).
//		: 메세지 큐 상에 메세지가 존재할 때 true, 존재하지 않을 때는 대기하며 WM_QUIT 메세지가 들어올 때만 false를 반환하는 함수.
//		  * 메세지가 존재하지 않을 때: 대기 상태(메세지 루프 일시정지)를 가짐(데드 타임, dead time).
//			이 시간에 다른 프로세스가 CPU를 쓸 수 있도록 양보하는 특징이 있어 멀티태스킹이 이루어진다.
// 
//	  - PeekMessage(&msg,			-> LPMSG  lpMsg			: 메세지를 저장할 변수의 포인터.
//					hWnd,			-> HWND   hWnd			: 메세지를 받는 윈도우의 핸들.
//					WM_NULL,		-> UINT   wMsgFilterMin	: 메세지 필터 최소값(수업에서 WM_NULL = 필터값 없음 사용).
//					WM_NULL,		-> UINT   wMsgFilterMax	: 메세지 필터 최대값(수업에서 WM_NULL = 필터값 없음 사용).
//					PM_REMOVE)		-> UINT   wRemoveMsg	: 발생한 메세지를 메세지 큐에서 삭제할 것인지 여부
//		: 메세지 큐 상에 메세지가 존재하면 true, 존재하지 않으면 false를 반환하는 함수.
//		  * 메세지 큐에서 메세지를 꺼내거나 검사하되, 메세지가 없어도 즉각 리턴하므로 CPU 속도에 따라 메세지를 처리(즉, GetMessage 보다 빠르다).
// 
// 2) 메세지를 윈도우 프로시저로 전송하는 함수
//	  - SendMessage(hWnd,			-> HWND    hWnd			: 메세지를 보낼 윈도우의 윈도우 핸들.
//					WM_APP,			-> UINT	   Msg			: 프로시저에 전달할 메세지(WM_~).
//					0,				-> WPARAM  wParam		: 메세지에 대한 추가 정보.
//					0)				-> LPARAM  lParam		: 메세지에 대한 추가 정보.
// 		: 특정 윈도우의 윈도우 프로시저로 메세지를 전달하는 함수.
//		  * 해당 윈도우의 프로시저를 직접 호출하며, 프로시저가 메시지를 처리할 때까지 반환하지 않는다.
//
//		(참고용, 수업에서 진행 X)
//	  - PostMessage(message,		-> UINT	   message		: 메세지 큐에 포스트할 메세지(WM_~).
//					wParam,			-> WPARAM  wParam		: 메세지에 대한 추가 정보.
//					lParam)			-> LPARAM  lParam		: 메세지에 대한 추가 정보.
//		: 해당 메시지를 메시지 큐에 포스트하는 역할을 수행한다
//		  * 해당 윈도우의 프로시저가 메시지를 처리할 때까지 기다리지 않고 반환.
// 
//	  - DispatchMessage(&msg)		-> MSG*	   lpMsg		: 메세지를 저장하고 있는 변수의 포인터.
//		: 일반적으로 GetMessage/PeekMessage 함수에 의해 검색된 메시지를 윈도우 프로시저에 발송하는 함수.
// 
//	  - PostQuitMessage(value)		-> int	   nExitCode	: 프로세스 종료 시 전달할 exit code.
//		: value를 nExitCode로 하여 WM_QUIT 메세지를 메세지 큐에 포스트하는 함수.
//
//	  - DefWindowProc(hWnd,			-> HWND	   hWnd			: 메세지를 보낼 윈도우의 윈도우 핸들.
// 					  message,		-> UINT	   Msg			: 프로시저에 전달할 메세지(WM_~).
// 					  wParam,		-> WPARAM  wParam		: 메세지에 대한 추가 정보.
// 					  lParam,		-> LPARAM  lParam		: 메세지에 대한 추가 정보.
//		: 응용 프로그램이 처리하지 않는 모든 창 메시지에 대한 기본 처리를 제공하기 위해,
//		  기본 윈도우 프로시저(default window procedure)를 호출하여 메세지를 전달하는 함수.
//
//===========================================================================================================================================


#include <Windows.h>
#define MAX_LOADSTRING 100
#define WINSIZEX 1280
#define WINSIZEY 720

// WCHAR 자료형(typedef wchar_t WCHAR;)
// : 문자열을 표기할 때 접두사 L을 표기하여 사용함(사용하지 않을 경우 오류).
//   * 2 ~ 4 Byte의 크기를 차지하는 문자를 저장할 수 있다.
WCHAR szTitle[MAX_LOADSTRING] = L"Window";
WCHAR szWindowClass[MAX_LOADSTRING] = L"Window";

ATOM				MyRegisterClass(HINSTANCE hInstance);	// (★중요) 윈도우 클래스 등록 함수
BOOL				InitInstance(HINSTANCE, int);			// (★중요) 윈도우 프로그램 인스턴스화 함수
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);	// (★중요) 윈도우 프로시저 함수


// APIENTRY(#define __stdcall APIENTRY)
// : __stdcall 함수 호출 규약.

// (참고) SAL(Source-code annotation language, 소스 코드 주석 언어)
// _In_		: 데이터는 호출된 함수에 전달되고 읽기 전용으로 처리.
// _In_opt_	: 읽기 전용이며, 선택적 매개변수임을 명시.
// _Inout_  : 사용 가능한 데이터가 함수에 전달되고 잠재적으로 수정될 수 있음.
// _Out_	: 호출자는 호출된 함수가 쓸 수 있는 공간만 제공. 호출된 함수는 해당 공간에 데이터를 씀.

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,				// (★중요) 현재 인스턴스 핸들.
					  _In_opt_ HINSTANCE hPrevInstance,		// 직전 프로세스의 인스턴스 핸들(16비트 Windows, 현재 Windows에서 사용하지 않아 항상 0(NULL).
					  _In_ LPWSTR    lpCmdLine,				// 명령행에서 입력된 인수를 유니코드 문자열로 포함하는 매개변수.
					  _In_ int       nCmdShow)				// 프로그램이 실행될 형태를 설정하는 플래그(최소화, 보통모양, 최대화).
{
	MyRegisterClass(hInstance);

	if (!InitInstance (hInstance, nCmdShow))
	{ return FALSE; }

	MSG msg = MSG();	// 메세지를 저장할 구조.

	// (참고) <MSG 구조체 내의 멤버>
	// HWND		hWnd;
	// UINT		message;
	// WPARAM	wParam;
	// LPARAM	lParam;
	// DWORD	time;
	// POINT	pt;
	

	//// (★중요)
	//while (GetMessage(&msg, nullptr, 0, 0))
	//{
	//	// DispatchMessage(&msg): 메세지를 WndProc으로 보내주는 함수(#define으로 이름 변경된 상태)
	//	DispatchMessage(&msg);
	//}
	//
	//return (int) msg.wParam;

	HWND hWnd = GetConsoleWindow();
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			// 주의: 메세지가 WM_QUIT일 때도 PeekMessage()는 true를 반환하므로 프로세스를 종료하기 위해 별도 처리가 필요.
			if (msg.message == WM_QUIT) return (int)msg.wParam;
			DispatchMessage(&msg);
		}
		else SendMessage(hWnd, WM_APP, 0, 0);
	}
}

// (★중요)
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex = WNDCLASSEXW();
	
	wcex.cbSize = sizeof(WNDCLASSEX);							// 윈도우 클래스의 크기(byte).
	wcex.style			= CS_HREDRAW | CS_VREDRAW;				// 윈도우 클래스의 스타일(현재 설정: 수평(H), 수직(V) 크기가 변할 때 WM_PAINT 메세지를 발생시킨다).
	wcex.lpfnWndProc	= WndProc;								// (★중요) 메세지 처리 함수의 포인터.
	//wcex.cbClsExtra	= 0;									// (기본값) 클래스의 여분의 메모리.
	//wcex.cbWndExtra	= 0;									// (기본값) 윈도우의 여분의 메모리.
	wcex.hInstance		= hInstance;							// 종속할 프로세스의 인스턴스 핸들.
	wcex.hIcon			= LoadIcon(nullptr, IDI_APPLICATION);	// 작업 표시줄의 아이콘 설정(보통 첫번째 매개변수에 hInstance, nullptr = 기본값).
	wcex.hIconSm		= LoadIcon(nullptr, IDI_APPLICATION);	// 타이틀 옆 아이콘 설정(보통 첫번째 매개변수에 hInstance, nullptr = 기본값).
	wcex.hCursor		= LoadCursor(nullptr, IDC_ARROW);		// 커서 설정(Standard Cursor ID (IDC_~) 사용).
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);				// 배경 색상 설정(+1 = 흰색, +3 = 검은색).
	//wcex.lpszMenuName	= nullptr;								// (기본값) 메뉴 사용 여부 설정.
	wcex.lpszClassName	= szWindowClass;						// 등록할 클래스의 이름 설정.
	
	return RegisterClassExW(&wcex);								// (★중요) 윈도우 클래스 등록 함수.
}

// (★중요)
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	// (★중요)
	// RECT: Rectangle의 left, top, right, bottom 좌표를 저장하는 구조체.
	RECT rt = { 0, 0, WINSIZEX, WINSIZEY };
	
	// (★중요)
	// 작업영역을 설정하고자 하는 크기로 만들기 위해 필요한 윈도우의 크기를 구하는 함수.
	// * RECT 형식의 변수에 값을 다시 저장하는 형태(반환형: BOOL).
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);

	//// (참고) MoveWindow(): 윈도우의 크기를 변경하거나 윈도우를 이동시키는 함수.
	//MoveWindow(hWnd,					// 윈도우 핸들.
	//		   rt.left,					// 디스플레이 상에서 윈도우의 좌상단을 위치시킬 X 좌표.
	//		   rt.top,					// 디스플레이 상에서 윈도우의 좌상단을 위치시킬 Y 좌표.
	//		   rt.right - rt.left,		// 윈도우의 수평 크기.
	//		   rt.bottom - rt.top,		// 윈도우의 수직 크기.
	//		   false);					// 윈도우를 다시 그릴지에 대한 여부(false로 해도 이후 ShowWindow 함수가 존재하면 다시 그려짐).

	UINT xSize = rt.right - rt.left;
	UINT ySize = rt.bottom - rt.top;

	//// (참고) GetSystemMetrics(): 입출력 장치(하드웨어)와 관련된 설정값을 가져올 수 있는 함수.
	//xSize = GetSystemMetrics(SM_CXSCREEN) / 2;		// SM_CXSCREEN: 바탕화면 해상도의 수평 크기.
	//ySize = GetSystemMetrics(SM_CYSCREEN) / 2;		// SM_CYSCREEN: 바탕화면 해상도의 수직 크기.

	// (★중요)
	// 윈도우를 생성한 뒤, 해당 윈도우의 핸들을 반환하는 함수(첫번째 매개변수 DWORD dwExStyle = 0L -> 생략).
	// * 윈도우 생성에 실패할 경우, NULL을 반환.
	HWND hWnd = CreateWindowW(szWindowClass,		// LPCWSTR	  lpClassName  : (★중요) 생성할 윈도우의 클래스 이름.
	                          szTitle,				// LPCWSTR	  lpWindowName : (★중요) 생성할 윈도우의 타이틀.
	                          WS_OVERLAPPEDWINDOW,	// DWORD	  dwStyle	   : 윈도우 스타일(WS_~).
	                          CW_USEDEFAULT,		// int		  X			   : (★중요) 생성할 윈도우의 시작 X 좌표(좌상단 원점 좌표계 기준, CW_USEDEFAULT = 기본값).
	                          0,					// int		  Y			   : (★중요) 생성할 윈도우의 시작 Y 좌표(좌상단 원점 좌표계 기준).
	                          xSize,				// int		  nWidth	   : (★중요) 윈도우 수평 크기(타이틀 및 메뉴 등의 크기 포함).
	                          ySize,				// int		  nHeight	   : (★중요) 윈도우 수직 크기(타이틀 및 메뉴 등의 크기 포함).
	                          nullptr,				// HWND		  hWndParent   : 부모 윈도우 존재 여부(nullptr = 사용 안함).
	                          nullptr,				// HMENU	  hMenu		   : 메뉴 사용 여부(nullptr = 사용 안함).
	                          hInstance,			// HINSTANCE  hInstance	   : 종속할 프로세스의 인스턴스 핸들.
	                          nullptr);				// LPVOID	  lpParam	   : WM_CREATE 메시지의 lParam 매개 변수가 가리키는 CREATESTRUCT 구조체의
													//							 lpCreateParams 멤버를 통해 창에 전달할 값에 대한 포인터.
	
	if (!hWnd) return FALSE;

	// (★중요)
	// 윈도우를 보여주는 함수.
	ShowWindow(hWnd, nCmdShow);
	
	return TRUE;
}

// CALLBACK(#define __stdcall CALLBACK)
// : __stdcall 함수 호출 규약.

// (★중요)
// 윈도우 프로시저 함수
// : 메세지를 처리하는 함수로, 모든 메세지는 처리된 뒤에는 반드시 0을 반환해야하며
//   DefWindowProc()에 의해 메세지가 디폴트로 처리되는 경우에는 해당 함수의 반환값을 반환해야한다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static BOOL Draw = FALSE;
	static int X, Y;
	static const int Grid = 40;
	static const int boxSize = 30;
	static const int Space = (Grid - boxSize) / 2;

	// (★중요)
	// POINT: (x, y) 좌표를 저장할 수 있는 구조체.
	static POINT point = { 0, 0 };
	static POINT mouse = { 0, 0 };
	static bool bPicked = false;

	switch (message)
	{
	// (★중요)
	// switch ~ case 구문 내에서 새로운 변수의 선언을 하기 위해서는 case마다 중괄호를 사용해야 한다.
	case WM_APP:
		InvalidateRect(hWnd, NULL, true);
		break;
	
	case WM_PAINT:
	{
		// (★중요)
		// <그리기 관련 함수>==================================================================================================================
		// 
		// BeginPaint(hWnd, &ps)
		// : 페인팅을 위해 지정된 창을 준비하고, 페인팅에 대한 정보로 PAINTSTRUCT 구조를 채우는 함수.
		// 
		// EndPaint(hWnd, &ps)
		// : 페인팅을 종료하는 함수.
		// 
		// InvalidateRect(hWnd,			// HWND			hWnd   : 갱신할 윈도우의 핸들.
		//				  NULL,			// const RECT*  lpRect : 갱신시킬 영역(NULL: 윈도우 전체 갱신).
		//				  true)			// BOOL			bErase : 윈도우 화면을 지우고 다시 그릴지에 대한 여부
		//														 * true: BeginPaint 함수 호출 시 화면 지워짐, false: 화면 유지.
		// : 지정된 창의 업데이트 영역을 갱신시켜주는 함수로, 메세지 큐의 현재 메세지 뒤에 WM_PAINT 메세지를 보내는 함수.
		// 
		// MoveToEx(hdc, X, Y, NULL)
		// : 현재 위치를 지정된 (X, Y)로 이동시키는 함수(LPPOINT lppt : (선택적) 이전 위치의 좌표를 반환할 POINT 형식을 가리키는 포인터).
		// 
		// LineTo(hdc, X, Y)
		// : 현재 위치로부터 지정된 (X, Y)까지의 직선을 그리는 함수, 함수 실행이 성공하면 현재 위치가 (X, Y)로 갱신됨.
		// 
		// Rectangle(hdc, LEFTTOP_X, LEFTTOP_Y, RIGHTBOTTOM_X, RIGHTBOTTOM_Y):
		// : 해당 사각형 범위와 동일한 크기의 직사각형을 그리는 함수.
		// 
		// Ellipse(hdc, LEFTTOP_X, LEFTTOP_Y, RIGHTBOTTOM_X, RIGHTBOTTOM_Y)
		// : 해당 사각형 범위에 내접하는 원을 그리는 함수.
		// 
		// TextOut(HDC, X, Y, wchar_t(또는 char), length)
		// : 해당 좌표에 wchar_t 형식의 문자열 중에서 length 까지만큼을 출력하는 함수.
		// 
		// MessageBox(hWnd,				// HWND					hWnd	  : 메세지 박스를 띄울 윈도우의 핸들.
		//			  L"KeyDown!",		// LPCWSTR(또는 LPCSTR)	lpText	  : 메세지 박스 내에 띄울 텍스트.
		//			  L"Message Box",	// LPCWSTR(또는 LPCSTR)	lpCaption : 메세지 박스의 제목.
		//			  NULL)				// UINT					uType	  : 대화 상자의 내용과 동작과 관련된 플래그(NULL: 확인 버튼 하나만 존재).
		// : 해당 윈도우에 메세지 상자를 띄우는 함수.
		// 
		//====================================================================================================================================
		

		PAINTSTRUCT ps;						// 그리기 도구 집합 구조체(PAINTSTRUCT)형 변수 선언.
		HDC hdc = BeginPaint(hWnd, &ps);

		//// (실습) 별모양 그리기
		//UINT xCenter = 600;
		//UINT xSpace1 = 40;
		//UINT xSpace2 = 50;
		//UINT yTop = 200;
		//UINT yBottom = 300;
		//
		//MoveToEx(hdc, xCenter, yTop, NULL);
		//LineTo(hdc, xCenter - xSpace1, yBottom);
		//LineTo(hdc, xCenter + xSpace2, yTop + (yBottom - yTop) * 0.33);
		//LineTo(hdc, xCenter - xSpace2, yTop + (yBottom - yTop) * 0.33);
		//LineTo(hdc, xCenter + xSpace1, yBottom);
		//LineTo(hdc, xCenter, yTop);
		//
		//// (실습) 텍스트 넣기
		//TextOutW(hdc, 500, 500, L"하이루", 3);
		//
		//// (실습) 키 입력에 따라 움직이는 사각형 만들기
		//Rectangle(hdc, 50 + point.x, 50 + point.y, 100 + point.x, 100 + point.y);

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
	
	case WM_LBUTTONDOWN:
	{
		//Draw = TRUE;
		//x = LOWORD(lParam);
		//y = HIWORD(lParam);

		if (mouse.x >= point.x && mouse.x <= point.x + boxSize &&
			mouse.y >= point.y && mouse.y <= point.y + boxSize)
			bPicked = TRUE;
		break;
	}
	
	case WM_MOUSEMOVE:
		if (Draw)
		{
			//HDC hdc = GetDC(hWnd);
			//MoveToEx(hdc, x, y, NULL);
	
			//x = LOWORD(lParam);
			//y = HIWORD(lParam);
			//LineTo(hdc, x, y);
		}

		mouse.x = LOWORD(lParam);
		mouse.y = HIWORD(lParam);
		if (bPicked)
		{
			point = mouse;
			InvalidateRect(hWnd, NULL, true);
		}
		break;
	
	case WM_LBUTTONUP:
		//Draw = FALSE;
		bPicked = FALSE;
		break;
	
	case WM_KEYDOWN:
	{
		// <메세지에 대한 추가적인 정보를 저장하는 변수>
		// - wParam: 키보드 입력에 대한 추가적인 정보(ASCII 코드).
		// - lParam: 마우스 입력에 대한 추가적인 정보.
		//   * LOWORD(lParam): 작업영역 좌표계 기준, 마우스의 x 좌표.
		//   * HIWORD(lParam): 작업영역 좌표계 기준, 마우스의 y 좌표.

		switch (wParam)
		{
		case 'A': if (point.x - 5 > 0) point.x -= 5; break;
		case 'D': if (point.x + 5 < WINSIZEX) point.x += 5; break;
		case 'W': if (point.y - 5 > 0) point.y -= 5; break;
		case 'S': if (point.y + 5 < WINSIZEY) point.y += 5; break;
		}

		InvalidateRect(hWnd, NULL, true);
		break;
		
		//// 'a' 키를 누를 때만 작동한다(주의: 문자 비교가 아닌 ASCII 코드(int) 비교).
		//if (wParam == 'A') MessageBox(hWnd, L"KeyDown!", L"Message Box", NULL);
		//break;
	}
		
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	
	// 상기 switch ~ case 구문에서 처리되지 않는 메세지를 처리.
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	
	return 0;
}