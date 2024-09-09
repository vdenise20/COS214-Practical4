#include "CropFieldDecorator.h"
#include <iostream>
using namespace std;
void CropFieldDecorator::increaseProduction() {
	return wrappedField->increaseProduction();
}
void CropFieldDecorator::harvest() {
	return wrappedField->harvest();
}
int CropFieldDecorator::getLeftOverCapacity() {
	return wrappedField->getLeftOverCapacity();
}
CropFieldDecorator::~CropFieldDecorator() {
	delete wrappedField;
}
