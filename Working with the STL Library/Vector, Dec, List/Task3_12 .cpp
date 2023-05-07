#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<numeric>

using namespace std;


int X;
int a1;
int b1;
bool kratn(int x) {
	return x % X == 0;
}

bool zamen(int x) {
	return (x >= a1 && x <= b1);

}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Введите n :\n"; int n; cin >> n; // ввожу количество элементов в векторе
	vector<int>a; vector<int>b; // создаю векторы для последовательностей
	cout << "Введите элементы первой последовательности \n";
	for (int i = 0; i < n; i++) { // ввод элементов для первой посл-ти
		int x; cin >> x;
		a.push_back(x);
	}
	cout << "Введите число Х \n";
	cin >> X;
	vector<int>::iterator it = remove_if(a.begin(), a.end(), kratn);
	    a.erase(it, a.end());
	cout << "итоговая первая последовательность\n";
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	int m = a.size();
	cout << endl;
	cout << "Введите эллементы второй последовательности \n"; // ввод элементов для второй последовательности
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		b.push_back(x);
	}
	cout << "Введите числа а и b \n"; cin >> a1; cin >> b1; // ввод диапазонна чисел
	if (a1 > b1) { // в случае если первое число больше второго, замена
		swap(a1, b1);
	}
	cout << "Введите число Y "; cout << endl; int Y; cin >> Y;
	replace_if(b.begin(), b.end(), zamen, Y);
	cout << "итоговая вторая последовательность\n";// вывод второй последовательности
	for (vector<int>::iterator iter = b.begin(); iter != b.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	list<int>a11; list<int>b11; //создаю списки
	for (int i = 0; i < m; i++) { // заношу в список первую последовательность
		a11.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) { // заношу в список вторую последовательность
		b11.push_back(b[i]);
	}
	a11.sort(); b11.sort(); // сортирую последовательности
	cout << endl;
	b11.merge(a11); // совмещаю последовательности
	for (list<int>::iterator it = b11.begin(); it != b11.end(); it++) // вывожу итоговый ответ
		cout << *it << " ";
}