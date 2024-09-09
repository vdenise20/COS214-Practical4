#ifndef EXTRABARNCROPFIELD_H
#define EXTRABARNCROPFIELD_H
#include "CropFieldDecorator.h"
class ExtraBarnCropField :
    public CropFieldDecorator
{
private:
    FarmUnit* wrappedField;
public:
    ExtraBarnCropField(FarmUnit* field);
    int getLeftOverCapacity() override;
};
#endif

