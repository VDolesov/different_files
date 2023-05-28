//Дан неориентированный граф. Выяснить, является ли граф связным.
#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
using namespace std;

struct stack {
	int inf;
	stack *next;
};

void stack_push(stack *& h, int x) { //Добавить элемент в начало стека
	stack * r = new stack; //создаем новый элемент 
	r->inf = x; //поле inf = x  
	r->next = h; //следующим элементов является h 
	h = r; //теперь r является головой 6 
}

int stack_pop(stack *& h) { //Удалить элемент из стека и вернуть его значение
	int i = h->inf; //значение первого элемента  
	stack* r = h; //указатель на голову стека 
	h = h->next; //переносим указатель на следующий элемент 
	delete r; //удаляем первый элемент 
	return i; //возвращаем значение
}

void fillGraph(vector<vector<int>>& gr, int n) { //неориентированный графа
	gr.resize(n);
	cout << "Введите список смежности для вершин \n";
	for (int i = 0; i < n; ++i)
	{
		int z;
		cout << "Количество смежных вершин для узла " << i << ": ";
		cin >> z;
		gr[i].resize(z);
		for (int j = 0; j < z; ++j)
		{
			int t;
			cout << "gr[" << i << "][" << j << "]: ";
			cin >> t;
			gr[i][j] = t;
		}

	}
}

int dfs(vector<vector<int>>& gr) { //обход в глубину
	vector<int> a(gr.size(), 0); //вектор посещенных вершин
	int k = 0; //кол-во посещённых вершин
	for (int i = 0; i < gr.size(); ++i)
	{
		if (a[i] == 0)
		{
			k++;
			stack *gr_stack = NULL;
			a[i] = 1;
			stack_push(gr_stack, i);

			while (gr_stack) {
				bool flag = false;
				int z = gr_stack->inf;
				int y = 0;
				for (int j = 0; j < gr[z].size(); ++j)
				{
					if (a[gr[z][j]] == 0)
					{
						flag = true;
						a[gr[z][j]] = 1;
						k++;
						stack_push(gr_stack, gr[z][j]);
						break;
					}
				}
				if (!flag)
				{
					stack_pop(gr_stack);
				}
			}
		}
	}
	return k;
}

void print(vector<vector<int>>& gr, int n) { //вывод графа
	for (int i = 0; i < n; ++i)
	{
		cout << "[ " << i << "]: ";
		for (auto it = gr[i].begin(); it != gr[i].end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<vector<int>> gr;
	int n;
	cout << "n = ";
	cin >> n;
	fillGraph(gr, n);
	print(gr, n);
	cout << endl;
	if (dfs(gr) == n) //если кол-во посещённых вершин равно кол-ву вершин в графе
	{
		cout << "Граф является связным";
	}
	else
	{
		cout << "Граф не является связным";
	}
	cout << endl;
	return 0;
}