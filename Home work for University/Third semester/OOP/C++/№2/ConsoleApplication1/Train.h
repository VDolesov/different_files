#pragma once
#include "Transport.h"

class Train : public Transport {
public:
	int BreakHealth;// исправность тормозов от 0 до 100 процентов
	string TrCompany; // наименование типа окраса
	int Length; //длинна состава (Колличество вагонов)
	Train() {}
	// Transport(string t, string c, int p, int y ) : Type(t), Color(c), Power(p), YearOfIssue(y) {}
	Train(int BH, string TC, int L, string t, string c, int p, int y) : Transport(t, c, p, y) {
		BreakHealth = BH;
		TrCompany = TC;
		Length = L;
	}
	int getBreakHealth() { return BreakHealth; }
	string getTrCompany() { return TrCompany; }
	int getLength() { return Length; }

	void ChangeLength(int k) {
		if (Length != k && k != 0) {
			int kk; kk = Length; Length=k;
			cout << "Пользователь изменил число вагонов с " << kk << " на " << Length << endl;
		}

	}
	bool similarity(Train& p) {
		return (BreakHealth == p.getBreakHealth() && TrCompany == p.getTrCompany() &&
			Length == p.getLength());
	}
	friend ostream& operator<< (ostream& out, Train& p)
	{
		return p.print(out);
	}

	virtual ostream& print(ostream& out) {
		return out << "Поезд окраса фирмы: " << TrCompany << " имеет  " << Length << " вагонов " << " исправность тормозов локомтива :" << BreakHealth << " %"
			<< " мощностью " << Power << " был произведён " << YearOfIssue << endl;
	}
	void FiXBreaks(string ok) {
		if (BreakHealth == 100) {
			cout << "\n" << " Томроза в отличном состоянии, нет необходимости их менять " << endl;
		}
		else {
			BreakHealth = 100;
			cout << "\n" << " Пользователь поменял тормоза на локомотиве "<<getTrCompany()<< " на новые " << endl;
		}
	}
	void Horn(string on) {
		cout << "\n" << " Пользователь нажал на гудок и локомотив издал приятный для ушей звук " << "\n";
	}
};