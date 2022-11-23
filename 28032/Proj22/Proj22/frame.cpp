#include <iostream>
#include "paintframe.h"

PaintFrame* theFrame = nullptr;
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

bool Frame::eventHandler(MEvent e)
{
	// TODO: 여기에 구현 코드 추가.
	OutputDebugString(L"Event\n");
	std::cout << L"Event\n" << std::endl;  // 여기는 cmd 창으로 출력

	// 이벤트의 종류를 파악해서 사각형 그리기를 여기서 해준다.
	if (e.isLButtonDownEvent() || e.isRButtonDownEvent()) {
		return true;
	}
	else {
		return false;
	}
}

void Frame::repaint() {
	// 그려야할 모든 것은 여기에. 아래 두 줄은 샘플이니 지워야한다.
}

void Frame::invalidate() {
	// 이 메소드를 부르면 화면을 다시 그리게 된다.
	InvalidateRect(hWnd_, nullptr, true);
}

void Frame::initialize() {

}

void Frame::addButton(Component* b) {
	buttons_[numButtons++] = b;
}
 
void Frame::drawButtons() {

}

Component* Frame::findButton(MPoint m) {
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
