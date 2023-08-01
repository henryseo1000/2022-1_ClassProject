#pragma once
#include "frame.h"
#include "shape.h"

class PaintFrame : public Frame{
public:
	PaintFrame();
	PaintFrame(std::wstring title, int width, int height);
	bool eventHandler(MEvent e) override;
	void repaint() override;
	void initialize() override;
	void drawButtons();
	void setCommand(int t);
	void setGrid(bool c);

	bool toGrid;
	int num = 0;
};