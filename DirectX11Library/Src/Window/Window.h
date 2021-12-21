
#ifndef WINDOW_H
#define WINDOW_H

#include <Windows.h>

class Window
{
public:
	static const char* p_ClassName;

private:
	static LRESULT CALLBACK WindowProc(
		HWND windowHandle_,
		UINT messageID_,
		WPARAM wparam_,
		LPARAM lparam_);

public:
	Window(const char* p_Title_, unsigned int width_, unsigned int height_) :
		p_Title(p_Title_),
		width(width_),
		height(height_)
	{}

	~Window() {}

	bool Create();

private:
	bool EntryWindowClass();
	void ResizeWindow(HWND windowHandle_);

private:
	const char* p_Title;
	unsigned int width;
	unsigned int height;
};

#endif // !WINDOW_H
