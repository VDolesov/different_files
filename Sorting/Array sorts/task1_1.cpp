#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
void quicksort(int**& a, int l, int r,int noc) {//будем сортировать столбцы массива быстрой сортировкой
	int i = l;
	int j = r;
	int pil = a[j-1][noc];
	while (i <= j) {
		while (a[i][noc] < pil) {
			i++;
		}
		while (a[j][noc] > pil) {
			j--;
		}
		if (i <= j) {
			swap(a[i][noc], a[j][noc]);
			j--;
			i++;
		}
	}
	if (j-l > 0) {
		quicksort(a, l, j, noc);
	}
	if (r-i > 0) {
		quicksort(a, i, r, noc);
	}
}
void print(int** a,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            out << a[i][j] << " ";//функция вывода массива в файл
        }
        out << endl;
    }
}
int main() {
	int n;
	string emp,t;
	getline(in, emp);
	n = stoi(emp);
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		getline(in, emp);
		for (int j = 0; j < n; j++) {
			t = emp.substr(0, emp.find_first_of(' '));
			emp.erase(0, emp.find_first_of(' ') + 1);
			a[i][j] = stoi(t);//задаём изначальный массив
		}
	}
	for (int i = 0; i < n; i++) quicksort(a, 0, n - 1, i);//сортируем столбцы
	print(a, n);//выводим
}