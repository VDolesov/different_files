#include <typeinfo>

#include "Transport.h"
#include "Car.h"
#include "Plane.h"
#include "Train.h"


//Сars
bool CondColorAndTires(Transport* s) {
	Car* cr = dynamic_cast<Car*>(s);
	if (cr)
		return (cr->getRimColor() == "Grey" && cr->getTires() == "Bridgestone");
	else return false;
}

bool CondColorAndBrand(Transport* s) {
	Car* cr = dynamic_cast<Car*>(s);
	if (cr)
		return (cr->getRimColor() == "Black" && cr->getBrand() == "Mercedes");
	else return false;
}

string getCL(Transport* var) { // узнаём имя класса
	return typeid(*var).name();
}

bool CondTrain(Transport* s) {
	if (getCL(s) == "class Train")
		return (((Train*)s)->getBreakHealth() == 100 && ((Train*)s)->getLength() >= 7);
	else return false;
}

bool CondCar(Transport* s) {
	if (getCL(s) == "class Car")
		return (((Car*)s)->getAceleration()<=8 && ((Car*)s)->getTires() == "NokianBlack");
	else return false;
}

bool CondPlane(Transport* s) {
	if (getCL(s) == "class Plane")
		return (((Plane*)s)->getAirCompany() == "A7" && ((Plane*)s)->getTopSpeed()>=390);
	else return false;
}
