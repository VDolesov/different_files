//������� ������� ����� ���������� � ����������� �� ���� ������ ������������,
//������, ��������.������� ������� ����� ���� � ����������� �� ���� ������ ��������� � �������������.
//�� ������ ���� ������� ������� ����� ��������� ������� � �������������� �������������� ������������.




using namespace std;

#include<iostream>
#include<stdlib.h>
#include<time.h>

#include "Transport.h"
#include "Car.h"
#include "Train.h"
#include "Plane.h"
#include "Classes.h"


string TypeOfTransport::PlaceOfHold = "��Garage";
string Passengers::Pas = "������������";
string Cargo::cargo = "��������";

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	cout << "� ������ ����� ��������� ������������ ������� :\n";
	//return out << "���������� �����: " << Brand << " ����� ����� �����: " << RimColor << "�� ����� �����: " << Tires 
	// << "����������� �� 100 ��" << Aceleration << " �./n" <<
	//" ���������" << Power << " ���� ������������ " << YearOfIssue << endl;

	// Car(string B, string RC, string Ti,int A, string t, string c, int p, int y) : Transport(t, c, p, y) {
	//CarPas(string B, string RC, string Ti, int A, string t, string c, int p, int y, int kp, int km, int l)
	CarPas c1p("Ford", "������", "Hankok", 13, "����������", "�������", 189, 2010,18,18,25000);
	cout << c1p;
	CarPas c2p("Mercedes", "����", "Nokian", 7, "����������", "����������", 278, 2014, 4, 7, 17800);
	cout << c2p;
	CarPas �3p("Subaru", "������", "Pirelli", 4, "����������", "������", 150, 2012, 6, 14, 20000);
	cout << �3p;
	Car c3("AUDI", "�����", "Pirelli", 4, "����������", "׸����", 249, 2016);
	cout << c3;
	Car c4("BMW", "�������", "Continental", 6, "����������", "׸����", 390, 2021);
	cout << c4;
	cout << endl;
	c2p.StartStop("�������� ���������");
	c4.ChangeRimColor("�����");
	c1p.ChangeTiers("LingLong");
	cout << endl;
	// 
	// 
	//Train(int BH, string TC, int L, string t, string c, int p, int y) : Transport(t, c, p, y) {
	//TrainCargo(int BH, string TC, int L,  string t, string c, int p, int y, int vc, int l) 
	Train t1(78, "�������", 8, "�����", "������", 9000, 2012);
	cout << t1;
	Train t2(100, "�������", 20, "�����", "�������", 12000, 2019);
	cout << t2 << endl;
	TrainCargo t3c(26, "�����",12,"�����", "������", 6000, 2018,2500,7500);
	cout << t3c;
	TrainCargo t4c(65, "�����", 23, "�����", "�����", 7000, 2016,2800,80000);
	cout << t4c;
	t3c.FiXBreaks("ok");
	t4c.ChangeLength(5); 
	t1.Horn("on"); cout << endl;

	//Plane(int bh, string ac, int ts, int th, string t, string c, int p, int y) : Transport(t, c, p, y) {
	//PlanePas(int bh, string ac, int ts, int th, string t, string c, int p, int y, int kp, int km, int l)
	PlanePas p1c(85, "A7", 900, 8000, "������", "�����", 1000, 2019,60,70,29000);
	cout << p1c;
	PlanePas p2c(79, "��������", 900, 9000, "������", "�����", 2000, 2021,90,120,34000);
	cout << p2c;
	PlanePas p3c(23, "������", 900, 7500, "������", "�����", 3000, 2015,80,90,25000);
	cout << p3c;
	Plane p4(99, "���������", 900, 10000, "������", "�����", 1500, 2023);
	cout << p4;
	p1c.ChangeAirCompany("S7��������");
	p2c.FiXBody("ok");
	p3c.SetLight("������� ���������");
	p4.startEngine("�������� ���������");
	return 0;
}

