#ifndef CROPFIELDINTERFACE
#define CROPFIELDINTERFACE

#include "Truck.h"
#include "SoilState.h"
class CropFieldInterface
{
private:
	vector<Truck*> observerList;

public:
	virtual void increaseProduction() = 0;
	virtual void harvest() = 0;
	virtual int getLeftOverCapacity() = 0;
	void attach(Truck* observer) { 
		observerList.push_back(observer); 
		std::cout << "A truck has been attached to the CropField.\n";
	}
	void detach(Truck* observer) { 
		observerList.erase(std::remove(observerList.begin(), observerList.end(), observer), observerList.end()); 
		std::cout << "A truck has been detached from the CropField.\n";
	}
	void notify(string name) {
		std::cout << "Notifying trucks...\n";
		for (Truck* observer : observerList) {  // Use the protected getter to access the list
			if(observer->getName() == name)
				observer->callTruck();  // Call the update method on each observer (truck)
		}
	};
};
#endif /*CROPFIELDINTERFACE*/

