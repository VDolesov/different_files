#pragma once
#include "Transport.h"

class Plane : public Transport {

public:
	int BodyHealth;// исправность физюляжа
	string AirCompany; // наименование авиалиний
	int TopSpeed; //максимальная скорость
	int TopHigh;// максимальная высота полёта
	Plane() {}
	Plane(int bh, string ac, int ts, int th, string t, string c, int p, int y) : Transport(t, c, p, y) {
		BodyHealth = bh;
		AirCompany = ac;
		TopSpeed = ts;
		TopHigh = th;
	}
	int getBodyHealth() { return BodyHealth; }
	string getAirCompany() { return AirCompany; }
	int getTopSpeed() { return TopSpeed; }
	int getTopHigh() { return TopHigh; }

	void ChangeAirCompany(string k) {
		string t = AirCompany;
		if (AirCompany != k) {
			AirCompany = k;
			cout << "Пользователь изменил авиакомпанию с " << t << " на " << AirCompany << endl;
		}

	}
	bool similarity(Plane& p) {
		return (BodyHealth == p.getBodyHealth() && AirCompany == p.getAirCompany() &&
			TopSpeed == p.getTopSpeed()) && TopHigh == p.getTopHigh();
	}
	friend ostream& operator<< (ostream& out, Plane& p)
	{
		return p.print(out);
	}

	virtual ostream& print(ostream& out) {
		return out << " Самолёт фирмы: " << AirCompany << " имеет максимальную скорость  "
			<< TopSpeed << " максимальную высоту полёта " << TopHigh << " физюляж исправен на " << BodyHealth << " % "
			<<" произведён в "<<YearOfIssue<< " мощностью "<<Power<<endl;
	}
	void FiXBody(string ok) {
		if (BodyHealth == 100) {
			cout << "\n" << "Томроза в отличном состоянии, нет необходимости их менять" << endl;
		}
		else {
			BodyHealth = 100;
			cout << "\n" << "Пользователь восстановил физюляж самолёта до состояния нового" << endl;
		}
	}
	void SetLight(string light) {
		if (light == "включил освещение")
			cout << "\n" << "Пользователь включил общее освещение в салоне и кабине самолёта" << "\n";
		else
			cout << "ошибка ввода";
	}
	void startEngine(string on) {
		if (on == "запустил двигатели" || on == "заглушил двиагатели")
			cout << "\n" << "Пользователь " << on << endl;
		else {
			cout << "ошибка ввода";
		}
	}

	void carryOrPas(Plane* b, TypeOfTransport* k) {
		if (b->getPower() >= 2000 || k->getLiftCap() == 10000) {
			cout << " транспорт типа " << b->getType() << " является грузовым" << endl;
		}
		else {
			cout << " транспорт типа " << b->getType() << " является пассажирским" << endl;
		}

	}

};