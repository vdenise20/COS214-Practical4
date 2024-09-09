#include "DepthFirstIterator.h"
#include "Farm.h" // Include the Farm class definition

// Constructor: Initialize the iterator with the root farm unit
DepthFirstIterator::DepthFirstIterator(Farm* root) {
    farmStack.push(root);  // Add the root farm unit to the stack
    current = nullptr;
}

// Initializes the iterator to point to the first farm unit
void DepthFirstIterator::firstFarm() {
    if (!farmStack.empty()) {
        current = farmStack.top();
    }
}

// Moves to the next farm unit in the traversal
void DepthFirstIterator::next() {
    if (!farmStack.empty()) {
        current = farmStack.top();  // Set the current farm unit
        farmStack.pop();  // Remove the current farm unit from the stack

        // Get all the children of the current farm unit and push them to the stack in reverse order
        std::vector<FarmUnit*> children = current->getChildren();
        for (auto it = children.rbegin(); it != children.rend(); ++it) {
            farmStack.push(static_cast<Farm*>(*it));  // Only add Farms to the stack
        }

        // Update the current farm unit to the next one in the stack
        if (!farmStack.empty()) {
            current = farmStack.top();
        }
        else {
            current = nullptr;
        }
    }
}

// Check if the traversal is complete (i.e., if the stack is empty)
bool DepthFirstIterator::isDone() const {
    return farmStack.empty();
}

// Return the current farm unit in the traversal
FarmUnit* DepthFirstIterator::currentFarm() const {
    return current;
}
