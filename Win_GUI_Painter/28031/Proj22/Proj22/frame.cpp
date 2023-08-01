#include "frame.h"
#include "Misc.h"
#include <iostream>
#include "shape.h"
#include "Mbutton.h"

// 어쩔 수 없이 전역 변수 1개는 사용한다.
Frame* theFrame = nullptr;
static int num = 0;
static Shape* unknown[100];


// 전역함수로는 윈도 메시지 처리 함수가 있다.
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

		// 그리기 코드는 이걸로 끝!
		if (theFrame != nullptr)
			theFrame->repaint();

		EndPaint(Hw, &ps);  // BeginPaint의 짝이 된다
	}
	default: return DefWindowProc(Hw, Msg, wParam, lParam);
	}
}

Frame::Frame() :Frame(L"", 800, 600) {
	// 현재 사용되지 않고 있음.
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
		WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | // 종료 최소화 최대화 아이콘
		WS_THICKFRAME,  // resize가 가능하게
		0, 0, width, height, // x, y, width, height
		NULL, NULL, hInst_, NULL);  // Parent, Menu, instance handle, lpParam
	if (!hWnd_) throw 0;

	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_); 
	SetFocus(hWnd_);
	hDC_ = GetDC(hWnd_);
	invalidate();
}


// run 함수는 수정하면 위험함.
void Frame::run() {

	HACCEL hAccelTable = LoadAccelerators(hInst_, MAKEINTRESOURCE(IDI_APPLICATION));

	MSG msg;

	// 기본 메시지 루프입니다:
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
	// TODO: 여기에 구현 코드 추가.
	OutputDebugString(L"Event\n");
	std::cout << L"Event\n" << std::endl;  // 여기는 cmd 창으로 출력

	// 이벤트의 종류를 파악해서 사각형 그리기를 여기서 해준다.
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
	// 그려야할 모든 것은 여기에. 아래 두 줄은 샘플이니 지워야한다.
	drawButtons();
}

void Frame::invalidate() {
	// 이 메소드를 부르면 화면을 다시 그리게 된다.
	InvalidateRect(hWnd_, nullptr, true);
}

void Frame::initialize() {
	MButton* b1 = new MButton("사각형");
	MButton* b2 = new MButton("타원");
	MButton* b3 = new MButton("선분");
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