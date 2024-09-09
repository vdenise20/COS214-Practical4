#ifndef FARMUNIT_H
#define	FARMUNIT_H

#include <iostream>
#include <vector>

class CropField;
class SoilState;
using namespace std;

#include <algorithm>
#include <iostream>

class FarmIterator;
class DepthFirstIterator;
class BreadthFirstIterator;
class Truck;
class FarmUnit
{
private:
	string name;
	std::vector<Truck*> observerList;
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
	virtual vector<FarmUnit*> getChildren() { return {}; }
	virtual void increaseProduction() {};
	virtual void harvest() {};
	virtual int getLeftOverCapacity() { return 0; };
	void attach(Truck* observer);
	void detach(Truck* observer);
	void notify(std::string name);
	virtual SoilState* getState() { return NULL; }
	virtual void setState(SoilState* newState) {}
	virtual void updateCurrentCrops(int num) {};
	virtual int getYield() {
		return 0;
	}
	virtual FarmIterator* createBreadthIterator() { return NULL; };
	virtual FarmIterator* createDepthIterator() {
		return NULL;
	};

};
#endif /*FARMUNIT_H*/

