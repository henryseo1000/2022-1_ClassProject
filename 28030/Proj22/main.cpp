
#include "frame.h"
#include <iostream>
#include <exception>
#include "shape.h"

// �ϴ��� ���� ���� 1���� ����Ѵ�.
extern Frame* theFrame ;
int main() {
	try {
		theFrame = new Frame(L"��ü1������Ʈ2022", 1000,800);
		theFrame->run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
