#pragma once
//Автосервис предоставляет разные виды услуг по ремонту и обслуживанию автомобилей и включает нескольких цехов :
//техосмотра, кузовного ремонта, шиномонтажа, ремонта двигателя.В каждом цеху работает несколько мастеров(2≤ K ≤ 7).
//Известно недельное расписание работы автосервиса : 5 дней по 12 часов и два дня по 8 часов, без перерывов на обед.
//
//Необходимо разработать имитационную модель работы автосервиса, при которой заявки на обслуживание автомобилей поступают 
//случайным образом, каждая заявка включает одну или несколько услуг.Каждая услуга выполняется в определенном цеху, известна
//средняя длительность ее выполнения и получаемая при этом прибыль.Фактический срок выполнения заявки может отличаться от среднего
//на некоторую случайную величину, изменяющуюся в некотором диапазоне(например, от часа до нескольких дней, в зависимости от вида услуги).
//Случайной величиной является также отрезок времени между последовательным появлением двух заявок, она имеет нормальное или равномерное 
//Распределение в некотором интервале(например, от 15 минут до 28 часа), причем плотность потока заявок зависит от времени дня – в середине
//рабочего дня заявки поступают чаще, т.е.плотность потока выше.


//Поступившие заявки образуют несколько очередей – по числу цехов автосервиса, причем в общем случае заявка может сохраняться в очереди несколько дней.
//Один и тот же автомобиль может находиться одновременно в нескольких очередях(с заявками на разные услуги), но его обслуживание в нужных цехах производится 
//последовательно.Максимальный общий срок обслуживания каждого автомобиля – неделя, и если по окончании этого срока ремонт(обслуживание) автомобиля еще не закончен, 
//то владелец забирает его из автосервиса – тем самым автосервис теряет своих клиентов.



//Цель моделирования работы автосервиса – определение оптимального соотношения числа рабочих в его цехах, выявление
//“узких” мест в его работе(таких как нехватка мастеров или их простой).Недельная зарплата каждого мастера определяется
//как 35 % от приносимой им прибыли автосервису, но не менее 1 тыс.рублей в день.Период моделирования – неделя, шаг – М часов.
//
//Следует включить в параметры моделирования величины K и М, а также диапазоны разброса вышеуказанных случайных величин.
//Визуализация моделируемого процесса должна предусматривать показ текущей ситуации в автосервисе, том числе – получившиеся очереди в каждом цеху,
//занятость рабочих, появление новых заявок.Также должен быть предусмотрен вывод подсчитанной статистики : общее число обслуженных автомобилей
//и предоставленных услуг разного вида, среднее время обслуживания одного автомобиля; средняя длина очередей в каждом цеху; средняя занятость рабочих и 
//средняя их зарплата, общая прибыль автосервиса.


#include<iostream>
#include<string>
#include<ctime>
#include<cmath>
#include <cstdlib>
#include<random>



using namespace std;

const string mas_cars_plates[27]{ "MB GLA 250","MB GLE 400","EXEED RX","FORD KUGA","GEELY COLRAY","BMW 530I","MB E250","MB GLS450","LADA 2107",
"LADA VESTA","LADA PRIORA","LADA NIVA","LADA NIVA TREVEL","BMW 340I","TOYOTA LC 200", "TOYOTA CAMRY","HONDA CIVIC", "KIA MOHAVE", "SUBARU FORESTER",
"LIXIAN L9","SKODA OCTAVIA","SKODA SUPERB","BMW X5","LADA GRANTA","KIA RIO","MB GLC","SUBARU IMPREZA"};


const string Chex_TO[7]{ "Замена масла в двигателе","Замена сальников амортизатора","замена сайленблоков"
"Замена масла в коробке","Замена воздушного фильтра","Замена салонного фильтра","Замена масла в редукторах" };


const int cost_TO[7]{ 7000,2000,1300,12000,1200,1250,5500 };

const string Chex_KR[7]{ "Покраска переднего бампера","Покраска заднего бампера","Покраска передих крыльев",
"Покраска задних крыльев", "Полировка", "Покраска Кузова", "Нанесенеие керамики на кузов" };

const int cost_KR[7]{ 11000,10000,11200,11250,12300,45000,20000 };

const string Chex_Rimz[7]{ "Шиномонтаж","Шиномонтаж + балансировка","Дошиповка","Вулканизация Шины",
"Правка дисков","Балансировка колёс","Мойка Шин" };

