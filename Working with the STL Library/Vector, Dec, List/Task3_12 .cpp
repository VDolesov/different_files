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
	cout << "������� n :\n"; int n; cin >> n; // ����� ���������� ��������� � �������
	vector<int>a; vector<int>b; // ������ ������� ��� �������������������
	cout << "������� �������� ������ ������������������ \n";
	for (int i = 0; i < n; i++) { // ���� ��������� ��� ������ ����-��
		int x; cin >> x;
		a.push_back(x);
	}
	cout << "������� ����� � \n";
	cin >> X;
	vector<int>::iterator it = remove_if(a.begin(), a.end(), kratn);
	    a.erase(it, a.end());
	cout << "�������� ������ ������������������\n";
	for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	int m = a.size();
	cout << endl;
	cout << "������� ��������� ������ ������������������ \n"; // ���� ��������� ��� ������ ������������������
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		b.push_back(x);
	}
	cout << "������� ����� � � b \n"; cin >> a1; cin >> b1; // ���� ���������� �����
	if (a1 > b1) { // � ������ ���� ������ ����� ������ �������, ������
		swap(a1, b1);
	}
	cout << "������� ����� Y "; cout << endl; int Y; cin >> Y;
	replace_if(b.begin(), b.end(), zamen, Y);
	cout << "�������� ������ ������������������\n";// ����� ������ ������������������
	for (vector<int>::iterator iter = b.begin(); iter != b.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	list<int>a11; list<int>b11; //������ ������
	for (int i = 0; i < m; i++) { // ������ � ������ ������ ������������������
		a11.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) { // ������ � ������ ������ ������������������
		b11.push_back(b[i]);
	}
	a11.sort(); b11.sort(); // �������� ������������������
	cout << endl;
	b11.merge(a11); // �������� ������������������
	for (list<int>::iterator it = b11.begin(); it != b11.end(); it++) // ������ �������� �����
		cout << *it << " ";
}