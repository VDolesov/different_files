#pragma once
#include "Transport.h"

class Train : public Transport {
public:
	int BreakHealth;// ����������� �������� �� 0 �� 100 ���������
	string TrCompany; // ������������ ���� ������
	int Length; //������ ������� (����������� �������)
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
			cout << "������������ ������� ����� ������� � " << kk << " �� " << Length << endl;
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
		return out << "����� ������ �����: " << TrCompany << " �����  " << Length << " ������� " << " ����������� �������� ��������� :" << BreakHealth << " %"
			<< " ��������� " << Power << " ��� ��������� " << YearOfIssue << endl;
	}
	void FiXBreaks(string ok) {
		if (BreakHealth == 100) {
			cout << "\n" << " ������� � �������� ���������, ��� ������������� �� ������ " << endl;
		}
		else {
			BreakHealth = 100;
			cout << "\n" << " ������������ ������� ������� �� ���������� "<<getTrCompany()<< " �� ����� " << endl;
		}
	}
	void Horn(string on) {
		cout << "\n" << " ������������ ����� �� ����� � ��������� ����� �������� ��� ���� ���� " << "\n";
	}
};