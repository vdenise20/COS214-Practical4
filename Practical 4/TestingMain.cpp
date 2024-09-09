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
#include "ExtraBarnCropField.h"
#include "FertilisedCropField.h"
#include "FarmIterator.h"

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
    FarmUnit* wheat = new CropField("Wheat Field", "Wheat", new DrySoil());
    FarmUnit* corn = new CropField("Corn Field", "Corn ", new FruitfulSoil());
    FarmUnit* extraBarn = new ExtraBarnCropField(cornField);
    // Add fields and barn to the farm
    farm1->add(wheatField);
    farm1->add(cornField);
    farm1->add(barn1);

    // Testing basic CropField methods
    std::cout << "Wheat Field Crop Type: " << wheatField->getCropType() << "\n";
    std::cout << "Corn Field Total Capacity: " << cornField->getTotalCapacity() << "\n";
    std::cout << "Barn Total Capacity: " << barn1->getTotalCapacity() << "\n";
    std::cout << "Wheat Field Soil State: " << wheatField->getSoilStateName() << "\n";

    //Delete for demo
    SoilState* soil = wheat->getState();
    CropField* crop = new CropField("Corn Field", "Corn", new FruitfulSoil());
    crop->updateCurrentCrops(10);
    crop->getYield();
    crop->getName();
    crop->increaseProduction();
    crop->harvest();
    crop->harvestCrops();
    crop->rain();

    Farm* farming = new Farm("Farm 1");
    farming->getTotalCapacity();
    farming->getName();
    farming->add(wheat);
    farming->remove(wheat);
    farming->getChildren();

    FertilisedCropField* fertilised = new FertilisedCropField(wheat);
    fertilised->increaseProduction();
    fertilised->harvest();

    FloodedSoil* flood = new FloodedSoil();
    flood->getName();
    flood->harvestCrops(corn);
    flood->rain(corn);

    // ============================
    // Component 2: Soil States and Yield
    // ============================
    std::cout << "\n=== Testing Component 2: Soil States and Yield ===\n";

    // Test the current soil state
    std::cout << "Wheat Field Soil State (Before Rain): " << wheatField->getSoilStateName() << "\n";
    wheatField->harvestCrops();
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
    wheat = new FertilisedCropField(wheatField);
    wheat->increaseProduction();  // Apply fertilizer to make the field more productive

    // Add an extra barn to the wheat field to increase storage capacity
    std::cout << "Adding a barn to Wheat Field to increase capacity...\n";
    wheat = new ExtraBarnCropField(wheatField);
    wheat->getLeftOverCapacity();  // Add an extra barn to the wheat field

    std::cout << "Wheat Field Total Capacity (After Barn): " << wheatField->getTotalCapacity() << "\n";
    std::cout << "Wheat Field Leftover Capacity: " << wheat->getLeftOverCapacity() << "\n";

    // ============================
    // Component 4: Truck Logistics and Notifications
    // ============================
    std::cout << "\n=== Testing Component 4: Truck Logistics and Notifications ===\n";

    // Create and purchase trucks
    Truck* fertilizerTruck = new FertiliserTruck();
    Truck* deliveryTruck = new DeliveryTruck();

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
    corn->notify("Fertiliser");
    // ============================
    // Component 5: Farm Traversal Strategies
    // ============================
    std::cout << "\n=== Testing Component 5: Farm Traversal Strategies ===\n";

    // Breadth-First Traversal
    std::cout << "Breadth-First Traversal:\n";
    FarmIterator* bfs = farm1->createBreadthIterator();
    bfs->firstFarm();
    cout << bfs->currentFarm()->getName() << endl;
    bfs->next();
    cout << bfs->currentFarm()->getName() << endl;
    cout << bfs->isDone() << endl;

    // Depth-First Traversal
    std::cout << "Depth-First Traversal:\n";
    FarmIterator* dfs = farm1->createDepthIterator();
    dfs->firstFarm();
    cout << dfs->currentFarm()->getName() << endl;
    dfs->next();
    cout << dfs->currentFarm()->getName() << endl;
    cout << dfs->isDone() << endl;

    // Cleanup
    delete farm1;
    delete wheatField;
    delete cornField;
    delete barn1;
    delete fertilizerTruck;
    delete deliveryTruck;
    delete crop;

    return 0;
}
