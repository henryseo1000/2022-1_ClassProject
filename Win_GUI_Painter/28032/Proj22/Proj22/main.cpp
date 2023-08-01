#include <iostream>
#include <exception>
#include "shape.h"
#include "paintframe.h"

// 일단은 전역 변수 1개는 사용한다.
extern PaintFrame* theFrame;

int main() {
	try {
		theFrame = new PaintFrame(L"객체1프로젝트2022", 1000,800);
		theFrame->initialize();
		theFrame->run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
