#ifndef FARMCOLLECTION_H
#define FARMCOLLECTION_H

#include "FarmIterator.h"
class FarmCollection
{
public:
	virtual FarmIterator* createIterator() = 0;
};
#endif /*FARMCOLLECTION_H*/

