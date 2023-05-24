//��� - ������ � ���������� ������� � �������� ����
#include <iostream>
using namespace std;

struct tree { // ��������� ������
	int inf;      // ���� ����
	tree* left;   // ��������� �� ������ �������
	tree* right;  // ��������� �� ������� �������
	int height;   // ������ ��������� � ������ � ������ ����
};

tree* node(int x) { // ��������� ����
	tree* n = new tree;
	n->inf = x;
	n->right = n->left = NULL;
	n->height = 1;
	return n;
}

int height(tree* tr) {   //������ ����
	if (tr) return tr->height;
	return 0;
}

int bfactor(tree* tr) {  //������� ����� (������ - �����) ���������
	return height(tr->right) - height(tr->left);
}

void fixheight(tree* tr) {  //�������� ����� �����
	int h_left = height(tr->left);
	int h_right = height(tr->right);
	tr->height = max(h_left, h_right) + 1;
}

tree* rotateright(tree* p) { // ������ ������� ������ p
	tree* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

tree* rotateleft(tree* q) {  // ����� ������� ������ q
	tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

tree* balance(tree* p) {   // ������������ ���� p
	fixheight(p);
	//���� ����� ���������� �������� ���������� ��� ��������,
	//����������� ������������������ ������-���� ���� ���-������ ����������� ����� �� ������ 2
	//�� ����� ������������
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0) //���� ������ ������� ������� ������������� (== -1)
			p->right = rotateright(p->right); //�� ������ ������� ����� �������,
		return rotateleft(p); // � ����� ������ ����� ����� �������
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // ������������ �� �����
}

tree* insert(tree* p, int k) {    // ������� ����� k � ������ � ������ p
	if (!p) return node(k);
	if (k < p->inf)
		p->left = insert(p->left, k);
	else
		p->right = insert(p->right, k);
	return balance(p);
}

tree* findmax(tree* p) // ����� ���� � ������������ ������ � ������ p 
{
	if (!p->right) return p;	   // ���� ��� ������� �������, ���������� ��������� �� ����
	else return findmax(p->right); // ����� ���� �� ������ ����� �� �����
}

tree* remove(tree* p, int k) {  // �������� ����� k �� ������ p
	if (!p)
		return p;

	if (k < p->inf)
		p->left = remove(p->left, k);

	else if (k > p->inf)
		p->right = remove(p->right, k);

	else {
		tree* tr;
		if (!p->left && !p->right) { // ���� ��� �����
			tr = p;
			p = NULL;
		}
		else if (!p->left || !p->right) { // ���� ���� ����
			if (p->right) { // ���� ���� ������ ������ �������
				tr = p->right;
				p->inf = tr->inf;
				tr = remove(p->right, tr->inf);
			}
			else { // ���� ���� ������ ����� �������
				tr = p->left;
				p->inf = tr->inf;
				tr = remove(p->left, tr->inf);
			}
		}
		else { // ���� ���� ��� �������
			tr = findmax(p->left);
			p->inf = tr->inf;
			p->left = remove(p->left, tr->inf);
		}
	}
	if (!p) return p;
	return balance(p);
}


void preorder(tree* tr) {  // ������ �����
	if (tr != NULL) {
		cout << tr->inf << ' ' << "height: " << tr->height << endl; // ������
		preorder(tr->left); // �����
		preorder(tr->right); // ������
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, x, del_node;

	cout << "n: ";
	cin >> n; // ���� ���������� ���������
	tree* root = NULL;
	for (int i = 0; i < n; i++) { // ��������� ������
		cin >> x;
		root = insert(root, x);
	}
	cout << "������ �����: \n";
	preorder(root);

	cout << "\n������� ������� ��� ��������: ";
	cin >> del_node;
	remove(root, del_node);

	cout << "������ �����: \n";
	preorder(root);

	cout << "\n������� ������� ��� ��������: ";
	cin >> del_node;
	remove(root, del_node);

	cout << "������ �����: \n";
	preorder(root);
}
