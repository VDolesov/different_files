using namespace std;

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<fstream>


class Error
{
public:
	virtual void print() { cerr << "�������� ���� ������\n "; }
};

class FileErr : public Error
{
public:
	FileErr() {}
	void print() { cerr << "������ �����\n "; }

};

class OverFlowMem : public Error
{
public:
	OverFlowMem() {}
	void print() { cerr << "������ ������������ ������\n "; }
};

enum StatusEr
{
	OK,
	Err
};

class Kniga {
private:
	int status; // ������ ����� 
	string name; // ��� �����  
	string lst_nameuser; // ��� ���������� ������������
	string author_name; // ��� ������ (��������������� ��� ������� � ��������)
	string genre; // ���� �����
	int num_of_pages; // ����������� �������
	string color_of_title; // ���� �������
	int num_of_all_users; // ������� ���� ���������� � ����� 
	int DamOfPag() { return (num_of_pages % (num_of_all_users + 1)) * 5; }
	int damage_of_pages; // ������� ������� �������� (��������������� ��� ������� �� �������� � �� ������� ����� �� ����� �� ����)
	void bad_status_book() { // ������ ��������� ����� �� �� ������
		cout << "�����: " << name << " �������� � ���������� ��� ������\n";
		status = 0;
	}
public:
	Kniga() // ����������� �� ��������� ��� �������� ���-��� �������� ����
	{
		status = Err;
		name = "";
		author_name = "";
		lst_nameuser = "";
		genre = "";
		num_of_pages = 0;
		color_of_title = "";
		num_of_all_users = 0;
		damage_of_pages = 0;
	}
	Kniga(string N, string an, string lst_us, string g, int np, string cot, int N_of_all)
	{
		status = Err;
		name = "";// �������� �����
		author_name = ""; // ��� ������ 
		lst_nameuser = ""; //��� ���������� ���������
		num_of_pages = 0; // ���-�� �������
		color_of_title = ""; // ���� ������� �����
		genre = ""; // ����
		num_of_all_users = 0; // ����� ���������� � �����
		damage_of_pages = 0; // ������� ������� ��������
		status = Err;
		try
		{
			if (N.find_first_of("0123456789") != std::string::npos)
			{
				throw Error();
			}
			if (N.size() <= 3) {
				throw "�������� ����� �������� ������";
			}
			if (an.size() <= 2) {
				throw an;
			}
			if (an.find_first_of("0123456789") != std::string::npos)
			{
				throw Error();
			}
			if (lst_us == "") {
				throw lst_us;
			}
			if (lst_us.find_first_of("0123456789") != std::string::npos)
			{
				throw Error();
			}
			if (np <= 0) {
				throw np;
			}
			if (cot.size() < 3) {
				throw cot;
			}
			if (cot.find_first_of("-+=.,/]\=[{}!`") != std::string::npos)
			{
				throw Error();
			}
			if (g.size() <= 3) {
				throw g;
			}
			if (g.find_first_of("0123456789") != std::string::npos)
			{
				throw Error();
			}
			if (N_of_all <= 0) {
				throw N_of_all;
			}
		

			status = OK;
			name = N;
			author_name = an;
			lst_nameuser = lst_us;
			num_of_pages = np;
			color_of_title = cot;
			genre = g;
			num_of_all_users = N_of_all;
			damage_of_pages = DamOfPag();
		}
		catch (Error& er)
		{
			er.print();
		}
		catch (...)
		{
			cout << "������ ��� ����� ��������\n";
		}

	}

	~Kniga() {}

	string getNameOfLstUser() { return lst_nameuser; }
	string getName() { return name; }
	string getAuthorName() { return author_name; }
	string getGenre() { return genre; }
	int getNumbersOfUsers() { return num_of_all_users; }
	int getNumbersOfPages() { return num_of_pages; }
	string get�olorOfTitle() { return color_of_title; }
	int getStatus() { return status; }

