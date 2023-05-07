#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n; cin >> n;// колличество целых чисел
	vector<int>a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.push_back(x);
	}
	int max = *max_element(a.begin(), a.end()); // поиск максимальных элементов
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (max == a[i])
			k = k + 1;
	}
	cout << k;
}