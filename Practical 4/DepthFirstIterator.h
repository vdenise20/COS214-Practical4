#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHGIRSTITERATOR_H
#include "FarmIterator.h"
class FarmUnit;
#include <stack>
class DepthFirstIterator :
    public FarmIterator
{
private:
    FarmUnit* current;
    stack<FarmUnit*> farmStack;

public:
    DepthFirstIterator(FarmUnit* root);
    void firstFarm() override;
    void next() override;
    bool isDone() const override;
    FarmUnit* currentFarm() const override;
};
#endif /*DEPTHFIRSTITERATOR_H*/
