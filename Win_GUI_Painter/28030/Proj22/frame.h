#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "shape.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Frame {
protected:
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;	 // ���� �ڵ��� �����صд�.
	HDC hDC_;    // �� ������ �־�� �׸��� �׸� �� �ִ�.

	// ������ ���� �ʿ��� ����
	MPoint start_;
	MPoint end_;

public:
	Frame();
	Frame(std::wstring, int, int);
	virtual void run();
	virtual void eventHandler( MEvent e);
	virtual void repaint();
	void invalidate();
};