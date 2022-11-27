#include "Misc.h"

MEvent::MEvent(UINT msg, WPARAM wParam, LPARAM lParam) :
	msg_(msg), wParam_(wParam), lParam_(lParam) 
{
	//  Nothing to do here.
}

bool MEvent::isLButtonDownEvent() {
	return msg_ == WM_LBUTTONDOWN;
}

bool MEvent::isLButtonUpEvent() {
	return msg_ == WM_LBUTTONUP;
}

bool MEvent::isRButtonDownEvent() {
	return msg_ == WM_RBUTTONDOWN;
}

bool MEvent::isRButtonUpEvent() {
	return msg_ == WM_RBUTTONUP;
}

bool MEvent::isCtrlKeyDown() {
	return MK_CONTROL & wParam_;
}

bool MEvent::isShiftKeyDown() {
	return MK_SHIFT & wParam_;
}

int MEvent::getX() {
	WORD x = 0;
	x = LOWORD(lParam_);
	return x;
}

int MEvent::getY() {
	WORD y = 0;
	y = HIWORD(lParam_);
	return y;
}

MPoint MEvent::getPoint() {
	return MPoint(getX(), getY());
}

MPoint::MPoint(int x, int y): x_(x), y_(y){

}

MPoint::MPoint() : x_(0), y_(0) {

}

