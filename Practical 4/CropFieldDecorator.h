#ifndef CROPFIELDDECORATOR_H
#define CROPFIELDDECORATOR_H
#include "FarmUnit.h"
#include "FruitfulSoil.h"

class CropFieldDecorator :
    public FarmUnit
{
protected:
    FarmUnit* wrappedField;

public:
    CropFieldDecorator(FarmUnit* field) : FarmUnit("") {
        wrappedField = field;  
    }
    virtual void increaseProduction() override {
        wrappedField->increaseProduction();
    }
    virtual void harvest() override {
        wrappedField->harvest();
    }
    virtual int getLeftOverCapacity() override {
        return wrappedField->getLeftOverCapacity();
    }
    virtual ~CropFieldDecorator() {};
};
#endif

