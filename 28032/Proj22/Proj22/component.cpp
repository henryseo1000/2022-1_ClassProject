#include "component.h"
#include <string>
#include "paintframe.h"
using namespace std;

//Component
Component::Component() {

}
Component::Component(string s, int x, int y, int width, int height) {
	name_ = s;
	x_ = x;
	y_ = y;
	width_ = width;
	height_ = height;
}
Component::Component(string s) {
	name_ = s;
}
/*bool MButton::includes(int x, int y) {

}*/

bool Component::includes(MPoint p) {
	if (p.x_ > x_ && p.x_ < x_ + width_ && p.y_ > y_ && p.y_ < y_ + height_) {
		return true;
	}
	return false;
}

void Component::setx(int x) {
	x_ = x;
}

int Component::getHeight() {
	return height_;
}

int Component::getWidth() {
	return width_;
}

void Component::draw(HDC hdc, int x, int y) {
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

void Component::onClick(MEvent e) {
	if (includes(e.getPoint())) {
		f_->setShape(Command_);
	}
}

void Component::setCommand(int a) {
	Command_ = a;
}

void Component::setFrame(Frame* f) {
	f_ = f;
}

//Mbutton
MButton::MButton(string s, int x, int y, int width, int height) : Component(s, x, y, width, height) {

}
MButton::MButton(string s) : Component(s) {
	
}
/*bool MButton::includes(int x, int y) {

}*/



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



//checkbox
checkbox::checkbox(string s, int x, int y, int width, int height) : Component(s, x, y, width, height) {
}
checkbox::checkbox(string s) : Component(s) {
}
/*bool MButton::includes(int x, int y) {

}*/

void checkbox::draw(HDC hdc, int x, int y) {
	x_ = x;
	y_ = y;
	Rectangle(hdc, x, y, x + default_width, y + default_height);
	RECT re = { x, y, x + default_width, y + default_height };

	string R;
	if (f_->cmdType_ == 0) {
		R = "[ ]" + name_;
	}
	else {
		R = "[v]" + name_;
	}

	int len;
	int slength = (int)R.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, R.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, R.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	LPCWSTR result = r.c_str();

	DrawText(hdc, result, -1, &re, DT_VCENTER | DT_CENTER);
}

void checkbox::onClick(MEvent e) {
		if (f_->cmdType_ == 1) {
			f_->cmdType_ = 0;
		}
		else {
			f_->cmdType_ = 1;
		}
	
}

void checkbox::setCommand(int a) {
	Command_ = a;
}