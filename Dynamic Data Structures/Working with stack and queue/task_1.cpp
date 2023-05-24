#include<iostream>

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


void result(queue*& h, queue*& t) {
	// инициализия очереди
	queue* h1 = NULL;
	queue* t1 = NULL;

	queue* h2 = NULL;
	queue* t2 = NULL;

	int per_stek = 0;
	int per_nechet = 0;
	
	while (h && t) {
		int x = pop(h, t);
		if (x % 2 != 0) {
			if (x > per_stek) {
				per_stek = x;
			}
			
		}
		push(h1, t1, x);
	}


//   2 4 6 5 1 4 5 3 4 5 2 1
	h = h1;
	t = t1; // передаём указатели

	h1 = NULL;// обнуление очереди h1
	t1 = NULL;

	while (h && t) {
		int x = pop(h, t); // удаление элемента
		if ((x != per_stek) && (per_nechet == 0)){
			push(h1, t1, x); // записываю в очередь h1 все элементы до нечетного
		}
		if (x == per_stek) { // встретится нечёт 
			per_nechet = 1;
		}
		if (per_nechet == 1) {
			push(h2, t2, x); // запись в очередь h2 элементов после нечётного включительно
		}

	}
	while (h1 && t1) {
		int x = pop(h1, t1); // удаление элемента
		push(h2, t2, x); // записываем в результат
	}
	h = h2;
	t = t2;



}

int main() {
	int n; // кол-во элементов в стеке
	cout << "n = 12 \n";
	n = 12;
	queue* head = NULL; // инициализация
	queue* tail = NULL; // инициализация
	int x;
	for (int i = 0; i < n; i++) { // создание стека
		cin >> x;
		push(head, tail, x);
	}
	result(head, tail); // результат
	print(head);
	return 0;
}