#ifndef FARMCOLLECTION_H
#define FARMCOLLECTION_H

#include "FarmIterator.h"
class FarmCollection
{
public:
	virtual FarmIterator* createBreadthIterator() = 0;
	virtual FarmIterator* createDepthIterator() = 0;
};
#endif /*FARMCOLLECTION_H*/

