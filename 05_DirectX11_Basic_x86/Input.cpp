#include <iostream>
#include <Windows.h>

namespace Input
{
	static class
	{
	public:
		// 키보드 키 입력 -> 0 ~ 255 까지의 숫자로 표현(즉, 1 바이트만 있어도 표현 가능).
		// 0x8000	==	16진수 8000		==	1000 0000 0000 0000 (2진수).
		void Down(WPARAM const code)	{ State.BitSwitch[code >> 0x4] = State.BitSwitch[code >> 0x4] | (0x8000 >> (code & 0xf)); }
		void Up(WPARAM const code)		{ State.BitSwitch[code >> 0x4] = State.BitSwitch[code >> 0x4] ^ (0x8000 >> (code & 0xf)); }
		bool Pressed(WPARAM const code) { return						 State.BitSwitch[code >> 0x4] & (0x8000 >> (code & 0xf)); }
		bool Changed(WPARAM const code) { return 0; }
		void Update() { return; }

	private:
		struct
		{
			USHORT BitSwitch[16];		// 모든 요소가 0으로 초기화.
			USHORT Changed[16];			// 모든 요소가 0으로 초기화.
		}State;
	}Key;

	namespace Get
	{
		bool Down(WPARAM const code) { return Key.Pressed(code); }
	}

	void Procedure(HWND const hWnd, UINT const uMessage, WPARAM const wParam, LPARAM const lParam)
	{
		switch (uMessage)
		{
		case WM_KEYDOWN:
			Key.Down(wParam);
			break;

		case WM_KEYUP:
			Key.Up(wParam);
			break;
		}
	}
}