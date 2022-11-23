#include "frame.h"
#include "Misc.h"
#include <iostream>
#include "shape.h"
#include "Mbutton.h"

// ��¿ �� ���� ���� ���� 1���� ����Ѵ�.
Frame* theFrame = nullptr;
static int num = 0;
static Shape* unknown[100];


// �����Լ��δ� ���� �޽��� ó�� �Լ��� �ִ�.
LRESULT CALLBACK WndProc(HWND Hw, UINT Msg, WPARAM wParam, LPARAM lParam)
{

	switch (Msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
	case WM_LBUTTONDOWN:
	case WM_LBUTTONDBLCLK:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONDBLCLK:
	case WM_RBUTTONUP:
	case WM_KEYDOWN:
	case WM_KEYUP:
	case WM_CHAR:
	case WM_SIZE:
		if (theFrame != nullptr)
			theFrame->eventHandler(MEvent(Msg, wParam, lParam));
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(Hw, &ps);

		// �׸��� �ڵ�� �̰ɷ� ��!
		if (theFrame != nullptr)
			theFrame->repaint();

		EndPaint(Hw, &ps);  // BeginPaint�� ¦�� �ȴ�
	}
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

Frame::Frame() :Frame(L"", 800, 600) {
	// ���� ������ �ʰ� ����.
}

Frame::Frame(std::wstring title, int width, int height) {
	hInst_ = GetModuleHandle(NULL);
	FreeConsole(); // No console
	// Register win class
	WNDCLASSEX Wc;

	Wc.cbSize = sizeof(WNDCLASSEX);
	Wc.style = CS_HREDRAW | CS_VREDRAW;
	Wc.lpfnWndProc = WndProc;
	Wc.cbClsExtra = 0;
	Wc.cbWndExtra = 0;
	Wc.hInstance = hInst_;
	Wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wc.lpszMenuName = NULL;
	Wc.lpszClassName = L"MyWin";
	Wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(&Wc);

	hWnd_ = CreateWindowExW(WS_EX_TOPMOST, L"MyWIn", (WCHAR*)title.c_str(),
		WS_OVERLAPPED |
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // ���� �ּ�ȭ �ִ�ȭ ������
		WS_THICKFRAME,  // resize�� �����ϰ�
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_); 
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);
	invalidate();
}


// run �Լ��� �����ϸ� ������.
void Frame::run() {

	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));

	MSG msg;

	// �⺻ �޽��� �����Դϴ�:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

void Frame::eventHandler(MEvent e)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	OutputDebugString(L"Event\n");
	std::cout << L"Event\n" << std::endl;  // ����� cmd â���� ���

	// �̺�Ʈ�� ������ �ľ��ؼ� �簢�� �׸��⸦ ���⼭ ���ش�.
	if (e.isLButtonDownEvent() || e.isRButtonDownEvent()) {
		start_ = e.getPoint();
		OutputDebugString(L"Down\n");
	}
	else if (e.isLButtonUpEvent()) {
		end_ = e.getPoint();
		if (findButton(end_) != nullptr) {
			findButton(end_)->onClick(e);
		}
		if (figType_ == 0) {

		}
		else if (figType_ == 1) {
			unknown[num] = new Rect(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		}
		else if (figType_ == 2) {
			unknown[num] = new Elli(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		}
		else if (figType_ == 3) {
			unknown[num] = new Line(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		}
		num++;
		//Rectangle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		OutputDebugString(L"LUp\n");
	}
	else if (e.isRButtonUpEvent()) {
		end_ = e.getPoint(); 
		if (findButton(end_) != nullptr) {
			findButton(end_)->onClick(e);
		}
		if (figType_ == 0) {

		}
		else if (figType_ == 1) {
			unknown[num] = new Rect(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		}
		else if (figType_ == 2) {
			unknown[num] = new Elli(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		}
		else if (figType_ == 3) {
			unknown[num] = new Line(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		}
		num++;
		//Ellipse(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		OutputDebugString(L"RUp\n");
	}
}

void Frame::repaint() {
	// �׷����� ��� ���� ���⿡. �Ʒ� �� ���� �����̴� �������Ѵ�.
	drawButtons();
}

void Frame::invalidate() {
	// �� �޼ҵ带 �θ��� ȭ���� �ٽ� �׸��� �ȴ�.
	InvalidateRect(hWnd_, nullptr, true);
}

void Frame::initialize() {
	MButton* b1 = new MButton("�簢��");
	MButton* b2 = new MButton("Ÿ��");
	MButton* b3 = new MButton("����");
	b1->setCommand(FIG_RECT);
	b2->setCommand(FIG_ELLI);
	b3->setCommand(FIG_LINE);
	b1->setFrame(this);
	b2->setFrame(this);
	b3->setFrame(this);
	addButton(b1);
	addButton(b2);
	addButton(b3);
}

void Frame::addButton(MButton* b) {
	buttons_[numButtons++] = b;
}
 
void Frame::drawButtons() {
	for (int i = 0; i < numButtons; i++) {
		buttons_[i]->draw(hDC_, 0 + i * buttons_[i] -> default_width, 0);
	}
	for (int i = 0; i < num; i++) {
		if (unknown[i] != nullptr) {
			unknown[i]->draw();
		}
	}
}

MButton* Frame::findButton(MPoint m) {
	for (int i = 0; i < numButtons; i++) {
		if (buttons_[i]->includes(m)) {
			return buttons_[i];
		}
	}
	return nullptr;
}

void Frame::setShape(int t) {
	figType_ = t;
}