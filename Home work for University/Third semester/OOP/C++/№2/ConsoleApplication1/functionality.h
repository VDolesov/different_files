#pragma once

#include "Transport.h"
#include "Car.h"
#include "Plane.h"
#include "Train.h"

bool CondColorAndTires(Transport* s);

bool CondColorAndBrand(Transport* s);

bool CondTrain(Transport* s);

bool CondPlane(Transport* s);

bool CondCar(Transport* s);
