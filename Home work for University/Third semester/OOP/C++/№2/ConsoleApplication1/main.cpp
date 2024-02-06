//Создать базовый класс «Транспорт» и производные от него классы «Автомобиль»,
//«Поезд», «Самолет».Создать базовый класс «Тип» и производные от него классы «Грузовой» и «Пассажирский».
//На основе этих классов создать набор различных классов с использованием множественного наследования.




using namespace std;

#include<iostream>
#include<stdlib.h>
#include<time.h>

#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Plane.h"
#include "Classes.h"


string TypeOfTransport::PlaceOfHold = "МуGarage";
string Passengers::Pas = "Пассажирский";
string Cargo::cargo = "Грузовой";

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	cout << "В ангаре стоит несколько транспортных средств :\n";
	//return out << "Автомобиль марки: " << Brand << " имеет диски цвета: " << RimColor << "на шинах марки: " << Tires 
	// << "разгоняется до 100 за" << Aceleration << " с./n" <<
	//" мощностью" << Power << " дата производства " << YearOfIssue << endl;

	// Car(string B, string RC, string Ti,int A, string t, string c, int p, int y) : Transport(t, c, p, y) {
	//CarPas(string B, string RC, string Ti, int A, string t, string c, int p, int y, int kp, int km, int l)
	CarPas c1p("Ford", "зелёный", "Hankok", 13, "Автомобиль", "Красный", 189, 2010,18,18,25000);
	cout << c1p;
	CarPas c2p("Mercedes", "хром", "Nokian", 7, "Автомобиль", "Коричневый", 278, 2014, 4, 7, 17800);
	cout << c2p;
	CarPas с3p("Subaru", "чёрный", "Pirelli", 4, "Автомобиль", "черный", 150, 2012, 6, 14, 20000);
	cout << с3p;
	Car c3("AUDI", "сталь", "Pirelli", 4, "Автомобиль", "Чёрный", 249, 2016);
	cout << c3;
	Car c4("BMW", "красный", "Continental", 6, "Автомобиль", "Чёрный", 390, 2021);
	cout << c4;
	cout << endl;
	c2p.StartStop("запустил двигатель");
	c4.ChangeRimColor("Белые");
	c1p.ChangeTiers("LingLong");
	cout << endl;
	// 
	// 
	//Train(int BH, string TC, int L, string t, string c, int p, int y) : Transport(t, c, p, y) {
	//TrainCargo(int BH, string TC, int L,  string t, string c, int p, int y, int vc, int l) 
	Train t1(78, "Аллегро", 8, "Поезд", "черный", 9000, 2012);
	cout << t1;
	Train t2(100, "Арктика", 20, "Поезд", "красный", 12000, 2019);
	cout << t2 << endl;
	TrainCargo t3c(26, "Волга",12,"Поезд", "желтый", 6000, 2018,2500,7500);
	cout << t3c;
	TrainCargo t4c(65, "Вятка", 23, "Поезд", "серый", 7000, 2016,2800,80000);
	cout << t4c;
	t3c.FiXBreaks("ok");
	t4c.ChangeLength(5); 
	t1.Horn("on"); cout << endl;

	//Plane(int bh, string ac, int ts, int th, string t, string c, int p, int y) : Transport(t, c, p, y) {
	//PlanePas(int bh, string ac, int ts, int th, string t, string c, int p, int y, int kp, int km, int l)
	PlanePas p1c(85, "A7", 900, 8000, "Самолёт", "Белый", 1000, 2019,60,70,29000);
	cout << p1c;
	PlanePas p2c(79, "Аэрофлот", 900, 9000, "Самолёт", "Белый", 2000, 2021,90,120,34000);
	cout << p2c;
	PlanePas p3c(23, "Победа", 900, 7500, "Самолёт", "Белый", 3000, 2015,80,90,25000);
	cout << p3c;
	Plane p4(99, "СмартАвиа", 900, 10000, "Самолёт", "Белый", 1500, 2023);
	cout << p4;
	p1c.ChangeAirCompany("S7айрлайнс");
	p2c.FiXBody("ok");
	p3c.SetLight("включил освещение");
	p4.startEngine("запустил двигатели");
	return 0;
}

