using namespace std;

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>


class Kniga {
private:
	int status; // статус книги 
	string name; // имя книги  
	string lst_nameuser; // имя последнего пользователя
	string author_name; // имя автора (подразумевается как фамилия и инициалы)
	string genre; // жанр книги
	int num_of_pages; // колличество страниц
	string color_of_title; // цвет обложки
	int num_of_all_users; // сколько было владельцев у книги 
	int damage_of_pages; // сколько страниц порванно (подразумевается что человек не читавший и не бравший книгу не знает об этом)
	void bad_status_book() { // статус порванной книги из за износа
		cout << "Книга: " << name << " Порванна и непригодна для чтения\n";
		status = 0;
	}

public:
	Kniga() {}// конструктор по умолчанию для создания дин-ких массивов книг
	Kniga(string N, string lst_us, string an, string g, int np, string cot, int N_of_all) {
		if (N == "" || an == "" || cot == "") { // книгу неправильно создали
			status = 0;
		}
		else {
			name = N;// название книги
			author_name = an; // имя автора 
			lst_nameuser = lst_us; //имя последнего владельца
			num_of_pages = np; // кол-во страниц
			color_of_title = cot; // цвет обложки книги
			genre = g; // жанр
			num_of_all_users = N_of_all; // всего владельцев у книги
			damage_of_pages = (num_of_pages % (num_of_all_users + 1)) * 5; // сколько страниц порванно
			status = 1;
		}
	}

	string getNameOfLstUser() { return lst_nameuser; }
	string getName() { return name; }
	string getAuthorName() { return author_name; }
	string getGenre() { return genre; }
	int getNumbersOfUsers() { return num_of_all_users; }
	int getNumbersOfPages() { return num_of_pages; }
	string getСolorOfTitle() { return color_of_title; }
	int getStatus() { return status; }

	bool NormStatusBook() { // проверка книги на состояние порванной
		if (damage_of_pages < num_of_pages * 20 / 100) {
			status = 1;
			return true;
		}
		else {
			bad_status_book();
			return false;
		}
	}
	// проверка книг на одинаковое название
	bool operator== (Kniga& t) {
		return (name == t.getName() && author_name == t.getAuthorName() &&
			num_of_pages == t.getNumbersOfPages() && color_of_title == t.getСolorOfTitle() &&
			genre == t.getGenre() && num_of_all_users == t.getNumbersOfUsers()) && t.getStatus();
	}
	// сравнение книг по признакам условие буждет любым
	bool  similarity(Kniga& p, bool condition(Kniga& p1, Kniga& p2)) {
		return condition(*this, p);
	}
	// вывод информации о книгах
	friend ostream& operator<< (ostream& out, Kniga t)
	{
		out << "Книга: " << t.name << " Автор: " << t.author_name << " Жанр: " << t.genre
			<< " Колличество пользователей: " << t.num_of_all_users << " Колличество страниц: " << t.num_of_pages
			<< " Цвет обложки: " << t.color_of_title << " Поврежденных страниц: " << t.damage_of_pages << "\n";
		return out;
	}
};



struct node {
	Kniga* inf;
	node* next;
	node* prev;
};

class Katalog_Biblioteki
{
private:
	node* head;
	node* tail;
	int count;

public:
	Katalog_Biblioteki() { head = NULL; tail = NULL; }
	void push(Kniga* t);
	void print();
	bool find(Kniga t);
	bool findAll(bool condition(Kniga& t1));
	void deletebook(int pos);
	int getCount();
	void insert(int index, Kniga* book);
};

int Katalog_Biblioteki::getCount()
{
	return count;
}


void Katalog_Biblioteki::push(Kniga* p)
{
	bool inList = false;
	int k = 0;
	node* curr1 = head;

	while (k < count - 1)
	{
		curr1 = curr1->next;
		k++;
		if (curr1->inf->getName() == p->getName())
		{
			inList = true;
			cout << "\nКнига с таким названием уже есть\n";
		}
	}

	if (!inList && p->getStatus() == 1)
	{
		node* r = new node;
		r->inf = p;
		r->next = NULL;
		if (!head && !tail)
		{
			r->prev = NULL;
			head = r;
		}
		else
		{
			tail->next = r;
			r->prev = tail;
		}
		tail = r;
		count++;
	}
	else {
		cout << "\nНеправильная книга\n";
	}
}


