
#include "Window.h"

const char* Window::p_ClassName = "DirectX11";

LRESULT CALLBACK Window::WindowProc(
	HWND windowHandle_,
	UINT messageID_,
	WPARAM wParam_,
	LPARAM lParam_)
{
	switch (messageID_)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(windowHandle_, messageID_, wParam_, lParam_);
		break;
	}

	return 0;
}

bool Window::Create()
{
	if (!EntryWindowClass()) return 0;

	HWND window_handle = CreateWindow(
		Window::p_ClassName,
		p_Title,
		(WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME) | WS_VISIBLE,
		CW_USEDEFAULT,
		0,
		width,
		height,
		NULL,
		NULL,
		GetModuleHandle(NULL),
		NULL);

	if (window_handle == NULL) return 0;

	ResizeWindow(window_handle);

	return true;
}

bool Window::EntryWindowClass()
{
	WNDCLASSEX window_class = {
		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW,
		WindowProc,
		0,
		0,
		GetModuleHandle(NULL),
		LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION)),
		LoadCursor(NULL, IDC_ARROW),
		NULL,
		NULL,
		Window::p_ClassName,
		NULL
	};

	if (RegisterClassEx(&window_class) == 0) return false;

	return true;
}

void Window::ResizeWindow(HWND windowHandle_)
{
	RECT window_rect;
	RECT client_rect;

	GetWindowRect(windowHandle_, &window_rect);
	GetClientRect(windowHandle_, &client_rect);

	int frame_size_x = (window_rect.right - window_rect.left) - (client_rect.right - client_rect.left);
	int frame_size_y = (window_rect.bottom - window_rect.top) - (client_rect.bottom - client_rect.top);

	SetWindowPos(windowHandle_, NULL, CW_USEDEFAULT, 0, frame_size_x + width, frame_size_y + height, SWP_NOMOVE);

	ShowWindow(windowHandle_, SW_SHOW);
	UpdateWindow(windowHandle_);
}
