#include "FertilisedCropField.h"
#include <iostream>
using namespace std;

FertilisedCropField::FertilisedCropField(FarmUnit* wrappedField) : CropFieldDecorator(wrappedField) {
	this->wrappedField = wrappedField;
}
void FertilisedCropField::increaseProduction() {
	wrappedField->setState(new FruitfulSoil());
}

void FertilisedCropField::harvest() {
	CropFieldDecorator::harvest();
}
