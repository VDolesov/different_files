//Открытое хэширование. Метод умножения по месяцу рождения
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

struct list { //двусвязный список
	people inf; //информационное поле
	list* next; //указатель на следующий элемент
	list* prev; //указатель на предыдущий элемент
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

void push(list*& h, list*& t, people x) { //вставка элемента в конец списка
	list* r = new list; //создание нового элемента
	r->inf = x; //его информационное поле определяется х
	r->next = NULL; //становится последним
	if (!h && !t) //если список пуст
	{
		r->prev = NULL; //то элемент первый - голова
		h = r;
	}
	else
	{
		t->next = r; //иначе - элемент следующий для хвоста
		r->prev = t; //а хвост - предыдущий для элемента
	}
	t = r; //элемент становится хвостом
}

void del_node(list*& h, list*& t, list* r) { //удаление после r

	if (r == h && r == t) //единственный элемент списка:
	{
		h = t = NULL; //список опустошается
	}
	else if (r == h) //удаляем голову списка:
	{
		h = h->next; //сдвигаем голову
		h->prev = NULL;
	}
	else if (r == t) //удаляем хвост списка:
	{
		t = t->prev; //сдвигаем хвост
		t->next = NULL;
	}
	else //удаляем в середине списка:
	{
		r->next->prev = r->prev; //для следующего от r предыдущим становится r->prev
		r->prev->next = r->next; //для предыдущего от r следующим становится r->next
	}
	delete r; //удаляем r
}

int HashFunction(int k) //реализовал хэш-функцию умножения
{
	int N = 16;
	float A = 0.618033;
	int h = N * fmod(k * A, 1);
	return h;
}

vector<pair<list*, list*>> hash_t(vector<people> s, int m) { //создание хэш-таблицы
	vector<pair<list*, list*>> t;
	for (int i = 0; i < m; ++i) //создание пустой таблицы
	{
		list* head = NULL;
		list* tail = head;
		auto p = make_pair(head, tail);
		t.push_back(p);
	}
	for (int i = 0; i < s.size(); ++i) //заполнение
	{
		int k = HashFunction(s[i].Date_of_Birth.mm);	//определяем значение хэш-функции
		push(t[k].first, t[k].second, s[i]); //добавляем элемент массива в соответсвующий список хэш-таблицы
	}
	return t; //возвращаем хэш-таблицу
}

void find_and_del_item(vector<pair<list*, list*>>& t, int x) { //функция поиска и удаления элементов
	int k = HashFunction(x);
	if (t[k].first)
	{
		list* i = t[k].first;
		while (i) {
			list* p = i->next;
			print(i->inf); //вывод найденных
			del_node(t[k].first, t[k].second, i); //удаление
			i = p;
		}
	}
	else
	{
		out << "Нет человека с такой датой рождения" << endl;
	}
}

void print_t(vector<pair<list*, list*>> t) { //вывод хэш-таблицы
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
	vector<people> x; //создаем вектор
	x = inFile(); //считываем и записываем данные о людях в этот вектор определенным образом
	int m = 20;
	int z; //элемент, в соответсвии с которым ведется поиск и удаление
	cout << "Введите значение, в соответствии с которым будет вестись поиск" << endl;
	cin >> z;
	vector<pair<list*, list*>> t = hash_t(x, m);
	out << "Начальные данные" << endl;
	print_t(t);
	out << endl;
	out << "Результаты поиска" << endl;
	find_and_del_item(t, z);
	out << endl;
	out << "Данные после удаления" << endl;
	print_t(t);
	return 0;
}