void Katalog_Biblioteki::deletebook(int x)
{

	if ((x == 1) and (head->next))
	{
		node* temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp->inf;
		delete temp;
		count--;
		return;
	}
	else if ((x == 1) and (head == tail))
	{

		head->next = NULL;
		head = NULL;
		delete head;
		count = 0;
		return;
	}

	if (x == count) {
		node* temp = tail;
		tail = tail->prev;
		tail->next = NULL;
		delete temp;
		count--;
		return;
	}
	node* temp = head, *temp2;

	for (int i = 0; i < x - 1; i++)
		temp = temp->next;

	temp2 = temp;
	temp2->prev->next = temp->next;
	temp2->next->prev = temp->prev;
	delete temp;
	count--;
}

void Katalog_Biblioteki::insert(int index, Kniga* book) {
	bool InBib = false;
	int k = 0;
	node* curr1 = head;
	while (k < count - 1) {
		curr1 = curr1->next;
		k++;
		if (curr1->inf->getName() == book->getName())
		{
			InBib = true;
			cout << "\nВ библиотеке уже есть книга с таким названием\n";
		}
	}
	if (!InBib && book->getStatus() == 1)
	{
		node* newNode = new node;
		newNode->inf = book;
		if (index == 0) {
			newNode->next = head;
			newNode->prev = NULL;
			if (head != NULL)
			{
				head->prev = newNode;
			}
			head = newNode;
			if (tail == NULL)
			{
				tail = newNode;
			}
		}
		else {
			node* current = head;
			int i = 0;
			while (i < index - 1)
			{
				current = current->next;
				i++;
			}
			newNode->next = current->next;
			newNode->prev = current;
			if (current->next != NULL)
			{
				current->next->prev = newNode;
			}
			current->next = newNode;

			if (index == count)
			{
				tail = newNode;
			}
		}
		count++;

	}
	else {
		cout << "\nВведенна неправильная книжка\n";
	}
}


void Katalog_Biblioteki::print() { // функция вывода списка на экран
	node* r = head;
	while (r != NULL) {
		cout << *(r->inf);
		r = r->next;
	}
	cout << '\n';
}

bool Katalog_Biblioteki::find(Kniga t) { // функция поиска конкретногго элемента
	node* r = head;
	while (r != NULL) {
		if (*(r->inf) == t)
			return true;
		r = r->next;
	}
	return false;
}


bool Katalog_Biblioteki::findAll(bool condition(Kniga& t1)) {
	node* r = head;
	while (r != NULL) {
		if (condition(*(r->inf)))
		{
			cout << *(r->inf);
		}
		r = r->next;
	}
	return (r != NULL);
}


bool CondNameAndNumPages(Kniga& t) { // сравниваем по параментрам страниц и имени
	return (t.getName() == "Мастер и Маргарита" && t.getNumbersOfPages() == 480);
}

bool CondNumUsers(Kniga& t) { // сравниваем по колличеству пользователей
	return (t.getNumbersOfUsers() > 11);
}

bool Equal(Kniga& t, Kniga& p) { // сравнение на одинаковость
	return (t.getName() == p.getName());
}



void vibor() {
	cout << "\nЧто вы хотите сделать с библиотекой?))\n";
	cout << "\n1) Порвать книги, потому что можем\n";
	cout << "\n2) Добавить книгу\n";
	cout << "\n3) Удалить книгу\n";
	cout << "\n4) Просмотреть каталог библиотеки\n";
	cout << "\n5) Оставить книги в покое\n";
}

