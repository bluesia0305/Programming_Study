#include <iostream>
#include <Windows.h>

namespace Input
{
	static class
	{
	public:
		// Ű���� Ű �Է� -> 0 ~ 255 ������ ���ڷ� ǥ��(��, 1 ����Ʈ�� �־ ǥ�� ����).
		// 0x8000	==	16���� 8000		==	1000 0000 0000 0000 (2����).
		void Down(WPARAM const code)	{ State.BitSwitch[code >> 0x4] = State.BitSwitch[code >> 0x4] | (0x8000 >> (code & 0xf)); }
		void Up(WPARAM const code)		{ State.BitSwitch[code >> 0x4] = State.BitSwitch[code >> 0x4] ^ (0x8000 >> (code & 0xf)); }
		bool Pressed(WPARAM const code) { return						 State.BitSwitch[code >> 0x4] & (0x8000 >> (code & 0xf)); }
		bool Changed(WPARAM const code) { return 0; }
		void Update() { return; }

	private:
		struct
		{
			USHORT BitSwitch[16];		// ��� ��Ұ� 0���� �ʱ�ȭ.
			USHORT Changed[16];			// ��� ��Ұ� 0���� �ʱ�ȭ.
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