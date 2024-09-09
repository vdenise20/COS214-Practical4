#include <iostream>
#include "Farm.h"
#include "CropField.h"
#include "Barn.h"
#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "FertiliserTruck.h"
#include "DeliveryTruck.h"
#include "BreadthFirstIterator.h"
#include "DepthFirstIterator.h"
#include "CropFieldInterface.h"

int main() {
    // ============================
    // Component 1: Farmlands and Crop Fields
    // ============================
    std::cout << "=== Testing Component 1: Farmlands and Crop Fields ===\n";

    // Create a farm and add crop fields and barns
    FarmUnit* farm1 = new Farm("Farm 1");
    FarmUnit* wheatField = new CropField("Wheat Field", "Wheat", new DrySoil());  // Initial capacity 100
    FarmUnit* cornField = new CropField("Corn Field", "Corn ", new FruitfulSoil());  // Initial capacity 200
    FarmUnit* barn1 = new Barn("Barn1", 50);  // Barn with additional 50 capacity
    CropFieldInterface* wheat = new CropField("Wheat Field", "Wheat", new DrySoil());
    CropFieldInterface* corn = new CropField("Corn Field", "Corn ", new FruitfulSoil());
    // Add fields and barn to the farm
    farm1->add(wheatField);
    farm1->add(cornField);
    farm1->add(barn1);

    // Testing basic CropField methods
    std::cout << "Wheat Field Crop Type: " << wheatField->getCropType() << "\n";
    std::cout << "Corn Field Total Capacity: " << cornField->getTotalCapacity() << "\n";
    std::cout << "Wheat Field Soil State: " << wheatField->getSoilStateName() << "\n";

    // ============================
    // Component 2: Soil States and Yield
    // ============================
    std::cout << "\n=== Testing Component 2: Soil States and Yield ===\n";

    // Test the current soil state
    std::cout << "Wheat Field Soil State (Before Rain): " << wheatField->getSoilStateName() << "\n";
    wheatField->rain();  // Apply rain to transition from DrySoil to FruitfulSoil
    std::cout << "Wheat Field Soil State (After Rain): " << wheatField->getSoilStateName() << "\n";

    // Test crop harvesting based on soil states
    std::cout << "Harvesting Wheat Field:\n";
    wheatField->harvestCrops();  // Should yield based on FruitfulSoil (x3)

    std::cout << "Flooding Corn Field and harvesting:\n";
    cornField->rain();  // Move to FloodedSoil
    cornField->harvestCrops();  // Should prevent further growth

    // ============================
    // Component 3: Fertilizer Application and Storage Enhancement
    // ============================
    std::cout << "\n=== Testing Component 3: Fertilizer and Barn Storage Enhancement ===\n";

    // Apply fertilizer to wheat field (should change DrySoil to FruitfulSoil)
    std::cout << "Applying fertilizer to Wheat Field...\n";
    wheat->increaseProduction();  // Apply fertilizer to make the field more productive

    // Add an extra barn to the wheat field to increase storage capacity
    std::cout << "Adding a barn to Wheat Field to increase capacity...\n";
    wheatField->add(new Barn("Barn",50));  // Add an extra barn to the wheat field

    std::cout << "Wheat Field Total Capacity (After Barn): " << wheatField->getTotalCapacity() << "\n";
    std::cout << "Wheat Field Leftover Capacity: " << wheat->getLeftOverCapacity() << "\n";

    // ============================
    // Component 4: Truck Logistics and Notifications
    // ============================
    std::cout << "\n=== Testing Component 4: Truck Logistics and Notifications ===\n";

    // Create and purchase trucks
    FertiliserTruck* fertilizerTruck = new FertiliserTruck();
    DeliveryTruck* deliveryTruck = new DeliveryTruck();

    fertilizerTruck->buyTruck();
    deliveryTruck->buyTruck();

    // Attach trucks to the farm
    wheat->attach(fertilizerTruck);
    corn->attach(deliveryTruck);

    // Simulate events that trigger truck operations
    std::cout << "Notifying trucks (Wheat Field needs fertilizer and Corn Field is full)...\n";
    corn->notify("Delivery");  // Trucks should respond (FertilizerTruck delivers fertilizer, DeliveryTruck collects crops)

    // Test truck-specific operations
    fertilizerTruck->startEngine();
    deliveryTruck->startEngine();

    // Sell trucks and re-test
    fertilizerTruck->sellTruck();
    deliveryTruck->sellTruck();
    corn->notify("Delivery");  // Should not trigger any truck operation after trucks are sold

    // ============================
    // Component 5: Farm Traversal Strategies
    // ============================
    std::cout << "\n=== Testing Component 5: Farm Traversal Strategies ===\n";

    // Breadth-First Traversal
    std::cout << "Breadth-First Traversal:\n";
    BreadthFirstIterator bfs(farm1);
    for (bfs.firstFarm(); !bfs.isDone(); bfs.next()) {
        std::cout << bfs.currentFarm()->getName() << "\n";
    }

    // Depth-First Traversal
    std::cout << "Depth-First Traversal:\n";
    DepthFirstIterator dfs(farm1);
    for (dfs.firstFarm(); !dfs.isDone(); dfs.next()) {
        std::cout << dfs.currentFarm()->getName() << "\n";
    }

    // Cleanup
    delete farm1;
    delete wheatField;
    delete cornField;
    delete barn1;
    delete fertilizerTruck;
    delete deliveryTruck;

    return 0;
}
