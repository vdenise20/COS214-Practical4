#include "ExtraBarnCropField.h"
#include <iostream>

using namespace std;

int ExtraBarnCropField::getLeftOverCapacity() {
	return CropFieldDecorator::getLeftOverCapacity() + 50;
}

