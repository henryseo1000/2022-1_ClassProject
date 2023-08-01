#pragma once
#include <iostream>
using namespace std;

class iterator;
class MyLink;
template <class T>
class MyList {
public:
	MyList() : root(0) {

	}

	void push_back(T a) {
		MyLink* temp = root;
		MyLink* p = new MyLink();
		p->data = a;
		p->next = 0;

		if (root == 0) {
			root = p;
		}
		else {
			while (temp->next) {
				temp = temp->next;
			}
			temp->next = p;
		}
	}

	void push_front(T a) {
		MyLink* p = new MyLink();
		p->data = a;
		p->next = 0;

		MyLink* temp = root;

		root = p;
		root->next = temp;
	}

	void print() {
		MyLink* p = root;
		while (p) {
			cout << p->data << endl;
			p = p->next;
		}
	}

	class MyLink {
	public:
		T data;
		MyLink* next;
		MyLink* prev;
		MyLink() :next(0) {

		}
	};

	class iterator {
	public:
		iterator() {

		}
		iterator(MyLink* p) {
			ptr_ = p;
		}
		bool hasNext() {
			return ptr_ != nullptr;
		}
		void toNext() {
			ptr_ = ptr_->next;
		}
		T getContent() {
			return ptr_->data;
		}
		MyLink* ptr_;
	};

	class reverse_iterator {

	};
	iterator begin() {
		return iterator(root);
	}

private:
	MyLink* root = 0;
};