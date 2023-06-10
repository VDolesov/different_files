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

void print(queue*& h) { // ������ �������
	queue* r = h;
	while (r) {
		cout << r->inf << ' ';
		r = r->next;
	}
	cout << endl;
}

int pop(queue*& h, queue*& t) { // �������� �������� �� �������
	queue* r = h; // ������� ��������� �� ������
	int i = h->inf; // ��������� �������� ������
	h = h->next; // �������� ��������� �� ��������� �������
	if (!h)
		t = NULL;
	delete r; // ������� ������ �������
	return i;
}


void result(queue*& h, queue*& t,int posled,int n,int minx) {
	// ����������� �������
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
	int n; // ���-�� ��������� � �����
	cout << "n = 11 \n";
	n = 11;
	int minx=INT_MAX;
	queue* head = NULL; // �������������
	queue* tail = NULL; // �������������
	int x;
	for (int i = 0; i < n; i++) { // �������� �����
		cin >> x;
		minx = min(minx, x);
		push(head, tail, x);
	}
	result(head, tail, x, n, minx); // ���������
	print(head);
	return 0;
}