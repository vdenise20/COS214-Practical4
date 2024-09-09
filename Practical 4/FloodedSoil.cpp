#include "FloodedSoil.h"
#include <iostream>
using namespace std;

void FloodedSoil::harvestCrops(FarmUnit* field) {
    // ASCII Art: Waterlogged field with submerged crops
    std::cout << R"(
    ~~~~~~~~~~~~~
   |             |
   | ~~~~~~~~~~  |   <- Flooded field, no crops can be harvested
   | ~~~~~~~~~~  |
   |_____________|
    Flooded Soil, no crops can be harvested.
    )" << std::endl;

    // No update to the crops, as they are flooded
}

void FloodedSoil::rain(FarmUnit* field) {
    // ASCII Art: Continuous rain on a flooded field
    std::cout << R"(
      .-.
     (   )
    (     )
     `-'-'
    ~~~~~~~~~~~~~
   |             |
   | ~~~~~~~~~~  |   <- Flooded field with more rain
   | ~~~~~~~~~~  |
   |_____________|
    More rain falls, but the field remains flooded.
    )" << std::endl;

    // No state change, still flooded
}

string FloodedSoil::getName() {
	return "Flooded";
}