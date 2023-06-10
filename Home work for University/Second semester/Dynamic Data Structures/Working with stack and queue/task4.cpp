#include<iostream>
#include<algorithm>
using namespace std;


struct queue {
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x) {
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		h = t = r;
	}
	else {
		t->next = r;
		t = r;
	}

}

void print(queue*& h) { // печать очереди
	queue* r = h;
	while (r) {
		cout << r->inf << ' ';
		r = r->next;
	}
	cout << endl;
}

int pop(queue*& h, queue*& t) { // удаление элемента из очереди
	queue* r = h; // создаем указатель на голову
	int i = h->inf; // сохраняем значение головы
	h = h->next; // сдвигаем указатель на следующий элемент
	if (!h)
		t = NULL;
	delete r; // удаляем первый элемент
	return i;
}


void result(queue*& h, queue*& t,int posled,int n,int minx) {
	// инициализия очереди
	queue* h1 = NULL;
	queue* t1 = NULL;
	for (int i = 0; i < n; i++) {
		int x = pop(h, t);
		if (x == posled) {
			push(h1, t1, minx);
		}
		push(h1, t1, x);
	}
	h = h1;
	t = t1;
}

int main() {
	int n; // кол-во элементов в стеке
	cout << "n = 11 \n";
	n = 11;
	int minx=INT_MAX;
	queue* head = NULL; // инициализация
	queue* tail = NULL; // инициализация
	int x;
	for (int i = 0; i < n; i++) { // создание стека
		cin >> x;
		minx = min(minx, x);
		push(head, tail, x);
	}
	result(head, tail, x, n, minx); // результат
	print(head);
	return 0;
}