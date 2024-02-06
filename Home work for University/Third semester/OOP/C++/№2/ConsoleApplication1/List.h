#pragma once

#include "Transport.h"

struct node {
	Transport* inf;
	node* next;
	node* prev;
};

class List {
private:
	node* head;
	node* tail;
	int cnt;
public:
	List() { head = NULL; tail = NULL; cnt = 0; }
	void push(Transport* p);
	void print(ostream& out);
	bool find(Transport* p);

	bool findAll(bool condition(Transport* p1));

	int getCnt() { return cnt; }

	node* operator[](const int index) {
		node* tmp = head;
		int i = 0;
		while (tmp != NULL && i < index) {
			i++;
			tmp = tmp->next;
		};
		return tmp;
	}
};