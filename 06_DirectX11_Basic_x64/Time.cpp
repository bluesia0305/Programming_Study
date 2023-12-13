#include "Time.h"

namespace Time
{
	namespace
	{
		std::chrono::steady_clock::time_point const Started = std::chrono::steady_clock::now();
		std::chrono::steady_clock::time_point		Updated	= std::chrono::steady_clock::now();

		float Elapsed = float();
		float Delta	  = float();
	}

	namespace Get
	{
		float Elapsed()	{ return Time::Elapsed; }
		float Delta()	{ return Time::Delta; }
	}
	
	void Procedure(HWND const hWnd, UINT const uMsg, WPARAM const wParam, LPARAM const lParam)
	{
		switch (uMsg)
		{
		case WM_APP:
		{
			using namespace std::chrono;
			Elapsed = duration_cast<duration<float>>(steady_clock::now() - Started).count();
			Delta	= duration_cast<duration<float>>(steady_clock::now() - Updated).count();
			Updated = steady_clock::now();
			return;
		}
		}
	}
}