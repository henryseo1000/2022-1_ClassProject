#pragma once
#include "C:\Users\henry\OneDrive - 명지대학교\바탕 화면\28033\Proj22\Project1\frame.h"
#include "shape.h"

class PaintFrame : public Frame{
public:
	PaintFrame();
	PaintFrame(std::wstring title, int width, int height);
	bool eventHandler(MEvent e) override;
	void repaint() override;
	void initialize() override;
	void drawButtons();
	void setShape(int t) override;
	void setCommand(int t);
	void setGrid(bool c);

	bool toGrid;
	int num = 0;
};