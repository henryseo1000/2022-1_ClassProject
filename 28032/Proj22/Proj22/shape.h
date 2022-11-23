#pragma once
#include <Windows.h>

class Shape {
public :
	Shape(HDC hdc, int x, int y, int x_, int y_);
	virtual void draw() = 0;
protected :
	int x1_ = 0, y1_ = 0, x2_ = 0, y2_ = 0;
	HDC hdc_;
};

class Rect : public Shape{
public :
	Rect(HDC hdc, int x, int y, int x_, int y_);
	void draw() override;
};

class Elli : public Shape {
public :
	Elli(HDC hdc, int x, int y, int x_, int y_);
	void draw() override;
};

class Line : public Shape {
public :
	Line(HDC hdc, int x, int y, int x_, int y_);
	void draw() override;
};