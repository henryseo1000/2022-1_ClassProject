#include <iostream>
#include "paintframe.h"

static int num = 0;
static Shape* unknown[100];

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
	else if(!Frame::eventHandler(e)) {
		end_ = e.getPoint();
		if (findButton(end_) != nullptr) {
			findButton(end_)->onClick(e);
		}
		if (figType_ == 0) {

		}
		else if (figType_ == 1) {
			if (cmdType_ == 0) {
				unknown[num] = new Rect(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
			}
			else {
				unknown[num] = new Rect(hDC_, (start_.x_ + 10) / 20 * 20, (start_.y_ + 10) / 20 * 20, (end_.x_ + 10) / 20 * 20, (end_.y_ + 10) / 20 * 20);
			}
		}
		else if (figType_ == 2) {
			if (cmdType_ == 0) {
				unknown[num] = new Elli(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
			}
			else {
				unknown[num] = new Elli(hDC_, (start_.x_ + 10) / 20 * 20, (start_.y_ + 10) / 20 * 20, (end_.x_ + 10) / 20 * 20, (end_.y_ + 10) / 20 * 20);
			}
		}
		else if (figType_ == 3) {
			if (cmdType_ == 0) {
				unknown[num] = new Line(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
			}
			else {
				unknown[num] = new Line(hDC_, (start_.x_ + 10) / 20 * 20, (start_.y_ + 10) / 20 * 20, (end_.x_ + 10) / 20 * 20, (end_.y_ + 10) / 20 * 20);
			}
		}
		num++;
		//Rectangle(hDC_, start_.x_, start_.y_, end_.x_, end_.y_);
		OutputDebugString(L"Up\n");
		return false;
	}
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
	for (int i = 0; i < numButtons; i++) {
		buttons_[i]->draw(hDC_, 0 + i * buttons_[i]->default_width, 0);
	}
	for (int i = 0; i < num; i++) {
		if (unknown[i] != nullptr) {
			unknown[i]->draw();
		}
	}
}

void PaintFrame::setShape(int t) {
	figType_ = t;
}

void PaintFrame::setCommand(int t) {
	cmdType_ = t;
}