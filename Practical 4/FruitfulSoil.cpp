#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include <iostream>
using namespace std;

// FruitfulSoil.cpp

void FruitfulSoil::harvestCrops(FarmUnit* field) {
    // ASCII Art: Lush field with tall, healthy crops
    std::cout << R"(
    _____________
   |             |
   |    | | |    |   <- Tall, healthy crops in fruitful soil
   |    | | |    |    
   |    | | |    |   
   |_____________|
    Fruitful Soil, high yield!
    )" << std::endl;

    field->updateCurrentCrops(field->getYield() * 3);  // Boosted yield
}
void FruitfulSoil::rain(FarmUnit* field) {
    // ASCII Art: Raindrops nurturing a healthy field
    std::cout << R"(
      .-.
     (   )
    (     )
     `-'-'
    _____________
   |             |
   |   | | | |   |   <- Rain falling on already fruitful crops
   |   | | | |   |
   |_____________|
    Rain continues to nurture the fruitful field.
    )" << std::endl;

    field->setState(new FloodedSoil());
}

string FruitfulSoil::getName() {
	return "Fruitful";
}