const int cost_Rimz[7]{ 1000,1100,1150,1320,2100,450,370 };

const string Chex_Engine[7]{ "Гильзовка двигателя","Ремонт помпы","Капитальный ремонт Двигателя",
"Ремонт ГРМ","Замена турбины","Замена Радиатора","Замена термостата" };

const int cost_Engine[7]{ 47000,14500,98000,32000,70000,27000,13000 };

const string Ser[28] = { "Замена масла в двигателе","Замена сальников амортизатора","замена сайленблоков"
"Замена масла в коробке","Замена воздушного фильтра","Замена салонного фильтра","Замена масла в редукторах",
 "Покраска переднего бампера","Покраска заднего бампера","Покраска передих крыльев",
"Покраска задних крыльев", "Полировка", "Покраска Кузова", "Нанесенеие керамики на кузов",
"Шиномонтаж","Шиномонтаж + балансировка","Дошиповка","Вулканизация Шины",
"Правка дисков","Балансировка колёс","Мойка Шин","Гильзовка двигателя","Ремонт помпы","Капитальный ремонт Двигателя",
"Ремонт ГРМ","Замена турбины","Замена Радиатора","Замена термостата" };


const int Ser_price[28] = { 7000,2000,1300,12000,1200,1250,5500,11000,10000,11200,11250,12300,45000,20000,1000,1100,
1150,1320,2100,450,370,47000,14500,98000,32000,70000,27000,13000 };

string minute = "00";
int ch = 0;
int stp = 1;
int chas = 5;

int kk = 0;

string generateLicensePlate() {
	// Генерация случайных букв
	char letters[3];
	for (int i = 0; i < 3; ++i) {
		letters[i] = 'A' + rand() % 26;
	}

	// Генерация случайных цифр
	int numbers[3];
	for (int i = 0; i < 3; ++i) {
		numbers[i] = rand() % 10;
	}

	// Сборка номерного знака
	std::string licensePlate = "";
	for (int i = 0; i < 3; ++i) {
		licensePlate += letters[i];
	}
	for (int i = 0; i < 3; ++i) {
		licensePlate += std::to_string(numbers[i]);
	}

	return licensePlate;
}


class Car
{
private:
	string licenceplate; // Марка авто
	string service; // наименование услуги 
	int cost; // цена услуги
	int num; // номер клиента
	int time; // время затрачиваемое на обслуживание клиента в минутах
	time_t rec; // время записи
public:
	Car() {}
	Car(string licenceplate, string service, int cost, int num, int time, time_t rec)
	{
		this->licenceplate = licenceplate;
		this->service = service;
		this->cost = cost;
		this->num = num;
		this->time = time;
		this->rec = rec;
	}




	int GetNum() { return  num; }
	int GetCost() { return cost; }
	int GetTime() { return time; }
	string GetLicenPlate() { return licenceplate; }
	string GetServise() { return service; }
	void SetTime(int changes) { time -= changes; }
	int getRec() { return rec; }
	void setRec(time_t rec) { this->rec = rec; }

	bool operator==(Car& c)
	{
		return (licenceplate == c.GetLicenPlate() && service == c.GetServise() && cost == c.GetCost() &&
			num == c.GetNum() && time == c.GetTime());
	}
};




struct node {
	Car*inf;
	node *next;
	node *prev;
};
class List
{
private:
	node *head;
	node *tail;
	int count = 0;
public:
	List() { head = NULL; tail = NULL; }
	void push(Car* x);
	void print();
	Car* FindToNumber(int n);
	void del_node(node *l);
	void del_equal();
	void del_all();
	void del_number(int k);
	int getCount();
};

int List::getCount() { return count; }

void List::push(Car*x) {
	node *r = new node;
	r->inf = x;
	r->next = NULL;
	if (!head && !tail)
	{
		r->prev = NULL;
		head = r;
	}
	else {
		tail->next = r;
		r->prev = tail;
	}
	tail = r;
	count++;
}

Car* List::FindToNumber(int nn)
{
	node *r = head;
	node *p;
	int k = 0;
	while (r != NULL)
	{
		p = r;
		if (k == nn)   break;
		r = r->next; k++;
	}
	return p->inf;
}

