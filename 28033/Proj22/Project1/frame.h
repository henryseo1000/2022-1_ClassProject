#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "component.h"
#include "C:\Users\henry\OneDrive - 명지대학교\바탕 화면\28033\Proj22\Project1\List.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Component;
class Frame {
protected:
	// Window 프로그래밍을 위한 기본 변수들이다. 건드리지 않는다.
	HINSTANCE hInst_;
	HWND hWnd_;	 // 윈도 핸들을 저장해둔다.
	HDC hDC_;    // 이 변수가 있어야 그림을 그릴 수 있다.

	// 공통적인 변수
	MyList<Component*> buttons_;
	int numButtons = 0;

	//
	//응용을 위해 필요한 변수
	static const int FIG_NONE = 0;
	static const int FIG_RECT = 1;
	static const int FIG_ELLI = 2;
	static const int FIG_LINE = 3;

	// 응용을 위해 필요한 변수
	MPoint start_;
	MPoint end_;

	// 어쩔 수 없이 전역 변수 1개는 사용한다.


public:
	Frame();
	Frame(std::wstring, int, int);
	void run();
	virtual bool eventHandler(MEvent e);
	virtual void repaint();
	void invalidate();
	virtual void initialize();
	void addButton(Component* b);
	virtual void drawButtons();
	Component* findButton(MPoint p); // p 위치를 클릭했을 때 거기 버튼의 포인터를 돌려준다.
	virtual void setShape(int t);
	HDC getDC();

	int figType_ = FIG_NONE;
	int cmdType_ = 0;
	int num = 0;

	MyList<Component*>::iterator i;
};