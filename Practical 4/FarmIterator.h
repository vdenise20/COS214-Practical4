#ifndef FARMITERATOR_H
#define FARMITERATOR_H

#include "Farm.h"
class FarmIterator
{
public:
	virtual void firstFarm() = 0;
	virtual void next() = 0;
	virtual bool isDone() const = 0;
	virtual FarmUnit* currentFarm() const = 0;
};
#endif /*FARMITERATOR_H*/

