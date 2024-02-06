#pragma once
#include "Transport.h"
class Car : public Transport  {
public:
	string RimColor;
	string Tires; //марка шин
	string Brand;
	int Aceleration; // время разгона до 100 км\ч
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
		cout << " Пользователь сменил шины на автомобиле с " << gg << " на " << Tires << endl;
	}
	bool similarity(Car& p) {
		return (RimColor == p.getRimColor() && Brand == p.getBrand() && Tires == p.getTires() && Aceleration == p.getAceleration());
	}
	friend ostream& operator<< (ostream& out, Car& p)
	{
		return p.print(out);
	}

	virtual ostream& print(ostream& out) {
		return out << " Автомобиль марки: " << Brand << " имеет диски цвета: " << RimColor << " на шинах марки: " << Tires << " разгоняется до 100 за " << Aceleration << " с " <<
			" мощностью " << Power << "л/с дата производства " << YearOfIssue <<" г. " <<endl;
	}
	void ChangeRimColor(string col) {
		string kk; kk = RimColor; RimColor = col;
		cout << " Пользователь сменил цвет дисков на автомобиле "<<getBrand()<< " с " << kk << " на " << RimColor << endl;
	}
	void StartStop(string on) {
		if (on == " запустил двигатель " || on == " заглушил двигатель ") {
			cout << "\n" << " Пользователь " << on <<"у автомобиля" << getBrand() << endl;
		}
		else {
			cout << "Ошибка ввода";
		}
	}

	
};


