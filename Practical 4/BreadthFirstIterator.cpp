#include "BreadthFirstIterator.h"
#include "Farm.h" // Include the Farm class definition

// Constructor: Initialize the iterator with the root farm unit
BreadthFirstIterator::BreadthFirstIterator(FarmUnit* root) {
    farmQueue.push(root);  // Add the root farm to the queue
    current = nullptr;
}

// Initializes the iterator to point to the first farm unit
void BreadthFirstIterator::firstFarm() {
    if (!farmQueue.empty()) {
        current = farmQueue.front();
    }
}

// Moves to the next farm unit in the traversal
void BreadthFirstIterator::next() {
    if (!farmQueue.empty()) {
        current = farmQueue.front();  // Set the current farm
        farmQueue.pop();  // Remove the current farm from the queue

        // Add all children of the current farm unit to the queue
        for (FarmUnit* child : current->getChildren()) {
            farmQueue.push(static_cast<Farm*>(child));  // Only add Farms to the queue
        }

        // Update the current farm to the next one in the queue
        if (!farmQueue.empty()) {
            current = farmQueue.front();
        }
        else {
            current = nullptr;
        }
    }
}

// Check if the traversal is complete (i.e., if the queue is empty)
bool BreadthFirstIterator::isDone() const {
    return farmQueue.empty();
}

// Return the current farm unit in the traversal
FarmUnit* BreadthFirstIterator::currentFarm() const {
    return current;
}
