#include "FertilisedCropField.h"
#include <iostream>
using namespace std;

void FertilisedCropField::increaseProduction() {
	wrappedField->setState(new FruitfulSoil());
}

void FertilisedCropField::harvest() {
	CropFieldDecorator::harvest();
}
