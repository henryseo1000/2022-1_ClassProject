#include <iostream>
#include "paintframe.h"
#include "List.h"
#include "frame.h"
#include "group.h"

static MyList<Shape*> unknown;
MyList<Shape*>::iterator j;
MyList<Group*>::iterator l;
MyList<Shape*>::reverse_iterator k;

PaintFrame::PaintFrame() : Frame(L"", 800, 600){

}
PaintFrame::PaintFrame(std::wstring title, int width, int height) : Frame(title, width, height) {

}

bool PaintFrame::eventHandler(MEvent e)
{
	// TODO: 여기에 구현 코드 추가.
	OutputDebugString(L"Event\n");
	std::cout << L"Event\n" << std::endl;  // 여기는 cmd 창으로 출력

	// 이벤트의 종류를 파악해서 사각형 그리기를 여기서 해준다.
	if (Frame::eventHandler(e)) {
		start_ = e.getPoint();
		OutputDebugString(L"Down\n");
		return true;
	}

	else if (e.isLButtonUpEvent() && e.isCtrlKeyDown()) {
		Shape* s;
		end_ = e.getPoint();
		if ((s = findShape(start_)) != nullptr) {
			if (s->group_ != nullptr) {
				for (j = (s->group_->slist_).begin(); j.hasNext(); j.toNext()) {
					if (j.getContent() != nullptr) {
						moveShape(j.getContent(), start_, end_);
					}
				}
			}
			else {
				moveShape(s, start_, end_);
			}
		}
		invalidate();
		return true;
	}

	else if (e.isLButtonUpEvent() && !e.isCtrlKeyDown()) {
		end_ = e.getPoint();
		if (findButton(end_) != nullptr) {
			findButton(end_)->onClick(e);
			if (figType_ == 4) {
				gnum = 0;
			}
		}
		if (figType_ == 0) {

		}
		else if (figType_ == 1) {
			if (cmdType_ == 0) {
				Shape* R = new Rect(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
				unknown.push_back(R);
			}
			else {
				Shape* R = new Rect(hDC_, (start_.x_ + 10) / 20 * 20, (start_.y_ + 10) / 20 * 20, (end_.x_ + 10) / 20 * 20, (end_.y_ + 10) / 20 * 20);
				unknown.push_back(R);
			}
		}
		else if (figType_ == 2) {
			if (cmdType_ == 0) {
				Shape* R = new Elli(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
				unknown.push_back(R);
			}
			else {
				Shape* R = new Elli(hDC_, (start_.x_ + 10) / 20 * 20, (start_.y_ + 10) / 20 * 20, (end_.x_ + 10) / 20 * 20, (end_.y_ + 10) / 20 * 20);
				unknown.push_back(R);
			}
		}
		else if (figType_ == 3) {
			if (cmdType_ == 0) {
				Shape* R = new Line(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
				unknown.push_back(R);
			}
			else {
				Shape* R = new Line(hDC_, (start_.x_ + 10) / 20 * 20, (start_.y_ + 10) / 20 * 20, (end_.x_ + 10) / 20 * 20, (end_.y_ + 10) / 20 * 20);
				unknown.push_back(R);
			}
		}
		else if (figType_ == 4) {
			if (gnum <= 1) {
				Group* g = new Group(start_, end_);
				g_.push_back(g);
				findShape(g);
				gnum++;
			}
			else {
				figType_ = 0;
			}
		}
		//Rectangle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		OutputDebugString(L"Up\n");
	}
	return true;
}

void PaintFrame::repaint() {
	drawButtons();
}

void PaintFrame::initialize() {
	MButton* b1 = new MButton("사각형");
	MButton* b2 = new MButton("타원");
	MButton* b3 = new MButton("선분");
	MButton* b4 = new MButton("그룹화");
	checkbox* c1 = new checkbox("그리드에 맞춤");

	c1->setFrame(this);
	b1->setFrame(this);
	b2->setFrame(this);
	b3->setFrame(this);
	b4->setFrame(this);

	b1->setCommand(FIG_RECT);
	b2->setCommand(FIG_ELLI);
	b3->setCommand(FIG_LINE);
	b4->setCommand(4);

	addButton(b1);
	addButton(b2);
	addButton(b3);
	addButton(b4);
	addButton(c1);
}

void PaintFrame::drawButtons() {
	Frame::drawButtons();
	for (j = unknown.begin(); j.hasNext(); j.toNext()) {
		if (j.getContent() != nullptr) {
			j.getContent()->draw();
		}
	}
}

void PaintFrame::setCommand(int t) {
	cmdType_ = t;
}

/*void PaintFrame::setGrid(bool c) {
	toGrid = c;
}*/

void PaintFrame::setGroup(MPoint s, MPoint e) {
	Group* g = new Group(s, e);
	g_.push_front(g);
}

void PaintFrame::findShape(Group* g) {
	for (j = unknown.begin(); j.hasNext(); j.toNext()) {
			if (g->areyouin(j.getContent())) {
				g->group(j.getContent());
				unknown.remove(j.getContent());
				j.getContent()->setGroup(g);
			}
	}
}

Shape * PaintFrame::findShape(MPoint m) {
	for (k = unknown.end(); k.hasPrev(); k.toPrev()) {
		if (k.getContent() != nullptr && k.getContent()->includes(m)) {
			return k.getContent();
		}
	}
	return nullptr;
}

void PaintFrame::moveShape(Shape * sh, MPoint s, MPoint e) {
	sh->x1_ = sh->x1_ + (e.x_ - s.x_);
	sh->y1_ = sh->y1_ + (e.y_ - s.y_);
	sh->x2_ = sh->x2_ + (e.x_ - s.x_);
	sh->y2_ = sh->y2_ + (e.y_ - s.y_);
}