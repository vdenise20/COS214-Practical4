#ifndef BARN_H
#define BARN_H
#include "FarmUnit.h"
class Barn :
    public FarmUnit
{
private:
    int totalCapacity;

public: 
    Barn(string name, int capacity) : FarmUnit(name) { totalCapacity = capacity; }
    int getTotalCapacity() const override;
};
#endif /*BARN_H*/