void List::del_node(node *T)
{
	if (T == head && T == tail)  //долнжо быть по крайне мере count на понижение
		head = tail = NULL;
	else if (T == head)
	{
		head = head->next;
		head->prev = NULL;
	}
	else if (T == tail)
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	else
	{
		T->next->prev = T->prev;
		T->prev->next = T->next;
	}
	delete T;

}

void List::del_equal() {
	node *r = head;
	while (r != NULL)
	{
		node *p = r->next;
		while (p != NULL)
		{
			node *q = p->next;
			if (p->inf->GetNum() == r->inf->GetNum() || p->inf->GetLicenPlate() == r->inf->GetLicenPlate())
			{
				del_node(p);
				count--;
			}
			p = q;
		}
		r = r->next;
	}
}

void List::del_number(int n)
{
	node *r = head;
	node *p;
	int k = 0;
	while (r != NULL)
	{
		p = r;
		if (k == n)
		{
			del_node(p);
			count--;
			break;
		}
		r = r->next;
		k++;
	}
}

int counter1 = 0;

int counter2 = 0;

int chet = 0;
int zp_11 = 0;
int zp_12 = 0;

int zp_21 = 0;
int zp_22 = 0;
int zp_31 = 0;
int zp_32 = 0;
int zp_41 = 0;
int zp_42 = 0;

List queue1; // очередь в 1ый цех
List queue2; // очередь в 2ый цех
List queue3; // очередь в 3ый цех
List queue4; // очередь в 4ый цех


List cars11; // cписок машин на то
List cars12;

List cars21; // список машин на кузовной ремонт
List cars22;

List cars31; // список машин на шиномонтаж
List cars32;

List cars41; // список машин на ремонт двигателя
List cars42;


// работники
Car *mas11 = NULL;
Car *mas12 = NULL;

Car *mas21 = NULL;
Car *mas22 = NULL;

Car *mas31 = NULL;
Car *mas32 = NULL;

Car *mas41 = NULL;
Car *mas42 = NULL;


void Time_change() {
	if (chas != 20 || minute != "00")
	{
		if (stp == 1)
		{
			if (kk % 2 == 1)
			{
				//chas += 8;
				minute = "30";
			}
			else {
				minute = "00";
				chas++;
			}
		}
		else
		{
			if (kk % 2 == 0) {
				//chas += 8;
				minute = "30";
			}
			else {
				minute = "00";
				chas++;
			}
		}
	}

	else {
		chas = 8;
		if (kk % 2 == 1) {
			stp = 2;
		}
		else {
			stp = 1;
		}
	}
}


int dif11 = 0;
int dif12 = 0;

int dif21 = 0;
int dif22 = 0;

int dif31 = 0;
int dif32 = 0;

int dif41 = 0;
int dif42 = 0;

time_t time_now{ time(NULL) };
time_t time_end{ time(NULL) };




string date_to_day(time_t sec) //функция предразования времени в строку
{

	tm timeinfo;
	localtime_s(&timeinfo, &sec);

	char str[128];
	strftime(str, sizeof(str), "%a %d.%m.%Y %X", &timeinfo);

	return str;
}


