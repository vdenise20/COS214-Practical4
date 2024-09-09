#ifndef TRUCK_H
#define TRUCK_H

#include "CropFieldInterface.h"
#
class Truck
{
private:
	string name;
public:
	Truck(string name) : name(name) {}
	virtual void callTruck() = 0;
	virtual void startEngine() = 0;
	virtual void buyTruck() = 0;
	virtual void sellTruck() = 0;
	string getName() { return name; }
};
#endif /*TRUCK_H*/

