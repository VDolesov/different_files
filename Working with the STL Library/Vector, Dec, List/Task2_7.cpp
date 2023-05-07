#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool odd(int x) {
	return x % 2 == 0;
}
int X;
bool kratn(int x) {
	return x % X == 0;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "Введите колличество целых чисел: \n"; int n; cin >> n;// колличество целых чисел
	vector<int>a;
	cout << "Введите члены первой последовательности " << endl;
	for (int i = 0; i < n; i++) { // ввожу в вектор нужные значения
		int x; cin >> x;
		a.push_back(x);
	}
	cout << "Удаление чётных элементов:" << endl;
	vector<int>::iterator it = remove_if(a.begin(), a.end(), odd); // удаляю чётные элементы с помощью функици
	a.erase(it, a.end());
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	int m = a.size();//размерность вектора
	int max = *max_element(a.begin(), a.end()); // поиск максимального эл-та
	int min = *min_element(a.begin(), a.end()); // поиск минимального эл-та
	cout << "Замена максимальных на минимальный :" << endl; //замена и вывод максимальных на минимальный элементов
	replace(a.begin(), a.end(), max, min); 
	for (int i = 0; i < m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Введите число X: \n";
	int k = 0; cin >> X;
	k = count_if(a.begin(), a.end(),kratn);
	cout << "Колличество элементов кратных " << X << ": " << k;
}