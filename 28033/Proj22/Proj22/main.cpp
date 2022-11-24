#include <iostream>
#include <exception>
#include "shape.h"
#include "paintframe.h"

// �ϴ��� ���� ���� 1���� ����Ѵ�.
extern PaintFrame* theFrame;

int main() {
	try {
		theFrame = new PaintFrame(L"��ü1������Ʈ2022", 1000,800);
		theFrame->initialize();
		theFrame->run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
