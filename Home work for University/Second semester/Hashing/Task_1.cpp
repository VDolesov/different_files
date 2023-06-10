//�������� �����������. ����� ��������� �� ������ ��������
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>

using namespace std;

ifstream in("hash.txt");
ofstream out("output.txt");

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

struct list { //���������� ������
	people inf; //�������������� ����
	list* next; //��������� �� ��������� �������
	list* prev; //��������� �� ���������� �������
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

void push(list*& h, list*& t, people x) { //������� �������� � ����� ������
	list* r = new list; //�������� ������ ��������
	r->inf = x; //��� �������������� ���� ������������ �
	r->next = NULL; //���������� ���������
	if (!h && !t) //���� ������ ����
	{
		r->prev = NULL; //�� ������� ������ - ������
		h = r;
	}
	else
	{
		t->next = r; //����� - ������� ��������� ��� ������
		r->prev = t; //� ����� - ���������� ��� ��������
	}
	t = r; //������� ���������� �������
}

void del_node(list*& h, list*& t, list* r) { //�������� ����� r

	if (r == h && r == t) //������������ ������� ������:
	{
		h = t = NULL; //������ ������������
	}
	else if (r == h) //������� ������ ������:
	{
		h = h->next; //�������� ������
		h->prev = NULL;
	}
	else if (r == t) //������� ����� ������:
	{
		t = t->prev; //�������� �����
		t->next = NULL;
	}
	else //������� � �������� ������:
	{
		r->next->prev = r->prev; //��� ���������� �� r ���������� ���������� r->prev
		r->prev->next = r->next; //��� ����������� �� r ��������� ���������� r->next
	}
	delete r; //������� r
}

int HashFunction(int k) //���������� ���-������� ���������
{
	int N = 16;
	float A = 0.618033;
	int h = N * fmod(k * A, 1);
	return h;
}

vector<pair<list*, list*>> hash_t(vector<people> s, int m) { //�������� ���-�������
	vector<pair<list*, list*>> t;
	for (int i = 0; i < m; ++i) //�������� ������ �������
	{
		list* head = NULL;
		list* tail = head;
		auto p = make_pair(head, tail);
		t.push_back(p);
	}
	for (int i = 0; i < s.size(); ++i) //����������
	{
		int k = HashFunction(s[i].Date_of_Birth.mm);	//���������� �������� ���-�������
		push(t[k].first, t[k].second, s[i]); //��������� ������� ������� � �������������� ������ ���-�������
	}
	return t; //���������� ���-�������
}

void find_and_del_item(vector<pair<list*, list*>>& t, int x) { //������� ������ � �������� ���������
	int k = HashFunction(x);
	if (t[k].first)
	{
		list* i = t[k].first;
		while (i) {
			list* p = i->next;
			print(i->inf); //����� ���������
			del_node(t[k].first, t[k].second, i); //��������
			i = p;
		}
	}
	else
	{
		out << "��� �������� � ����� ����� ��������" << endl;
	}
}

void print_t(vector<pair<list*, list*>> t) { //����� ���-�������
	for (int i = 0; i < t.size(); ++i)
	{
		if (!i)
		{
			out << 20 << ": " << endl;
		}
		else
		{
			out << i << ": " << endl;
		}
		for (list* j = t[i].first; j; j = j->next)
		{
			print(j->inf);
		}
	}
}

int main() {
	setlocale(LC_ALL, "RUS");
	vector<people> x; //������� ������
	x = inFile(); //��������� � ���������� ������ � ����� � ���� ������ ������������ �������
	int m = 20;
	int z; //�������, � ����������� � ������� ������� ����� � ��������
	cout << "������� ��������, � ������������ � ������� ����� ������� �����" << endl;
	cin >> z;
	vector<pair<list*, list*>> t = hash_t(x, m);
	out << "��������� ������" << endl;
	print_t(t);
	out << endl;
	out << "���������� ������" << endl;
	find_and_del_item(t, z);
	out << endl;
	out << "������ ����� ��������" << endl;
	print_t(t);
	return 0;
}