#ifndef CROPFIELDDECORATOR_H
#define CROPFIELDDECORATOR_H
#include "CropFieldInterface.h"
#include "FruitfulSoil.h"
class CropField;
class CropFieldDecorator :
    public CropFieldInterface
{
protected:
    CropField* wrappedField;

public:
    CropFieldDecorator(CropField* field) : wrappedField(field) {}
    virtual void increaseProduction() override;
    virtual void harvest() override;
    virtual int getLeftOverCapacity() override;
    virtual ~CropFieldDecorator();
};
#endif

