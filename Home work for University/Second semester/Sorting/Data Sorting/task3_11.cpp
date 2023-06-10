#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");

struct date {//дата
	int dd, mm, yy;

};

struct people {//данные о человеке
	string Surname; //фамилия
	string dol;// должность
	date DateOfBirth; //дата рождения
	string time;// время работы
	int Salary; //зарплата

};

date Str_to_Date(string str) {//из строки в дату
	date x;
	string temp = str.substr(0, 2);//день
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2);//месяц
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4);//год
	x.yy = atoi(temp.c_str());
	return x;

}

vector<people> inFile() {//ввод из файла
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.Surname;//фамилия
		string dolji;// должность
		in >> dolji;
		temp.dol = dolji;
		string tmp;//дата рождения
		in >> tmp;
		temp.DateOfBirth = Str_to_Date(tmp);
		in >> temp.time;//время работы
		in >> temp.Salary;//зарплата
		x.push_back(temp);

	}
	return x;

}

void print(people x) {//вывод в файл
	out << setw(10) << left << x.Surname;//по левому краю, 10 позиций для фамилии
	out << left << setw(5) << "  " << x.dol << "  ";
	if (x.DateOfBirth.dd < 15) out << left << '.' << x.DateOfBirth.dd << '.';//добавляем 0
	else out << left << x.DateOfBirth.dd << '.';
	if (x.DateOfBirth.mm < 15) out << '0' << x.DateOfBirth.mm << '.';
	else out << x.DateOfBirth.mm << ' . ';
	out << left << setw(6) << x.DateOfBirth.yy;//на год 6 позиций
	out << left << setw(5) << x.time;
	out << left << setw(5) << x.Salary << endl;//запрлата


}

bool operator < (people a, people b) {//переопределяем оператор < в соотвествии с условием
	if (a.dol < b.dol) return true;
	if (a.dol == b.dol && a.time < b.time) return true;
	if (a.dol == b.dol && a.time == b.time && a.Salary < b.Salary)
		return false;

}

void puz_sort(vector<people>& x,int N) {//пузырьком сортировка
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
