#pragma once
using namespace std;

#include <iostream>
#include <stdlib.h>

class Transport {
private:
	string Type;//тип тс
	string Color; // цвет тс
protected:
	int Power; //мощность тс
	int YearOfIssue; // год выпуска
public:
	Transport() {}
	Transport(string t, string c, int p, int y) : Type(t), Color(c), Power(p), YearOfIssue(y) {}

	int getPower() { return Power; }
	int getYearOfIssue() { return YearOfIssue; }
	string getType() { return Type; }
	string getColor() { return Color; }

	// сравним транспорт

	virtual bool operator==(Transport& p) {
		return (Type == p.getType() && Color == p.getColor() && Power == p.getPower() && YearOfIssue == p.getYearOfIssue());
	}

	virtual std::ostream& print(ostream& out) {
		return out << "Транспорт  вида " << Type << " имеет цвет " << Color << " имеет мощность " << Power << " год выпуска " << YearOfIssue << "\n";
	}

	friend ostream& operator<< (ostream& out, Transport& p)
	{
		return p.print(out);
	}
};


class TypeOfTransport {
private:
	
public:
	int Lifting_capacity; // грузоподъёмность
	static string PlaceOfHold; // место стоянки 
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
		return out << " грузоподъёмность" << Lifting_capacity << "\n";
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
		return out << " Тип транспорта" << Pas << " колличество пассажиров" << kolpas << " колличество мест" << kolmest << "\n";
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
		return out << " Тип транспорта " << cargo << " объём груза " << volcarg << "\n";
	}

	friend ostream& operator<< (ostream& out, Cargo& e)
	{
		return e.print(out);
	}

};






