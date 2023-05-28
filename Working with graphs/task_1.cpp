//Дан ориентированный граф. Вывести количество вершин, смежных с данной.
#include <iostream>
#include <sstream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void fillGraph(vector<vector<int>>& gr, int n) { //ориентированный граф
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
	int n = 7;
	int X, k = 0;
	cout << "Х = ";
	cin >> X;
	fillGraph(gr, n);
	print(gr, n);
	if (X >= n || X < 0)
	{
		cout << "Такой вершины в графе нет." << endl;
	}
	else
	{
		cout << "Количество смежных вершин с вершиной Х: " << gr[X].size() << " " << endl;
	}
	return 0;
}