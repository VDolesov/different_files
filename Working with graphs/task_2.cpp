//��� ����������������� ����. ������� �����, ����������� ������� � � B.
#include <iostream>
#include <sstream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void fillGraph(vector<vector<int>>& gr, int n) { //����������������� ����
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
	int n = 8;
	int x = 0;
	int A;
	int B;
	fillGraph(gr, n);
	print(gr, n);
	
	cout << "\n������� A: ";
	cin >> A;
	cout << "������� B: ";
	cin >> B;
	cout << endl;

	for (int i = 0; i < n; ++i) //������� ����� ����� A � B
	{
		for (int j = 0; j < gr[i].size(); ++j)
		{
			if (i == B && gr[i][j] == A || i == A && gr[i][j] == B)
			{
				gr[i].erase(gr[i].begin() + j);
			}
		}
	}
	print(gr, n);
	return 0;
}