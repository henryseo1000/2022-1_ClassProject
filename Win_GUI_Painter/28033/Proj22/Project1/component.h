#pragma once
#include <string>
#include "Misc.h"
#include "frame.h"
using namespace std;

class Frame;
class Component{
public:
	Component();
	Component(string s, int x, int y, int width, int height);
	Component(string s);
	//bool includes(int x, int y);
	bool includes(MPoint p);
	void setx(int x);
	int getHeight();
	int getWidth();
	virtual void draw(HDC hdc, int x, int y);
	virtual void onClick(MEvent p);
	virtual void setCommand(int a);
	void setFrame(Frame* f);

	static const int default_height = 30;
	static const int default_width = 200;

	int x_ = 0;
	int y_ = 0;
	int width_ = default_width;
	int height_ = default_height;
	string name_;
	Frame* f_ = nullptr;
	int Command_ = 0;
};

class MButton : public Component {
public:
	MButton(string s, int x, int y, int width, int height);
	MButton(string s);
	//bool includes(int x, int y);
	void draw(HDC hdc, int x, int y) override;
	void onClick(MEvent p) override;
	void setCommand(int a) override;
	
};

class checkbox : public Component {
public:
	checkbox(string s, int x, int y, int width, int height);
	checkbox(string s);
	//bool includes(int x, int y);
	void draw(HDC hdc, int x, int y) override;
	void onClick(MEvent p) override;
	void setCommand(int a) override;
	bool checked_ = false;
};