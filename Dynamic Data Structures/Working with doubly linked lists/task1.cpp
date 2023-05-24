#include<iostream>

using namespace std;


struct list {
	int inf;
	list *next;
	list* prev;
};

void push(list*& h, list*& t, int x) {
	list *r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list *h, list *t) {
	list* p = h;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
}

list* find(list* h, list* t, int x) { //печать элементов списка
	 list * p = h; //укзатель на голову
	 while (p) { //пока не дошли до конца списка
		 if (p->inf == x) break; // если нашли, прекращаем цикл
		 p = p -> next; //переход к следующему элементу
		
	}
	 return p; //возвращаем указатель
	
}


void del_node(list*& h, list*& t, list* r) {
	if (r == h && r == t)
		h = t = NULL;
	else if (r == h) {
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}

void del_list(list * &h, list * &t) { //удаляем список
	while (h) { //пока список не пуст
		list * p = h; //указатель на голову
		h = h-> next; //переносим голову
		h -> prev = NULL; //обнуляем
		delete p; //удаляем p
		
	}
	
}
void reverse_v1(list* head, list* tail)
{
	list* p = head->next;
	while (p != tail)
	{
		list* next = p->next;

		swap(p->next, p->prev);

		//Переходим к следующему узлу
		p = next;
	}
	swap(head->next, tail->prev);
	swap(head->next->prev, tail->prev->next);
}

int main() {
	setlocale(LC_ALL, "RUS");
	int n; cin >> n;  ///12
	list* head = NULL;
	list* tail = NULL;
	int x;
	int per_chet=0;
	int lst_chet=0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(head, tail, x);
		if (x % 2 == 0) {
			lst_chet = x;
		}
		if (x % 2 == 0 && per_chet==0) {
			per_chet = x;
		}
	}
	del_node(head, tail, find(head, tail, per_chet));
	reverse_v1(head, tail);
	del_node(head, tail, find(head, tail, lst_chet));
	reverse_v1(head, tail);
	print(head, tail);
	cout << endl;

}