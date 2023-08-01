#pragma once
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

	private:
		MyLink() :next(0) {

		}
	};

	class iterator {

	};

	class reverse_iterator {

	};
private:
	MyLink* root = 0;
};