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
			p->prev = root;
			root = p;
		}
		else {
			while (temp->next) {
				temp = temp->next;
			}
			p->prev = temp;
			temp->next = p;
		}
	}

	void push_front(T a) {
		MyLink* p = new MyLink();
		p->data = a;
		p->next = 0;
		p->prev = root;

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

	void remove(T d) {
		MyLink* p = root;
		MyLink* temp;
		while (root->data != d) {
			root = root->next;
		}
		temp = root;
		root = temp->next;
		root = p;
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

		MyLink* ptr_ = 0;
	};

	class reverse_iterator {
	public:
		reverse_iterator() {

		}
		reverse_iterator(MyLink* p) {
			rptr_ = p;
		}
		bool hasPrev() {
			return rptr_ -> prev != nullptr;
		}
		void toPrev() {
			rptr_ = rptr_->prev;
		}
		T getContent() {
			return rptr_->data;
		}

		MyLink* rptr_ = 0;
	};

	iterator begin() {
		return iterator(root);
	}

	reverse_iterator end() {
		MyLink* temp = root;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		return reverse_iterator(temp);
	}

	T operator[](int num) {
		MyLink* p = root;
		while (num) {
			p = p->next;
			num--;
		}
		return p->data;
	}

private:
	MyLink* root = 0;
};