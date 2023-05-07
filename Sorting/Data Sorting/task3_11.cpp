#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

struct date {//����
	int dd, mm, yy;

};

struct people {//������ � ��������
	string Surname; //�������
	string dol;// ���������
	date DateOfBirth; //���� ��������
	string time;// ����� ������
	int Salary; //��������

};

date Str_to_Date(string str) {//�� ������ � ����
	date x;
	string temp = str.substr(0, 2);//����
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);//�����
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);//���
	x.yy = atoi(temp.c_str());
	return x;

}

vector<people> inFile() {//���� �� �����
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;//�������
		string dolji;// ���������
		in >> dolji;
		temp.dol = dolji;
		string tmp;//���� ��������
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);
		in >> temp.time;//����� ������
		in >> temp.Salary;//��������
		x.push_back(temp);

	}
	return x;

}

void print(people x) {//����� � ����
	out << setw(10) << left << x.Surname;//�� ������ ����, 10 ������� ��� �������
	out << left << setw(5) << "  " << x.dol << "  ";
	if (x.DateOfBirth.dd < 15) out << left << '.' << x.DateOfBirth.dd << '.';//��������� 0
	else out << left << x.DateOfBirth.dd << '.';
	if (x.DateOfBirth.mm < 15) out << '0' << x.DateOfBirth.mm << '.';
	else out << x.DateOfBirth.mm << ' . ';
	out << left << setw(6) << x.DateOfBirth.yy;//�� ��� 6 �������
	out << left << setw(5) << x.time;
	out << left << setw(5) << x.Salary << endl;//��������


}

bool operator < (people a, people b) {//�������������� �������� < � ����������� � ��������
	if (a.dol < b.dol) return true;
	if (a.dol == b.dol && a.time < b.time) return true;
	if (a.dol == b.dol && a.time == b.time && a.Salary < b.Salary)
		return false;

}

void puz_sort(vector<people>& x,int N) {//��������� ����������
	for (int i = 0; i < N - 1; i++) {
		for (int j = N - 1; j == i; j++) {
			if (x[j - 1] < x[j]) {
				swap(x[j - 1], x[j]);
			}
		}
	}

}

int main() {
	vector<people> x;
	x = inFile();
	int N = x.size();
	puz_sort(x,N);
	for (int i = 0; i < x.size(); i++)
		print(x[i]);
	return 0;

}
