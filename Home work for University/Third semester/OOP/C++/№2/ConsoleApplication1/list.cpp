#include "List.h"

void List::push(Transport* e) { // принимаем животное в зоопарк
	node* r = new node;
	r->inf = e;
	r->next = NULL;
	if (!head && !tail) {
		r->prev = NULL;
		head = r;
	}
	else {
		tail->next = r;
		r->prev = tail;
	}
	tail = r;
	cnt++;
}
void List::print(ostream& out)
{
	node* r = head;
	while (r != NULL) {
		//(*(r->inf)).print(cout);
		out << *(r->inf);
		r = r->next;
	}
	cout << '\n';
}

bool List::find(Transport* e) {
	node* r = head;
	while (r != NULL) {
		if (*(r->inf) == *e)
			return true;
		r = r->next;
	}
	return false;
}

bool List::findAll(bool condition(Transport* e1)) {
	node* r = head;
	while (r != NULL) {
		if (condition(r->inf))
		{
			(*(r->inf)).print(cout);
		}
		r = r->next;
	}
	return (r != NULL);
}