void rep(int timeinday) {

	tm dt1;
	localtime_s(&dt1, &time_now);
	int fl = 0;

	if (mas11 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)   // для работника 1  цеха 1
	{
		if (mas11->GetTime() <= timeinday)
		{
			if (queue1.getCount() != 0)
			{
				if (queue1.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars11.push(queue1.FindToNumber(0));
					mas11 = queue1.FindToNumber(0);
					mas11->SetTime(dif11 + timeinday);
					queue1.del_number(0);
					dif11 = 0;
				}
				else
				{
					mas11 = NULL;
					queue1.del_number(0);
					dif11 += timeinday;
				}
			}
			else
			{
				mas11 = NULL;
			}
		}
		else
		{
			mas11->SetTime(timeinday);
		}
	}


	if (mas12 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)  // для работника 2  цеха 1
	{
		if (mas12->GetTime() <= timeinday)
		{
			if (queue1.getCount() != 0)
			{
				if (queue1.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars12.push(queue1.FindToNumber(0));
					mas12 = queue1.FindToNumber(0);
					mas12->SetTime(dif12 + timeinday);
					queue1.del_number(0);
					dif12 = 0;
				}
				else
				{
					mas12 = NULL;
					queue1.del_number(0);
					dif12 += timeinday;
				}
			}
			else
			{
				mas12 = NULL;
			}
		}
		else
		{
			mas12->SetTime(timeinday);
		}

	}

	if (mas21 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)   // для работника 1  цеха 2
	{
		if (mas21->GetTime() <= timeinday)
		{
			if (queue2.getCount() != 0)
			{
				if (queue2.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars21.push(queue2.FindToNumber(0));
					mas21 = queue2.FindToNumber(0);
					mas21->SetTime(dif21 + timeinday);
					queue2.del_number(0);
					dif21 = 0;
				}
				else
				{
					mas21 = NULL;
					queue2.del_number(0);
					dif21 += timeinday;
				}
			}
			else
			{
				mas21 = NULL;
			}
		}
		else
		{
			mas21->SetTime(timeinday);
		}
	}


	if (mas22 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)    // для работника 2  цеха 2
	{
		if (mas22->GetTime() <= timeinday)
		{

			if (queue2.getCount() != 0)
			{
				if (queue2.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars21.push(queue2.FindToNumber(0));
					mas22 = queue2.FindToNumber(0);
					mas22->SetTime(dif22 + timeinday);
					queue2.del_number(0);
					dif22 = 0;
				}
				else
				{
					mas22 = NULL;
					queue2.del_number(0);
					dif22 += timeinday;
				}
			}
			else
			{
				mas22 = NULL;
			}
		}
		else
		{
			mas22->SetTime(timeinday);
		}
	}

	if (mas31 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)   // для работника 1  цеха 3
	{
		if (mas31->GetTime() <= timeinday)
		{

			if (queue3.getCount() != 0)
			{
				if (queue3.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars31.push(queue3.FindToNumber(0));
					mas31 = queue3.FindToNumber(0);
					mas31->SetTime(dif31 + timeinday);
					queue3.del_number(0);
					dif31 = 0;
				}
				else
				{
					mas31 = NULL;
					queue3.del_number(0);
					dif31 += timeinday;
				}
			}
			else
			{
				mas31 = NULL;
			}
		}
		else
		{
			mas31->SetTime(timeinday);
		}
	}




	if (mas32 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)    // для работника 2  цеха 3
	{
		if (mas32->GetTime() <= timeinday)
		{

			if (queue3.getCount() != 0)
			{
				if (queue3.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars32.push(queue3.FindToNumber(0));
					mas32 = queue3.FindToNumber(0);
					mas32->SetTime(dif32 + timeinday);
					queue3.del_number(0);
					dif32 = 0;
				}
				else
				{
					mas32 = NULL;
					queue3.del_number(0);
					dif32 += timeinday;
				}
			}
			else
			{
				mas32 = NULL;
			}
		}
		else
		{
			mas32->SetTime(timeinday);
		}
	}


	if (mas41 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)   // для работника 1  цеха 4
	{
		if (mas41->GetTime() <= timeinday)
		{

			if (queue4.getCount() != 0)
			{
				if (queue4.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars41.push(queue4.FindToNumber(0));
					mas41 = queue4.FindToNumber(0);
					mas41->SetTime(dif31 + timeinday);
					queue4.del_number(0);
					dif41 = 0;
				}
				else
				{
					mas41 = NULL;
					queue4.del_number(0);
					dif41 += timeinday;
				}
			}
			else
			{
				mas41 = NULL;
			}
		}
		else
		{
			mas41->SetTime(timeinday);
		}
	}

	if (mas42 != NULL && dt1.tm_hour * 60 + dt1.tm_min != 480)   // для работника 2  цеха 4
	{
		if (mas42->GetTime() <= timeinday)
		{

			if (queue4.getCount() != 0)
			{
				if (queue4.FindToNumber(0)->GetTime() * 60 + time_now <= time_end)
				{
					cars42.push(queue4.FindToNumber(0));
					mas42 = queue4.FindToNumber(0);
					mas42->SetTime(dif42 + timeinday);
					queue4.del_number(0);
					dif42 = 0;
				}
				else
				{
					mas42 = NULL;
					queue4.del_number(0);
					dif42 += timeinday;
				}
			}
			else
			{
				mas42 = NULL;
			}
		}
		else
		{
			mas42->SetTime(timeinday);
		}
	}
}
int pr11 = 0;
int pr12 = 0;
int pr21 = 0;
int pr22 = 0;
int pr31 = 0;
int pr32 = 0;
int pr41 = 0;
int pr42 = 0;





