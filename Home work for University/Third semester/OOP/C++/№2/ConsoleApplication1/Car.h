#pragma once
#include "Transport.h"
class Car : public Transport  {
public:
	string RimColor;
	string Tires; //����� ���
	string Brand;
	int Aceleration; // ����� ������� �� 100 ��\�
	Car() {}
	Car(string B, string RC, string Ti,int A, string t, string c, int p, int y) : Transport(t, c, p, y) {
		Brand = B;
		RimColor = RC;
		Tires= Ti;
		Aceleration = A;
	}
	Car(const Car& car) : Transport((const_cast<Car&>(car)).getType(), (const_cast<Car&>(car)).getColor(), 
		(const_cast<Car&>(car)).getPower(), (const_cast<Car&>(car)).getYearOfIssue())
	{
		Brand = car.Brand;
		RimColor = car.RimColor;
		Tires = car.Tires;
		Aceleration = car.Aceleration;
	}
	string getRimColor() { return RimColor; }
	string getBrand() { return Brand; }
	string getTires() { return Tires; }
	int getAceleration() { return Aceleration; }

	void ChangeTiers(string newt) {
		string gg; gg = Tires;
		Tires = newt;
		cout << " ������������ ������ ���� �� ���������� � " << gg << " �� " << Tires << endl;
	}
	bool similarity(Car& p) {
		return (RimColor == p.getRimColor() && Brand == p.getBrand() && Tires == p.getTires() && Aceleration == p.getAceleration());
	}
	friend ostream& operator<< (ostream& out, Car& p)
	{
		return p.print(out);
	}

	virtual ostream& print(ostream& out) {
		return out << " ���������� �����: " << Brand << " ����� ����� �����: " << RimColor << " �� ����� �����: " << Tires << " ����������� �� 100 �� " << Aceleration << " � " <<
			" ��������� " << Power << "�/� ���� ������������ " << YearOfIssue <<" �. " <<endl;
	}
	void ChangeRimColor(string col) {
		string kk; kk = RimColor; RimColor = col;
		cout << " ������������ ������ ���� ������ �� ���������� "<<getBrand()<< " � " << kk << " �� " << RimColor << endl;
	}
	void StartStop(string on) {
		if (on == " �������� ��������� " || on == " �������� ��������� ") {
			cout << "\n" << " ������������ " << on <<"� ����������" << getBrand() << endl;
		}
		else {
			cout << "������ �����";
		}
	}

	
};


