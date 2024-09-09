#ifndef BREADTHFIRSTITERATOR_H
#define BREADTHFIRSTITERATOR_H
#include "FarmIterator.h"
#include <queue>
class BreadthFirstIterator :
    public FarmIterator
{
private:
    FarmUnit* current;
    queue<FarmUnit*> farmQueue;

public:
    BreadthFirstIterator(Farm* root);
    void firstFarm() override;
    void next() override;
    bool isDone() const override;
    FarmUnit* currentFarm() const override;
};
#endif /*BREADTHFIRSTITERATOR_H*/
