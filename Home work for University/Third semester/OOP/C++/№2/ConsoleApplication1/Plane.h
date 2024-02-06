#pragma once
#include "Transport.h"

class Plane : public Transport {

public:
	int BodyHealth;// ����������� ��������
	string AirCompany; // ������������ ���������
	int TopSpeed; //������������ ��������
	int TopHigh;// ������������ ������ �����
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
			cout << "������������ ������� ������������ � " << t << " �� " << AirCompany << endl;
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
		return out << " ������ �����: " << AirCompany << " ����� ������������ ��������  "
			<< TopSpeed << " ������������ ������ ����� " << TopHigh << " ������� �������� �� " << BodyHealth << " % "
			<<" ��������� � "<<YearOfIssue<< " ��������� "<<Power<<endl;
	}
	void FiXBody(string ok) {
		if (BodyHealth == 100) {
			cout << "\n" << "������� � �������� ���������, ��� ������������� �� ������" << endl;
		}
		else {
			BodyHealth = 100;
			cout << "\n" << "������������ ����������� ������� ������� �� ��������� ������" << endl;
		}
	}
	void SetLight(string light) {
		if (light == "������� ���������")
			cout << "\n" << "������������ ������� ����� ��������� � ������ � ������ �������" << "\n";
		else
			cout << "������ �����";
	}
	void startEngine(string on) {
		if (on == "�������� ���������" || on == "�������� ����������")
			cout << "\n" << "������������ " << on << endl;
		else {
			cout << "������ �����";
		}
	}

	void carryOrPas(Plane* b, TypeOfTransport* k) {
		if (b->getPower() >= 2000 || k->getLiftCap() == 10000) {
			cout << " ��������� ���� " << b->getType() << " �������� ��������" << endl;
		}
		else {
			cout << " ��������� ���� " << b->getType() << " �������� ������������" << endl;
		}

	}

};