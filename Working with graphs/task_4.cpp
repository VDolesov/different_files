//��� ����������������� ����. ��������, �������� �� ���� �������.
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

void stack_push(stack *& h, int x) { //�������� ������� � ������ �����
	stack * r = new stack; //������� ����� ������� 
	r->inf = x; //���� inf = x  
	r->next = h; //��������� ��������� �������� h 
	h = r; //������ r �������� ������� 6 
}

int stack_pop(stack *& h) { //������� ������� �� ����� � ������� ��� ��������
	int i = h->inf; //�������� ������� ��������  
	stack* r = h; //��������� �� ������ ����� 
	h = h->next; //��������� ��������� �� ��������� ������� 
	delete r; //������� ������ ������� 
	return i; //���������� ��������
}

void fillGraph(vector<vector<int>>& gr, int n) { //����������������� �����
	gr.resize(n);
	cout << "������� ������ ��������� ��� ������ \n";
	for (int i = 0; i < n; ++i)
	{
		int z;
		cout << "���������� ������� ������ ��� ���� " << i << ": ";
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

int dfs(vector<vector<int>>& gr) { //����� � �������
	vector<int> a(gr.size(), 0); //������ ���������� ������
	int k = 0; //���-�� ���������� ������
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

void print(vector<vector<int>>& gr, int n) { //����� �����
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
	if (dfs(gr) == n) //���� ���-�� ���������� ������ ����� ���-�� ������ � �����
	{
		cout << "���� �������� �������";
	}
	else
	{
		cout << "���� �� �������� �������";
	}
	cout << endl;
	return 0;
}