	bool NormStatusBook() { // �������� ����� �� ��������� ���������
		if (damage_of_pages < num_of_pages * 20 / 100) {
			status = OK;
			return true;
		}
		else {
			bad_status_book();
			return false;
		}
	}

	void ChangeLstUser(string newPOl) {// ������ ���������� ������������
		if (status == OK) {
			lst_nameuser = newPOl;
			num_of_all_users += 1;
		}
	}

	void ChangeColorTitle(string newCol) {
		if (status == OK)
			color_of_title = newCol;
	}

	// �������� ���� �� ���������� ��������
	bool operator== (Kniga& t) {
		return (name == t.getName() && author_name == t.getAuthorName() &&
			num_of_pages == t.getNumbersOfPages() && color_of_title == t.get�olorOfTitle() &&
			genre == t.getGenre() && num_of_all_users == t.getNumbersOfUsers()) && t.getStatus();
	}
	// ��������� ���� �� ��������� ������� ������ �����
	bool  similarity(Kniga& p, bool condition(Kniga& p1, Kniga& p2)) {
		return condition(*this, p);
	}
	// ����� ���������� � ������
	friend ostream& operator<< (ostream& out, Kniga t)
	{
		out << "�����: " << t.name << " �����: " << t.author_name << " ����: " << t.genre
			<< " ����������� �������������: " << t.num_of_all_users << " ����������� �������: " << t.num_of_pages
			<< " ���� �������: " << t.color_of_title << " ������������ �������: " << t.damage_of_pages << "\n";
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
			cout << "\n����� � ����� ��������� ��� ����\n";
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
	node* temp = head, * temp2;

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
			cout << "\n� ���������� ��� ���� ����� � ����� ���������\n";
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
		cout << "\n�������� ������������ ������\n";
	}
}


void Katalog_Biblioteki::print() { // ������� ������ ������ �� �����
	node* r = head;
	while (r != NULL) {
		cout << *(r->inf);
		r = r->next;
	}
	cout << '\n';
}

