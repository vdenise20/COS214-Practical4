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
	virtual int getTotalCapacity() const { return 0; };
	virtual string getCropType() { return ""; }
	virtual string getSoilStateName() { return ""; }
	virtual void rain() {}
	virtual void harvestCrops() {}
	virtual void add(FarmUnit* unit) {};
	virtual void remove(FarmUnit* unit) {};
	virtual vector<FarmUnit*> getChildren() {};
};
#endif /*FARMUNIT_H*/

