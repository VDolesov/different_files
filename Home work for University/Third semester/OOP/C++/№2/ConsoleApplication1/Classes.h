#pragma once
#pragma once
#include "Transport.h"
#include "Car.h"
#include "Plane.h"
#include "Train.h"

class CarPas : public Car, public Passengers {

public:

	CarPas() {}
	//Car(string B, string RC, string Ti,int A, string t, string c, int p, int y)
	//Passengers(int kp, int km, int l) : TypeOfTransport(l) {
	CarPas(string B, string RC, string Ti, int A, string t, string c,
		int p, int y, int kp, int km, int l) : Car(B, RC, Ti, A, t, c, p, y), Passengers (kp, km, l) {
	}
	CarPas(const CarPas& CarP) : Car((const_cast<CarPas&>(CarP)).getBrand(), (const_cast<CarPas&>(CarP)).getRimColor(),
		(const_cast<CarPas&>(CarP)).getTires(), (const_cast<CarPas&>(CarP)).getAceleration(),
		(const_cast<CarPas&>(CarP)).getType(), (const_cast<CarPas&>(CarP)).getColor(),
		(const_cast<CarPas&>(CarP)).getPower(), (const_cast<CarPas&>(CarP)).getYearOfIssue()), 
		Passengers((const_cast<CarPas&>(CarP)).getKolPas(), (const_cast<CarPas&>(CarP)).getKolMest(),
		(const_cast<CarPas&>(CarP)).getLiftCap())
	{}
	

	virtual std::ostream& print(ostream& out) {
		// TypeOf наследуется от ТИПА ГРУЗОВОЙ ПАССАЖИРСКИЙ

		return out <<Pas<< " Наименование тс " << Brand << " года выпуска " << YearOfIssue << " с колличеством пассажиров  "
			<< kolpas<< " общей допустимой массой " << Lifting_capacity << endl;
	}

	friend ostream& operator<< (ostream& out, CarPas& e)
	{
		return e.print(out);
	}

};

class PlanePas : public Plane, public Passengers {

public:
	PlanePas() {}
	//Plane(int bh, string ac, int ts, int th, string t, string c, int p, int y) 
	//Passengers(int kp, int km, int l) : TypeOfTransport(l) {
	PlanePas(int bh, string ac, int ts, int th, string t, string c,
		int p, int y, int kp, int km, int l) : Plane(bh,ac,ts,th, t, c, p, y), Passengers(kp, km, l) {
	}
	PlanePas(const PlanePas& PlaneP) : Plane((const_cast<PlanePas&>(PlaneP)).getBodyHealth(),
		(const_cast<PlanePas&>(PlaneP)).getAirCompany(),(const_cast<PlanePas&>(PlaneP)).getTopSpeed(),
		(const_cast<PlanePas&>(PlaneP)).getTopHigh(),(const_cast<PlanePas&>(PlaneP)).getType(),
		(const_cast<PlanePas&>(PlaneP)).getColor(),(const_cast<PlanePas&>(PlaneP)).getPower(),
		(const_cast<PlanePas&>(PlaneP)).getYearOfIssue()),
		Passengers((const_cast<PlanePas&>(PlaneP)).getKolPas(), (const_cast<PlanePas&>(PlaneP)).getKolMest(),
		(const_cast<PlanePas&>(PlaneP)).getLiftCap())
	{
	}


	virtual std::ostream& print(ostream& out) {
		// TypeOf наследуется от ТИПА ГРУЗОВОЙ ПАССАЖИРСКИЙ

		return out << Pas << " Наименование самолёта " << AirCompany << " года выпуска " << YearOfIssue << " с колличеством пассажиров  "
			<< kolpas << " общей допустимой массой " << Lifting_capacity << endl;
	}

	friend ostream& operator<< (ostream& out, PlanePas& e)
	{
		return e.print(out);
	}

};

class TrainCargo : public Train, public Cargo {

public:

	TrainCargo() {}
	//Train(int BH, string TC, int L, string t, string c, int p, int y)
	//Cargo(int vc, int l) : TypeOfTransport(l) {
	TrainCargo(int BH, string TC, int L,  string t, string c,
		int p, int y, int vc, int l) : Train(BH, TC, L, t, c, p, y), Cargo(vc, l) {
	}
	TrainCargo(const TrainCargo& TrainC) : Train((const_cast<TrainCargo&>(TrainC)).getBreakHealth(),
		(const_cast<TrainCargo&>(TrainC)).getTrCompany(), (const_cast<TrainCargo&>(TrainC)).getLength(),
		(const_cast<TrainCargo&>(TrainC)).getType(), (const_cast<TrainCargo&>(TrainC)).getColor(),
		(const_cast<TrainCargo&>(TrainC)).getPower(), (const_cast<TrainCargo&>(TrainC)).getYearOfIssue()),
		Cargo((const_cast<TrainCargo&>(TrainC)).getVolumeCargo(), (const_cast<TrainCargo&>(TrainC)).getLiftCap())
	{
	}


	virtual std::ostream& print(ostream& out) {
		// TypeOf наследуется от ТИПА ГРУЗОВОЙ ПАССАЖИРСКИЙ

		return out << cargo << " Наименование поезда " << TrCompany << " года выпуска " << YearOfIssue << " с допустимым объёмом грузом  "
			<< volcarg << " общей допустимой массой " << Lifting_capacity << endl;
	}

	friend ostream& operator<< (ostream& out, TrainCargo& e)
	{
		return e.print(out);
	}

};