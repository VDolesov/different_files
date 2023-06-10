//�������� �����������. �������� � �������� �����������, ��������������� � ����� ��������� �� ����
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
using namespace std;

ifstream in("hash.txt"); //������� ����� ��� ������ � ��������� � ������
ofstream out("output.txt"); //������� ����� ��� ������ � ��������� � ������ "output.txt"

struct date { //���� ��������
	int dd, mm, yy;
};

struct people { //������ � ��������
	string surname; //�������
	date Date_of_Birth; //���� ��������
	string dolgnost; //���������
	int stag; //���� ������
	int salary; //��������
};

date str_to_Date(string str) { //�� ������ � ����
	date x;
	string temp = str.substr(0, 2); //����
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2); //�����
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4); //���
	x.yy = atoi(temp.c_str());
	return x;
}

vector<people> inFile() { //���� �� �����
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.surname; //�������
		in >> temp.dolgnost; //���������
		string tmp; //���� ��������
		in >> tmp;
		temp.Date_of_Birth = str_to_Date(tmp); //���� ��������
		in >> temp.stag; //���� ������
		in >> temp.salary; //��������
		x.push_back(temp); //���������� �������
	}
	return x;
}

void print(people x) { //����� � ����
	out << setw(10) << left << x.surname << ' '; //�� ������ ����, 10 ������� ��� �������
	out << setw(13) << left << x.dolgnost << ' '; //�� ��������� 13 �������
	if (x.Date_of_Birth.dd < 10)
	{
		out << left << '0' << x.Date_of_Birth.dd << '.'; //��������� 0
	}
	else
	{
		out << left << x.Date_of_Birth.dd << '.';
	}
	if (x.Date_of_Birth.mm < 10)
	{
		out << left << '0' << x.Date_of_Birth.mm << '.';
	}
	else
	{
		out << left << x.Date_of_Birth.mm << '.';
	}
	out << left << setw(6) << x.Date_of_Birth.yy << ' '; //�� ��� 6 �������
	out << left << setw(2) << x.stag << ' '; //�� ���� ������ 2 �������
	out << left << setw(10) << x.salary << endl; //��������
}

int h1(int x, int m) { //��������������� ���-�������
	double A = 0.618034; // �������� ������� �������
	int uz = (x * A) / 1; // ����� ����� �� ������������ x*A
	double u = x * A - uz; // �������� ������� ����� ������������ x*A ���������� �� x*A ����� ����� ������� ������������
	int res = (u * m) / 1; // �������� ���������� ������� ����� �� m � ����� ����� �����
	return res;
}

int h2(int x, int j, int m) { //�������� ���-�������, �������� �����������
	return x + j;
}

vector<people> hash_t(vector<people> s, int m) { //�������� ���-�������
	people zero; //�������� ������� �������� people
	zero.surname = "";
	zero.dolgnost = "";
	zero.stag = 0;
	zero.salary = 0;
	zero.Date_of_Birth.yy = 0;
	zero.Date_of_Birth.mm = 0;
	zero.Date_of_Birth.dd = 0;
	vector<people> t(m, zero); //�������� ������ �������
	for (int i = 0; i < s.size(); ++i)
	{
		int k = h1(s[i].Date_of_Birth.yy, m); //�������� ��������������� ���-������� 
		int j = 0;
		for (; j < m;)
		{
			int p = h2(k, j, m); //�������� �������� ���-�������
			if (!t[p].stag) //���� ������ ���-������� �� ������ - ������ �������
			{
				//������������� �� ������ �� ����������, ��� - ����
				t[p] = s[i]; //��������� �� ��� ����� � ������� ������� �������
				break;
			}
			else
			{
				j++;
			}
		}
	}
	return t;
}

void find_item(vector<people> t, int x, int m) { //������� ������ ���������
	bool fl = 0;
	int k = h1(x, m);
	for (int i = k; i < m; ++i)
	{
		if (t[i].stag)
		{
			if (h1(t[i].Date_of_Birth.yy, m) == k)
			{
				print(t[i]);
				fl = 1;
			}
		}
	}
	if (!fl)
	{
		out << "��� �������� � �������������� ����� ��������\n";
	}
}

void print_t(vector<people> t) { //����� ���-�������
	for (int i = 0; i < t.size(); ++i)
	{
		out << i << ": ";
		if (!t[i].stag)
		{
			out << "NULL\n";
		}
		else
		{
			print(t[i]);
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<people> x; //������� ������
	x = inFile(); //��������� � ���������� ������ � ����� � ������
	int n = x.size();
	int m = 3 * n;
	out << "��������� ������:\n";
	vector<people> t = hash_t(x, m);
	print_t(t);
	out << "\n���������� ������:\n";
	int y; //�������, � ����������� � ������� ������� �����
	cout << "������� ��� �� �������� ����� ������� �����" << endl;
	cin >> y;
	find_item(t, y, m);
	return 0;
}