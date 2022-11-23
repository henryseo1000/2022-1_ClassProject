#include "Mbutton.h"
#include <string>
#include <atlbase.h>
using namespace std;

MButton::MButton(string s, int x, int y, int width, int height) {
	name_ = s;
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
}
MButton::MButton(string s) {
	name_ = s;
}
/*bool MButton::includes(int x, int y) {

}*/

bool MButton::includes(MPoint p) {
	if (p.x_ > x_ && p.x_ < x_ + width_ && p.y_ > y_ && p.y_ < y_ + height_) {
		return true;
	}
	return false;
}

void MButton::setx(int x) {
	x_ = x;
}

int MButton::getHeight() {
	return height_;
}

int MButton::getWidth() {
	return width_;
}

void MButton::draw(HDC hdc, int x, int y) {
	x_ = x;
	y_ = y;
	Rectangle(hdc, x, y, x + default_width, y + default_height);
	RECT re = { x, y, x + default_width, y + default_height };
	
	int len;
	int slength = (int)name_.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, name_.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, name_.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	LPCWSTR result = r.c_str();

	DrawText(hdc, result, -1, &re, DT_VCENTER | DT_CENTER);
}

void MButton::onClick(MEvent e) {
	if (includes(e.getPoint())) {
		f_->setShape(Command_);
	}
}

void MButton::setCommand(int a) {
	Command_ = a;
}

void MButton::setFrame(Frame* f) {
	f_ = f;
}