#ifndef FARMUNIT_H
#define	FARMUNIT_H

#include <iostream>
#include <vector>
using namespace std;
class FarmUnit
{
private:
	string name;

public:
	FarmUnit(string name) : name(name) {};
	string getName() const { return name; }
	virtual int getTotalCapacity() const = 0;
	virtual string getSoilStateName() const = 0;
	virtual void updateCurrentCrops(int num) = 0;
	virtual void add(FarmUnit* unit);
	virtual void remove(FarmUnit* unit);
	virtual vector<FarmUnit*> getChildren() = 0;
};
#endif /*FARMUNIT_H*/

