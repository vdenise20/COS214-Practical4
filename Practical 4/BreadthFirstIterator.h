#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H
#include "FarmIterator.h"
#include <queue>
class FarmUnit;
class BreadthFirstIterator :
    public FarmIterator
{
private:
    FarmUnit* current;
    queue<FarmUnit*> farmQueue;

public:
    BreadthFirstIterator(FarmUnit* root);
    void firstFarm() override;
    void next() override;
    bool isDone() const override;
    FarmUnit* currentFarm() const override;
};
#endif /*BREADTHFIRSTITERATOR_H*/
