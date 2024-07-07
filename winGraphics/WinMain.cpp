#include <Windows.h>

// Windows is all about two things:
// Windows + Messages
// Windows class - register windows class with windows
// Create a class instance - and that creates 
// actual windows that can be shown on the screen
// In Windows everything is a window - button, labels,...

// lpCmdLine
// =========
// To get a Unicode copy of the command - line 
// arguments, call the GetCommandLine function.
// This function returns all of the arguments in a single string.
// If you want the arguments as an argv - style array, pass this string to CommandLineToArgvW.


// CALLBACK (same as WINAPI) keyword is telling c++ compiler to use different
// calling convention for WinMain - and that is stdcall
// meaning caller is passing parameters order via stack but callee is cleaning up those
// instead of caller like in cdecl (trad. c function call)
// Most functions in the Windows API 
// are declared using WINAPI. 
// You may wish to use CALLBACK for the callback 
// functions that you implement to help identify the function as a callback function.

int CALLBACK WinMain(			// OS doesn't use return value, but you can pass it to another program
	HINSTANCE	hInstance,		// OS uses this to indentify EXE when it's loaded into memoty, and certain Win functions (i.e for bitmaps or icons)
	HINSTANCE	hPrevInstance,	// has no meaning, it was used in 16-bit windows
	LPSTR		lpCmdLine,		// cmd line arguments as an ANSII string (use wWinMain instead for Unicode)
	int			nCmdShow)		// indicates whether main app win is min, maximised or shown normally (when created)
{
	// 1. Register Windows Class
	const auto pClassName = L"winTitle";

	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = DefWindowProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hIconSm = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	
	RegisterClassEx(&wc);

	// 2. Create a Window

	HWND hWnd = CreateWindowEx(
		0,
		pClassName,
		L"Window Name",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200,
		640, 480,
		nullptr, nullptr,
		hInstance, nullptr
	);

	// 3. Show the Window
	ShowWindow(hWnd, SW_SHOW);

	while (true);

	return 0;
}