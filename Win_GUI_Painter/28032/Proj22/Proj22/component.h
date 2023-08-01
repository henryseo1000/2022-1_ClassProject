#pragma once
#include <string>
#include "Misc.h"
#include "paintframe.h"
#include "frame.h"
using namespace std;

class Frame;
class PaintFrame;
class Component{
public:
	static const int default_height = 30;
	static const int default_width = 150;

	Component();
	Component(string s, int x, int y, int width, int height);
	Component(string s);
	//bool includes(int x, int y);
	virtual bool includes(MPoint p);
	void setx(int x);
	int getHeight();
	int getWidth();
	virtual void draw(HDC hdc, int x, int y);
	virtual void onClick(MEvent p);
	void setFrame(Frame* f);

protected:
	int x_ = 0;
	int y_ = 0;
	int width_ = default_width;
	int height_ = default_height;
	string name_;
	Frame* f_ = nullptr;
};

class MButton : public Component {
public:
	MButton(string s, int x, int y, int width, int height);
	MButton(string s);
	//bool includes(int x, int y);

	void draw(HDC hdc, int x, int y) override;
	void onClick(MEvent p) override;

	void setCommand(int a);
	int Command_ = 0;
};

class checkbox : public Component {
public:
	checkbox(string s, int x, int y, int width, int height);
	checkbox(string s);
	//bool includes(int x, int y);
	void draw(HDC hdc, int x, int y) override;
	void onClick(MEvent p) override;
	bool checked_ = false;
};