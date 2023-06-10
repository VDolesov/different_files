//Закрытое хэширование. Основная — линейное хеширование, вспомогательная — метод умножения по году
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>
using namespace std;

ifstream in("hash.txt"); //создаем поток для чтения и связываем с файлом
ofstream out("output.txt"); //создаем поток для записи и связываем с файлом "output.txt"

struct date { //дата рождения
	int dd, mm, yy;
};

struct people { //данные о человеке
	string surname; //фамилия
	date Date_of_Birth; //дата рождения
	string dolgnost; //должность
	int stag; //стаж работы
	int salary; //зарплата
};

date str_to_Date(string str) { //из строки в дату
	date x;
	string temp = str.substr(0, 2); //день
	x.dd = atoi(temp.c_str());
	temp = str.substr(3, 2); //месяц
	x.mm = atoi(temp.c_str());
	temp = str.substr(6, 4); //год
	x.yy = atoi(temp.c_str());
	return x;
}

vector<people> inFile() { //ввод из файла
	vector<people> x;
	people temp;
	while (in.peek() != EOF) {
		in >> temp.surname; //фамилия
		in >> temp.dolgnost; //должность
		string tmp; //дата рождения
		in >> tmp;
		temp.Date_of_Birth = str_to_Date(tmp); //дата рождения
		in >> temp.stag; //стаж работы
		in >> temp.salary; //зарплата
		x.push_back(temp); //заполнение массива
	}
	return x;
}

void print(people x) { //вывод в файл
	out << setw(10) << left << x.surname << ' '; //по левому краю, 10 позиций для фамилии
	out << setw(13) << left << x.dolgnost << ' '; //на должность 13 позиций
	if (x.Date_of_Birth.dd < 10)
	{
		out << left << '0' << x.Date_of_Birth.dd << '.'; //добавляем 0
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
	out << left << setw(6) << x.Date_of_Birth.yy << ' '; //на год 6 позиций
	out << left << setw(2) << x.stag << ' '; //на стаж работы 2 позиции
	out << left << setw(10) << x.salary << endl; //зарплата
}

int h1(int x, int m) { //вспомогательная хэш-функция
	double A = 0.618034; // выбираем золотое сечение
	int uz = (x * A) / 1; // целая часть от произведения x*A
	double u = x * A - uz; // получаем дробную часть произведения x*A вычитанием из x*A целой части данного произведения
	int res = (u * m) / 1; // умножаем полученную дробную часть на m и берем целую часть
	return res;
}

int h2(int x, int j, int m) { //основная хэш-функция, линейное хэширование
	return x + j;
}

vector<people> hash_t(vector<people> s, int m) { //создание хэш-таблицы
	people zero; //создание пустого элемента people
	zero.surname = "";
	zero.dolgnost = "";
	zero.stag = 0;
	zero.salary = 0;
	zero.Date_of_Birth.yy = 0;
	zero.Date_of_Birth.mm = 0;
	zero.Date_of_Birth.dd = 0;
	vector<people> t(m, zero); //создание пустой таблицы
	for (int i = 0; i < s.size(); ++i)
	{
		int k = h1(s[i].Date_of_Birth.yy, m); //значение вспомогательной хэш-функции 
		int j = 0;
		for (; j < m;)
		{
			int p = h2(k, j, m); //значение основной хэш-функции
			if (!t[p].stag) //если ячейка хэш-таблицы не занята - пустой элемент
			{
				//просматриваем по одному из параметров, тут - стаж
				t[p] = s[i]; //вставляем на это место в таблице элемент массива
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

void find_item(vector<people> t, int x, int m) { //функция поиска элементов
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
		out << "Нет человека с соответсвующим годом рождения\n";
	}
}

void print_t(vector<people> t) { //вывод хэш-таблицы
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
	vector<people> x; //создаем вектор
	x = inFile(); //считываем и записываем данные о людях в вектор
	int n = x.size();
	int m = 3 * n;
	out << "Начальные данные:\n";
	vector<people> t = hash_t(x, m);
	print_t(t);
	out << "\nРезультаты поиска:\n";
	int y; //элемент, в соответсвии с которым ведется поиск
	cout << "Введите год по которому будет вестись поиск" << endl;
	cin >> y;
	find_item(t, y, m);
	return 0;
}