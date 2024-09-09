#ifndef TRUCK_H
#define TRUCK_H

#include "CropFieldInterface.h"
#include <iostream>
class Truck
{
private:
	std::string name;
public:
	Truck(std::string name) : name(name) {}
	virtual void callTruck() = 0;
	virtual void startEngine() = 0;
	virtual void buyTruck() = 0;
	virtual void sellTruck() = 0;
	std::string getName() { return name; }
};
#endif /*TRUCK_H*/

