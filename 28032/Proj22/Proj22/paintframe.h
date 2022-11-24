#pragma once
#include "frame.h"

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
};