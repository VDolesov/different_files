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
	cout << "������� ����������� ����� �����: \n"; int n; cin >> n;// ����������� ����� �����
	vector<int>a;
	cout << "������� ����� ������ ������������������ " << endl;
	for (int i = 0; i < n; i++) { // ����� � ������ ������ ��������
		int x; cin >> x;
		a.push_back(x);
	}
	cout << "�������� ������ ���������:" << endl;
	vector<int>::iterator it = remove_if(a.begin(), a.end(), odd); // ������ ������ �������� � ������� �������
	a.erase(it, a.end());
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	int m = a.size();//����������� �������
	int max = *max_element(a.begin(), a.end()); // ����� ������������� ��-��
	int min = *min_element(a.begin(), a.end()); // ����� ������������ ��-��
	cout << "������ ������������ �� ����������� :" << endl; //������ � ����� ������������ �� ����������� ���������
	replace(a.begin(), a.end(), max, min); 
	for (int i = 0; i < m; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "������� ����� X: \n";
	int k = 0; cin >> X;
	k = count_if(a.begin(), a.end(),kratn);
	cout << "����������� ��������� ������� " << X << ": " << k;
}