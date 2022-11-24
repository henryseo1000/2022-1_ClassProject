#include <iostream>
#include <Windows.h>
#include "shape.h"

Shape::Shape(HDC hdc, int x, int y, int x_, int y_) {
	hdc_ = hdc;
	x1_ = x;
	y1_ = y;
	x2_ = x_;
	y2_ = y_;
}
Rect::Rect(HDC hdc, int x, int y, int x_, int y_) : Shape(hdc, x, y, x_, y_) {

}
void Rect::draw() {
	Rectangle(hdc_, x1_, y1_, x2_, y2_);
}
Elli::Elli(HDC hdc, int x, int y, int x_, int y_) : Shape(hdc, x, y, x_, y_) {

}
void Elli::draw() {
	Ellipse(hdc_, x1_, y1_, x2_, y2_);
}
Line::Line(HDC hdc, int x, int y, int x_, int y_) : Shape(hdc, x, y, x_, y_) {

}
void Line::draw() {
	MoveToEx(hdc_, x1_, y1_, NULL);
	LineTo(hdc_, x2_, y2_);
}