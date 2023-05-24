//АВЛ - дерево с операциями вставки и удаления узла
#include <iostream>
using namespace std;

struct tree { // структура дерева
	int inf;      // ключ узла
	tree* left;   // указатель на левого ребенка
	tree* right;  // указатель на правого ребенка
	int height;   // высота поддерева с корнем в данном узле
};

tree* node(int x) { // начальный узел
	tree* n = new tree;
	n->inf = x;
	n->right = n->left = NULL;
	n->height = 1;
	return n;
}

int height(tree* tr) {   //высота узла
	if (tr) return tr->height;
	return 0;
}

int bfactor(tree* tr) {  //разница высот (правое - левое) поддерево
	return height(tr->right) - height(tr->left);
}

void fixheight(tree* tr) {  //пересчет высот узлов
	int h_left = height(tr->left);
	int h_right = height(tr->right);
	tr->height = max(h_left, h_right) + 1;
}

tree* rotateright(tree* p) { // правый поворот вокруг p
	tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

tree* rotateleft(tree* q) {  // левый поворот вокруг q
	tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

tree* balance(tree* p) {   // балансировка узла p
	fixheight(p);
	//Если после выполнения операции добавления или удаления,
	//коэффициент сбалансированности какого-либо узла АВЛ-дерева становиться равен по модулю 2
	//то нужна балансировка
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0) //если баланс правого ребенка отрицательный (== -1)
			p->right = rotateright(p->right); //то делаем большой левый поворот,
		return rotateleft(p); // а иначе только малый левый поворот
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

tree* insert(tree* p, int k) {    // вставка ключа k в дерево с корнем p
	if (!p) return node(k);
	if (k < p->inf)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

tree* findmax(tree* p) // поиск узла с максимальным ключом в дереве p 
{
	if (!p->right) return p;	   // если нет правого потомка, возвращаем указатель на узел
	else return findmax(p->right); // иначе идем по правой ветке до конца
}

tree* remove(tree* p, int k) {  // удаление ключа k из дерева p
	if (!p)
		return p;

	if (k < p->inf)
		p->left = remove(p->left, k);

	else if (k > p->inf)
		p->right = remove(p->right, k);

	else {
		tree* tr;
		if (!p->left && !p->right) { // если нет детей
			tr = p;
			p = NULL;
		}
		else if (!p->left || !p->right) { // если есть дети
			if (p->right) { // если есть только правый ребенок
				tr = p->right;
				p->inf = tr->inf;
				tr = remove(p->right, tr->inf);
			}
			else { // если есть только левый ребенок
				tr = p->left;
				p->inf = tr->inf;
				tr = remove(p->left, tr->inf);
			}
		}
		else { // если есть оба ребенка
			tr = findmax(p->left);
			p->inf = tr->inf;
			p->left = remove(p->left, tr->inf);
		}
	}
	if (!p) return p;
	return balance(p);
}


void preorder(tree* tr) {  // прямой обход
	if (tr != NULL) {
		cout << tr->inf << ' ' << "height: " << tr->height << endl; // корень
		preorder(tr->left); // левое
		preorder(tr->right); // правое
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, x, del_node;

	cout << "n: ";
	cin >> n; // ввод количества элементов
	tree* root = NULL;
	for (int i = 0; i < n; i++) { // заполняем дерево
		cin >> x;
		root = insert(root, x);
	}
	cout << "Прямой обход: \n";
	preorder(root);

	cout << "\nВведите элемент для удаления: ";
	cin >> del_node;
	remove(root, del_node);

	cout << "Прямой обход: \n";
	preorder(root);

	cout << "\nВведите элемент для удаления: ";
	cin >> del_node;
	remove(root, del_node);

	cout << "Прямой обход: \n";
	preorder(root);
}