int main() {

	setlocale(LC_ALL, "Russian");
	//Kniga(string N,  string lst_us, string an, string g, int np, string cot,, int N_of_all)
	cout << "В библиотеке находятся книги:\n";
	Kniga book_1("Ревизор", "Иван", "Гоголь", "Комедия", 125, "Чёрный", 11);   // тут я добавляю в целом книжки в библиотеку
	cout << book_1;
	Kniga book_2("Идиот", "Пётр", "Достоевский", "Роман", 637, "Красный", 5);
	cout << book_2;
	Kniga book_3("Дубровский", "Борис", "Пушкин", "Роман", 110, "Зеленый", 2);
	cout << book_3;
	Kniga book_4("Рудин", "Генадий", "Тургеньев", "Фикшн", 256, "Белый", 13);
	cout << book_4;
	Kniga book_5("Мастер и Маргарита", "Владимир", "Булгаков", "Роман", 480, "Красный", 2);
	cout << book_5;

	cout << endl;

	Katalog_Biblioteki Books;


	Books.push(&book_1);
	Books.push(&book_2);
	Books.push(&book_3);
	Books.push(&book_4);
	Books.push(&book_5);
	cout << "\nВ итоге остались книги: \n";
	Books.print();

	cout << "\nСтуденты нагло взяли книжки автором которых является <<Булгаков>> и колличество страниц в которых <<480>>\n";
	Books.findAll(CondNameAndNumPages);

	cout << "\nСтуденты снова украли книжки, на этот раз те, у колличество пользователей которых 21\n";
	Books.findAll(CondNumUsers);

	cout << "\nК счастью владелец бибилиотеки смог найти этих нехороших студентов, все книжки были возвращенны в целости и сохранности\n";
	cout << "\nСтуденты оказались порядочными и ни одна книжка не получила ущерба...\n";

	cout << "\nЧто вы хотите сделать с библиотекой?))\n";
	cout << "\n1) Порвать книги, потому что можем\n";
	cout << "\n2) Добавить книгу\n";
	cout << "\n3) Удалить книгу\n";
	cout << "\n4) Просмотреть каталог библиотеки\n";
	cout << "\n5) Оставить книги в покое\n";
	int kol = 0;
	int dob = 0;
	while (kol != 5) {
		int chik;
		cin >> chik;
		if (!chik) {
			cout << "\nВведён неверный номер \n";
			break;
		}
		if (chik == 1) {
			cout << "\nКакую конкретно рвём? (номер)\n"; // возможность удалять книги
			int kk; cin >> kk;
			cout << "\nРвать книги плохо!!!\n";
			vibor();

		}
		if (chik == 2) {// возможность добавлять книги
			string namen; string author_namen; string genren; int num_of_pagesn;
			string color_of_titlen; int num_of_all_usersn;
			string name_user;
			cout << "\nВведите название книги\n";
			cin >> namen;
			cout << "\nВВедите последнего владельца\n";
			cin >> name_user;
			cout << "\nВведите фамилию автора\n";
			cin >> author_namen;
			cout << "\nВведите жанр книги\n";
			cin >> genren;
			cout << "\nВведите колличество страниц\n";
			cin >> num_of_pagesn;
			cout << "\nВведите колличество пользователей\n";
			cin >> num_of_all_usersn;
			cout << "\nВведите цвет обложки\n";
			cin >> color_of_titlen;
			int damage_of_pagesn = (num_of_pagesn % (num_of_all_usersn + 1)) * 5;
			Kniga book_temp(namen, name_user, author_namen, genren, num_of_pagesn, color_of_titlen, damage_of_pagesn);
			if (dob >= 1) {
				cout << "\nВместо какой книги вы хотите добавить книгу? (номер) \n"; int ll; cin >> ll;
				if (ll >= 6)
					Books.insert(ll, &book_temp);
				else
					cout << "\nНеправильный номер книги\n";
			}
			else {
				Books.push(&book_temp);

			}
			cout << "\nГотово, вот новый список библиотеки\n";
			Books.print();
			dob++;
		}

		if (chik == 3) {
			cout << "\nКакую книгу по счёту необходимо удалить ?\n"; int nn; cin >> nn;
			Books.deletebook(nn);
			cout << "\nГотово, вот новый список библиотеки\n";
			Books.print();
			vibor();
		}
		if (chik == 4) {
			cout << "\nКаталог библиотеки:\n";
			Books.print();
			vibor();
		}

		if (chik == 5) {
			cout << "\n Прекрасное решение !!! \n" << "\nВсего доброго...\n";
			kol = 5;
		}
	}
}
