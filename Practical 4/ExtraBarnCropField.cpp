#include "ExtraBarnCropField.h"
#include <iostream>

using namespace std;

ExtraBarnCropField::ExtraBarnCropField(FarmUnit* field) : CropFieldDecorator(field){
	wrappedField = field;
}
int ExtraBarnCropField::getLeftOverCapacity() {
	return CropFieldDecorator::getLeftOverCapacity() + 50;
}

