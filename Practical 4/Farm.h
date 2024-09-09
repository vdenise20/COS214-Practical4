#ifndef FARM_H
#define FARM_H
#include "FarmUnit.h"
#include <vector>
class Farm :
    public FarmUnit
{
private:
    vector<FarmUnit*> units;

public: 
    Farm(std::string name) : FarmUnit(name) {}
    int getTotalCapacity() const override;
    string getName() const ;
    void add(FarmUnit* unit) override;
    void remove(FarmUnit* unit) override;
    vector<FarmUnit*> getChildren() override;
};
#endif /*FARM_H*/

