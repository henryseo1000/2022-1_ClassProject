#pragma once
#include "shape.h"
#include "component.h"
class Shape;
class Group {
public:
	Group();
	Group(MPoint& s, MPoint& e);
	bool areyouin(Shape* a);
	void group(Shape* a);
	void setComponent(Component* c);
	MyList<Shape*> slist_;
private:
	Component* b = nullptr;
	MPoint s_;
	MPoint e_;
};