bool Katalog_Biblioteki::find(Kniga t) { // ������� ������ ������������ ��������
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


bool CondNameAndNumPages(Kniga& t) { // ���������� �� ����������� ������� � �����
	return (t.getName() == "������ � ���������" && t.getNumbersOfPages() == 480);
}

bool CondNumUsers(Kniga& t) { // ���������� �� ����������� �������������
	return (t.getNumbersOfUsers() > 11);
}

bool Equal(Kniga& t, Kniga& p) { // ��������� �� ������������
	return (t.getName() == p.getName());
}



void vibor() {
	cout << "\n��� �� ������ ������� � �����������?))\n";
	cout << "\n1) ������� �����, ������ ��� �����\n";
	cout << "\n2) �������� �����\n";
	cout << "\n3) ������� �����\n";
	cout << "\n4) ����������� ������� ����������\n";
	cout << "\n5) �������� ����� � �����\n";
}





int main() {

	setlocale(LC_ALL, "Russian");
	//Kniga(string N,  string lst_us, string an, string g, int np, string cot,, int N_of_all)
	Katalog_Biblioteki Books;
	//cout << "� ���������� ��������� �����:\n";
	Kniga book_1("������123����", "�����", "������", "�����", 110, "�������", 2);
	cout << book_1;
	Kniga book_2("����������", "�����", "������", "�����", -110, "�������", 2);
	cout << book_2;
	Kniga book_3("����������", "�����", "������", "�����", 110, "�������", -2);
	cout << book_3;
	Kniga book_4("", "�����", "������", "�����", 110, "�������", 2);
	cout << book_4;



	cout << endl;
	ifstream File("input.txt");
	Kniga* bb;
	try
	{
		if (!File.is_open())
			throw FileErr();
		string N, lst_us, an, g, cot;
		int np, N_of_all; int n;
		File >> N >> lst_us >> an >> g >> np >> cot >> N_of_all;
		//Kniga b(N, lst_us, an, g, np, cot, N_of_all);
		// int* mas = new int[n];
		int k = 0, p;
		File >> n;
		while (File.peek() != EOF)
		{
			File >> N >> lst_us >> an >> g >> np >> cot >> N_of_all;
			if (k == n)
				throw OverFlowMem();
			bb = new Kniga(N, lst_us, an, g, np, cot, N_of_all);
			Books.push(bb);
			k++;
		}
	}

	catch (Error& error)
	{
		error.print();
	}
	cout << "\n�������� ����� ����� ������ ������� ������� �������� <<��������>> � ����������� ������� � ������� <<480>>\n";
	Books.findAll(CondNameAndNumPages);

	cout << "\n�������� ����� ������ ������, �� ���� ��� ��, � ����������� ������������� ������� 21\n";
	Books.findAll(CondNumUsers);

	//cout << "\n� ������� �������� ����������� ���� ����� ���� ��������� ���������, ��� ������ ���� ����������� � ������� � �����������\n";
	//cout << "\n�������� ��������� ����������� � �� ���� ������ �� �������� ������...\n";

	//cout << "\n��� �� ������ ������� � �����������?))\n";
	//cout << "\n1) ������� �����, ������ ��� �����\n";
	//cout << "\n2) �������� �����\n";
	//cout << "\n3) ������� �����\n";
	//cout << "\n4) ����������� ������� ����������\n";
	//cout << "\n5) �������� ����� � �����\n";
	//int kol = 0;
	//int dob = 0;
	//while (kol != 5) {
	//	int chik;
	//	cin >> chik;
	//	if (chik == 1) {
	//		cout << "\n����� ��������� ���? (�����)\n"; // ����������� ������� �����
	//		int kk; cin >> kk;
	//		cout << "\n����� ����� �����!!!\n";
	//		vibor();

	//	}
	//	if (chik == 2) {// ����������� ��������� �����
	//		string namen; string author_namen; string genren; int num_of_pagesn;
	//		string color_of_titlen; int num_of_all_usersn;
	//		string name_user;
	//		cout << "\n������� �������� �����\n";
	//		cin >> namen;
	//		cout << "\n������� ���������� ���������\n";
	//		cin >> name_user;
	//		cout << "\n������� ������� ������\n";
	//		cin >> author_namen;
	//		cout << "\n������� ���� �����\n";
	//		cin >> genren;
	//		cout << "\n������� ����������� �������\n";
	//		cin >> num_of_pagesn;
	//		cout << "\n������� ����������� �������������\n";
	//		cin >> num_of_all_usersn;
	//		cout << "\n������� ���� �������\n";
	//		cin >> color_of_titlen;
	//		int damage_of_pagesn = (num_of_pagesn % (num_of_all_usersn + 1)) * 5;
	//		Kniga book_temp(namen, name_user, author_namen, genren, num_of_pagesn, color_of_titlen, damage_of_pagesn);
	//		if (dob >= 1) {
	//			cout << "\n������ ����� ����� �� ������ �������� �����? (�����) \n"; int ll; cin >> ll;
	//			if (ll >= 6)
	//				Books.insert(ll, &book_temp);
	//			else
	//				cout << "\n������������ ����� �����\n";
	//		}
	//		else {
	//			Books.push(&book_temp);

	//		}
	//		cout << "\n������, ��� ����� ������ ����������\n";
	//		Books.print();
	//		dob++;


	//		if (chik == 3) {
	//			cout << "\n����� ����� �� ����� ���������� ������� ?\n"; int nn; cin >> nn;
	//			Books.deletebook(nn);
	//			cout << "\n������, ��� ����� ������ ����������\n";
	//			Books.print();
	//			vibor();
	//		}
	//		if (chik == 4) {
	//			cout << "\n������� ����������:\n";
	//			Books.print();
	//			vibor();
	//		}

	//		if (chik == 5) {
	//			cout << "\n ���������� ������� !!! \n" << "\n����� �������...\n";
	//			kol = 5;
	//		}

	//	}
	//}
}