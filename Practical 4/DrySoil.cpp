#include "DrySoil.h"
#include "FruitfulSoil.h"
#include <iostream>
using namespace std;

// DrySoil.cpp

void DrySoil::harvestCrops(CropField* field) {
    // ASCII Art: Dry soil with a small plant
    std::cout << R"(
    ____________
   |            |
   |    .-.     |    <- Small, struggling plant in dry soil
   |   (   )    |    
   |    `-'     |   
   |____________|
    Dry Soil, minimal yield.
    )" << std::endl;

    field->updateCurrentCrops(field->getYield());
}
void DrySoil::rain(CropField* field) {
    // ASCII Art: Raindrops falling on dry soil
    std::cout << R"(
      .-.
     (   )
    (     )
     `-'-'
    _________
   |         |
   |   .-.   |   <- Raindrops falling on dry soil
   |  (   )  |
   |_________|
    Rainfall brings life to the field!
    Transitioning soil to Fruitful...
    )" << std::endl;

    field->setState(new FruitfulSoil());
}

string DrySoil::getName() {
	return "Dry";
}