void total() // итог каждого мастера за все услуги
{
	pr11 = 0;
	pr12 = 0;
	pr21 = 0;
	pr22 = 0;
	pr31 = 0;
	pr32 = 0;
	pr41 = 0;
	pr42 = 0;
	for (int i = 0; i < cars11.getCount(); i++)
	{
		pr11 += cars11.FindToNumber(i)->GetCost();
	}
	for (int i = 0; i < cars12.getCount(); i++)
	{
		pr12 += cars12.FindToNumber(i)->GetCost();
	}
	for (int i = 0; i < cars21.getCount(); i++)
	{
		pr21 += cars21.FindToNumber(i)->GetCost();
	}
	for (int i = 0; i < cars22.getCount(); i++)
	{
		pr22 += cars22.FindToNumber(i)->GetCost();
	}
	for (int i = 0; i < cars31.getCount(); i++)
	{
		pr31 += cars31.FindToNumber(i)->GetCost();
	}
	for (int i = 0; i < cars32.getCount(); i++)
	{
		pr32 += cars32.FindToNumber(i)->GetCost();
	}
	for (int i = 0; i < cars41.getCount(); i++)
	{
		pr41 += cars41.FindToNumber(i)->GetCost();
	}
	for (int i = 0; i < cars42.getCount(); i++)
	{
		pr42 += cars42.FindToNumber(i)->GetCost();
	}

}


void del_all() {
	int q1 = queue1.getCount(), q2 = queue2.getCount();
	int q3 = queue3.getCount(), q4 = queue4.getCount();

	

	if (q1 == 5)
	{
		queue1.del_number(4);
		queue1.del_number(3);
		queue1.del_number(2);
		queue1.del_number(1);
		queue1.del_number(0);
	}
	else if (q1 == 4)
	{
		queue1.del_number(3);
		queue1.del_number(2);
		queue1.del_number(1);
		queue1.del_number(0);
	}
	else if (q1 == 3)
	{
		queue1.del_number(2);
		queue1.del_number(1);
		queue1.del_number(0);
	}
	else if (q1 == 2)
	{
		queue1.del_number(1);
		queue1.del_number(0);
	}
	else if (q1 == 1)
	{
		queue1.del_number(0);
	}


	if (q2 == 5)
	{
		queue2.del_number(4);
		queue2.del_number(3);
		queue2.del_number(2);
		queue2.del_number(1);
		queue2.del_number(0);
	}
	else if (q2 == 4)
	{
		queue2.del_number(3);
		queue2.del_number(2);
		queue2.del_number(1);
		queue2.del_number(0);
	}
	else if (q2 == 3)
	{
		queue2.del_number(2);
		queue2.del_number(1);
		queue2.del_number(0);
	}
	else if (q2 == 2)
	{
		queue2.del_number(1);
		queue2.del_number(0);
	}
	else if (q2 == 1)
	{
		queue2.del_number(0);
	}

	if (q3 == 5)
	{
		queue3.del_number(4);
		queue3.del_number(3);
		queue3.del_number(2);
		queue3.del_number(1);
		queue3.del_number(0);
	}
	else if (q3 == 4)
	{
		queue3.del_number(3);
		queue3.del_number(2);
		queue3.del_number(1);
		queue3.del_number(0);
	}
	else if (q3 == 3)
	{
		queue3.del_number(2);
		queue3.del_number(1);
		queue3.del_number(0);
	}
	else if (q3 == 2)
	{
		queue3.del_number(1);
		queue3.del_number(0);
	}
	else if (q3 == 1)
	{
		queue3.del_number(0);
	}
	if (q4 == 5)
	{
		queue4.del_number(4);
		queue4.del_number(3);
		queue4.del_number(2);
		queue4.del_number(1);
		queue4.del_number(0);
	}
	else if (q4 == 4)
	{
		queue4.del_number(3);
		queue4.del_number(2);
		queue4.del_number(1);
		queue4.del_number(0);
	}
	else if (q4 == 3)
	{
		queue4.del_number(2);
		queue4.del_number(1);
		queue4.del_number(0);
	}
	else if (q4 == 2)
	{
		queue4.del_number(1);
		queue4.del_number(0);
	}
	else if (q4 == 1)
	{
		queue4.del_number(0);
	}

}
