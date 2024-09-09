#ifndef EXTRABARNCROPFIELD_H
#define EXTRABARNCROPFIELD_H
#include "CropFieldDecorator.h"
class ExtraBarnCropField :
    public CropFieldDecorator
{
public:
    int getLeftOverCapacity() override;
};
#endif

