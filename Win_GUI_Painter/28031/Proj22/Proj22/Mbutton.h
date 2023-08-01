#pragma once
#include <string>
#include "frame.h"
#include "Misc.h"
using namespace std;
class Frame;
class MButton {
public :
	MButton(string s, int x, int y, int width, int height);
	MButton(string s);
	//bool includes(int x, int y);
	bool includes(MPoint p);
	void setx(int x);
	int getHeight();
	int getWidth();
	void draw(HDC hdc, int x, int y);
	void onClick(MEvent p);
	void setCommand(int a);
	void setFrame(Frame * f);

	static const int default_height = 30;
	static const int default_width = 100;

	int x_ = 0; 
	int y_ = 0; 
	int width_ = default_width; 
	int height_ = default_height;
	int Command_ = 0;
	string name_;
	Frame* f_;
};