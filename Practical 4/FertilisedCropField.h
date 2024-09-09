#ifndef FERTILISEDCROPFIELD_H
#define FERTILISEDCROPFIELD_H
#include "CropFieldDecorator.h"
class FertilisedCropField :
    public CropFieldDecorator
{
public:
    void increaseProduction() override;
    void harvest() override;
};
#endif

