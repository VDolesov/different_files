#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
void gnom_sort(int* a, int n) {//����� ����������� ������� ������� ������� ����������� 
	int i = 1;
	while (i < n) {
		if (i == 0) {
			i++;
		}
		if (a[i - 1] <= a[i]) {
			i++;
		}
		else {
			swap(a[i], a[i - 1]);
			i--;
		}
	}
}

void gnom_sort_reverse(int* a, int n) {//����� ����������� ������� ������� ������� ����������� ��������
	int i = n;
	while (i > 0) {
		if (i == n) {
			i--;
		}
		if (a[i-1] >= a[i]) {
			i--;
		}
		else {
			swap(a[i], a[i - 1]);
			i++;
		}
	}
}



void print(int** a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << a[i][j] << " ";//������� ������ ������� � ����
		}
		out << endl;
	}
}
int main() {
	int n;
	string emp, t;
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
			a[i][j] = stoi(t);//����� ����������� ������ 
		}
	}
	for (int i = 1; i < n; i += 2) {
		gnom_sort(a[i], n);//��������� ��� �������� �������
	}
	for (int i = 0; i < n; i += 2) {
		gnom_sort_reverse(a[i], n);
	}
	print(a, n);//�������
}