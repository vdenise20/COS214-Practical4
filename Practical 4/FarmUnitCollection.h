#ifndef FARMUNITCOLLECTION_H
#define FARMUNITCOLLECTION_H
#include "FarmCollection.h"
class FarmUnitCollection :
    public FarmCollection
{
public:
    FarmIterator* createIterator() override;
};
#endif /*FARMUNITCOLLECTION_H*/

