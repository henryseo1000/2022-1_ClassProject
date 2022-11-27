#include "group.h"
#include "Misc.h"
Group::Group() {

}

Group::Group(MPoint s, MPoint e) {
	s_ = s;
	e_ = e;
}

bool Group::areyouin(Shape * a) {
	if (s_.x_ < a->x1_ && s_.y_ > a->y1_ && e_.x_ > a->x2_ && e_.y_ < a->y2_) {
		return true;
	}
	return false;
}

void Group::group(Shape* a) {
	slist_.push_back(a);
}

void Group::setComponent(Component* c) {
	b = c;
}