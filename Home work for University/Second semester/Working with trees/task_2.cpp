// Дано дерево. Вывести путь от узла A до узла B
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct tree { //дерево
	int inf;
	tree* right;
	tree* left;
	tree* parent;
};

tree* node(int x) { //начальный узел
	tree* n = new tree;
	n->inf = x;
	n->left = n->right = NULL;
	n->parent = NULL;
	return n;
}

void insert(tree*& tr, int x) { //вставка
	tree* n = node(x);
	if (!tr)
		tr = n; //если дерево пустое - корень
	else {
		tree* y = tr;
		while (y) { //ищем место для вставки
			if (n->inf > y->inf) //правая ветка
				if (y->right)
					y = y->right;
				else {
					n->parent = y; //узел становится правым ребенком
					y->right = n;
					break;
				}
			else if (n->inf < y->inf) //левая ветка
				if (y->left)
					y = y->left;
				else {
					n->parent = y; //узел становится левым ребенком
					y->left = n;
					break;
				}
		}
	}
}

void preorder(tree* tr) { //прямой обход
	if (tr) {
		preorder(tr->left);
		cout << tr->inf << ' ';
		preorder(tr->right);
	}
}

tree* find_a(tree* tr, int a, vector<int> &t) { //поиск
	if (!tr || a == tr->inf) { //нашли или дошли до конца ветки
		t.push_back(tr->inf); //запоминаем значение узла
		return tr;
	}
	if (a < tr->inf) {
		t.push_back(tr->inf); //запоминаем значение узла
		return find_a(tr->left, a, t); //ищем по левой ветке
	}
	else {
		t.push_back(tr->inf); //запоминаем значение узла
		return find_a(tr->right, a, t); //ищем по правой ветке
	}
}

tree* find_b(tree* tr, int b, vector<int>& t) { //поиск
	if (!tr || b == tr->inf) { //нашли или дошли до конца ветки
		t.push_back(tr->inf); //запоминаем значение узла
		return tr;
	}
	if (b < tr->inf) {
		t.push_back(tr->inf); //запоминаем значение узла
		return find_b(tr->left, b, t); //ищем по левой ветке
	}
	else {
		t.push_back(tr->inf); //запоминаем значение узла
		return find_b(tr->right, b, t); //ищем по правой ветке
	}
}

void p(tree*& tr, int a, int b, int n) {
	vector<int> t;
	if (find_a(tr, a, t) && find_b(tr, b, t)) { //если мы нашли нужный узел
		for (int i = 3; i < t.size(); i++) //выводим путь от узла А до узла В
			cout << t[i] << ' ';
		cout << endl;
	}
	else cout << "Узла A или узла B нет" << endl;
}

int main() {
	int n, x, a, b;
	cout << "n = ";
	cin >> n;
	cout << "A = ";
	cin >> a;
	cout << "B = ";
	cin >> b;
	tree* tr = NULL;
	for (int i = 0; i < n; i++) { //заполняем дерево
		cin >> x;
		insert(tr, x);
	}
	p(tr, a, b, n); //вызываем функцию пути от узла А до узла В
	return 0;
}