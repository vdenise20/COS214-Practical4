#ifndef FERTILISEDCROPFIELD_H
#define FERTILISEDCROPFIELD_H
#include "CropFieldDecorator.h"
class FertilisedCropField :
    public CropFieldDecorator
{
private:
    FarmUnit* wrappedField;
public:
    FertilisedCropField(FarmUnit* wrappedField);
    void increaseProduction() override;
    void harvest() override;
};
#endif

