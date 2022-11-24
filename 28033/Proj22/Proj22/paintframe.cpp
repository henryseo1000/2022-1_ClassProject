#include <iostream>
#include "paintframe.h"
#include "C:\Users\henry\OneDrive - �������б�\���� ȭ��\28033\Proj22\Project1\List.h"
#include "C:\Users\henry\OneDrive - �������б�\���� ȭ��\28033\Proj22\Project1\frame.h"

static MyList<Shape*> unknown;

MyList<Shape*>::iterator j;

PaintFrame::PaintFrame() : Frame(L"", 800, 600){

}
PaintFrame::PaintFrame(std::wstring title, int width, int height) : Frame(title, width, height) {

}

bool PaintFrame::eventHandler(MEvent e)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	OutputDebugString(L"Event\n");
	std::cout << L"Event\n" << std::endl;  // ����� cmd â���� ���

	// �̺�Ʈ�� ������ �ľ��ؼ� �簢�� �׸��⸦ ���⼭ ���ش�.
	if (Frame::eventHandler(e)) {
		start_ = e.getPoint();
		OutputDebugString(L"Down\n");
		return true;
	}

	else if (!Frame::eventHandler(e) && e.isLButtonUpEvent()) {
		end_ = e.getPoint();
		if (findButton(end_) != nullptr) {
			findButton(end_)->onClick(e);
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
		num++;
		//Rectangle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		OutputDebugString(L"Up\n");
		return true;
	}
	return true;
}

void PaintFrame::repaint() {
	drawButtons();
}

void PaintFrame::initialize() {
	MButton* b1 = new MButton("�簢��");
	MButton* b2 = new MButton("Ÿ��");
	MButton* b3 = new MButton("����");
	checkbox* c1 = new checkbox("�׸��忡 ����");

	c1->setFrame(this);
	b1->setFrame(this);
	b2->setFrame(this);
	b3->setFrame(this);

	b1->setCommand(FIG_RECT);
	b2->setCommand(FIG_ELLI);
	b3->setCommand(FIG_LINE);

	addButton(b1);
	addButton(b2);
	addButton(b3);
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

void PaintFrame::setGrid(bool c) {
	toGrid = c;
}