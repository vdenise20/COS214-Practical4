#ifndef CROPFIELDINTERFACE_H
#define CROPFIELDINTERFACE_H

#include <vector>
#include <algorithm>
#include <iostream>

class Truck;
class CropFieldInterface
{
private:
    std::vector<Truck*> observerList;

public:
    virtual ~CropFieldInterface() = default;  // Ensure the base class has a virtual destructor
    virtual void increaseProduction() = 0;
    virtual void harvest() = 0;
    virtual int getLeftOverCapacity() = 0;
    void attach(Truck* observer);
    void detach(Truck* observer);
    void notify(std::string name);
};

#endif /* CROPFIELDINTERFACE_H */
