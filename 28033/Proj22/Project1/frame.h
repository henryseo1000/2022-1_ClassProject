#pragma once
#include "Windows.h"
#include <string>
#include <list>
#include "Misc.h"
#include "component.h"
#include "C:\Users\henry\OneDrive - �������б�\���� ȭ��\28033\Proj22\Project1\List.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

class Component;
class Frame {
protected:
	// Window ���α׷����� ���� �⺻ �������̴�. �ǵ帮�� �ʴ´�.
	HINSTANCE hInst_;
	HWND hWnd_;	 // ���� �ڵ��� �����صд�.
	HDC hDC_;    // �� ������ �־�� �׸��� �׸� �� �ִ�.

	// �������� ����
	MyList<Component*> buttons_;
	int numButtons = 0;

	//
	//������ ���� �ʿ��� ����
	static const int FIG_NONE = 0;
	static const int FIG_RECT = 1;
	static const int FIG_ELLI = 2;
	static const int FIG_LINE = 3;

	// ������ ���� �ʿ��� ����
	MPoint start_;
	MPoint end_;

	// ��¿ �� ���� ���� ���� 1���� ����Ѵ�.


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
	Component* findButton(MPoint p); // p ��ġ�� Ŭ������ �� �ű� ��ư�� �����͸� �����ش�.
	virtual void setShape(int t);
	HDC getDC();

	int figType_ = FIG_NONE;
	int cmdType_ = 0;
	int num = 0;

	MyList<Component*>::iterator i;
};