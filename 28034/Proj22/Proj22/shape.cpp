#include <iostream>
#include <Windows.h>
#include "shape.h"
#include "component.h"

//Shape 
Shape::Shape(HDC hdc, int x, int y, int x_, int y_) {
	hdc_ = hdc;
	x1_ = x;
	y1_ = y;
	x2_ = x_;
	y2_ = y_;
}

void Shape::setGroup(Group* g) {
	group_ = g;
}

bool Shape::includes(MPoint p) { 
	if (p.x_ > x1_ && p.y_ > y1_ && p.x_ < x2_ && p.y_ < y2_) {
		return true;
	}
	return false;
}

//Rect
Rect::Rect(HDC hdc, int x, int y, int x_, int y_) : Shape(hdc, x, y, x_, y_) {

}
void Rect::draw() {
	Rectangle(hdc_, x1_, y1_, x2_, y2_);
}

//Elli
Elli::Elli(HDC hdc, int x, int y, int x_, int y_) : Shape(hdc, x, y, x_, y_) {

}
void Elli::draw() {
	Ellipse(hdc_, x1_, y1_, x2_, y2_);
}

//Line
Line::Line(HDC hdc, int x, int y, int x_, int y_) : Shape(hdc, x, y, x_, y_) {

}
void Line::draw() {
	MoveToEx(hdc_, x1_, y1_, NULL);
	LineTo(hdc_, x2_, y2_);
}
