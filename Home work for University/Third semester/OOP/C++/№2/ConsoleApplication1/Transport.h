#pragma once
using namespace std;

#include <iostream>
#include <stdlib.h>

class Transport {
private:
	string Type;//��� ��
	string Color; // ���� ��
protected:
	int Power; //�������� ��
	int YearOfIssue; // ��� �������
public:
	Transport() {}
	Transport(string t, string c, int p, int y) : Type(t), Color(c), Power(p), YearOfIssue(y) {}

	int getPower() { return Power; }
	int getYearOfIssue() { return YearOfIssue; }
	string getType() { return Type; }
	string getColor() { return Color; }

	// ������� ���������

	virtual bool operator==(Transport& p) {
		return (Type == p.getType() && Color == p.getColor() && Power == p.getPower() && YearOfIssue == p.getYearOfIssue());
	}

	virtual std::ostream& print(ostream& out) {
		return out << "���������  ���� " << Type << " ����� ���� " << Color << " ����� �������� " << Power << " ��� ������� " << YearOfIssue << "\n";
	}

	friend ostream& operator<< (ostream& out, Transport& p)
	{
		return p.print(out);
	}
};


class TypeOfTransport {
private:
	
public:
	int Lifting_capacity; // ����������������
	static string PlaceOfHold; // ����� ������� 
	TypeOfTransport() {}
	TypeOfTransport(int l) : Lifting_capacity(l) {
		Lifting_capacity = l;
	
	}
	int getLiftCap() { return Lifting_capacity; }

	static string getPlaceOfHold() { return PlaceOfHold; }


	virtual bool operator == (TypeOfTransport& e) {
		return (Lifting_capacity == e.getLiftCap());
	}
	virtual std::ostream& print(ostream& out) {
		return out << " ����������������" << Lifting_capacity << "\n";
	}

	friend ostream& operator<< (ostream& out, TypeOfTransport& e)
	{
		return e.print(out);
	}
};

class Passengers : public TypeOfTransport {
	
public:
	static string Pas;
	int kolpas;
	int kolmest;
	
	Passengers() {}
	Passengers(int kp, int km, int l) : TypeOfTransport(l) {
		kolpas = kp;
		kolmest = km;
		
	}
	Passengers(const Passengers& pas): TypeOfTransport((const_cast<Passengers&>(pas)).getLiftCap()){}
	int getKolMest() { return kolmest; }
	int getKolPas() { return kolpas; }
	string getTypeOf() { return Pas; }

	virtual bool operator == (Passengers& e) {
		return (Lifting_capacity == e.getLiftCap() && kolpas == e.getKolPas() && kolmest == e.getKolMest());
	}
	virtual std::ostream& print(ostream& out) {
		return out << " ��� ����������" << Pas << " ����������� ����������" << kolpas << " ����������� ����" << kolmest << "\n";
	}

	friend ostream& operator<< (ostream& out, Passengers& e)
	{
		return e.print(out);
	}

};

class Cargo : public TypeOfTransport {

public:
	static string cargo;
	int volcarg;
	Cargo() {}
	Cargo(int vc, int l) : TypeOfTransport(l) {
		volcarg = vc;
	}
	Cargo(const Cargo& pas) : TypeOfTransport((const_cast<Cargo&>(pas)).getLiftCap()) {}
	int getVolumeCargo() { return volcarg; }

	virtual bool operator == (Cargo& e) {
		return (Lifting_capacity == e.getLiftCap());
	}
	virtual std::ostream& print(ostream& out) {
		return out << " ��� ���������� " << cargo << " ����� ����� " << volcarg << "\n";
	}

	friend ostream& operator<< (ostream& out, Cargo& e)
	{
		return e.print(out);
	}

};






