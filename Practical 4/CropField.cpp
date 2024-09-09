#include "CropField.h"
#include <iostream>
using namespace std;

CropField::CropField(string name, string cropType, SoilState* currentState):FarmUnit(name){
	this->cropType = cropType;
	this->totalCapacity = 100;
	this->currentStoredCrops = 0;
	this->currentState = currentState;
	this->yield = 10;
}
string CropField::getCropType() {
	return this->cropType;
}
int CropField::getTotalCapacity() const {
	return this->totalCapacity;
}
void CropField::updateCurrentCrops(int num) {
	if(getLeftOverCapacity() - num >= 0)
		this->currentStoredCrops += num;
	else {
		cout << "The storage is full." << endl;
		CropFieldInterface::notify("Delivery");
		this->currentStoredCrops = num;
		cout << "The crops have been sent out to thte delivery trucks. The storage is now free and has been updated." << endl;
	}
}
int CropField::getYield() {
	return yield;
}
string CropField::getName() const {
	return FarmUnit::getName();
}
string CropField::getSoilStateName() const {
	return this->currentState->getName();
}
SoilState* CropField::getState() {
	return this->currentState;
}
void CropField::setState(SoilState* newState) {
	this->currentState = newState;
}
int CropField::getLeftOverCapacity() {
	return totalCapacity - currentStoredCrops;
}
void CropField::increaseProduction() {
	notify("Fertiliser");
}
void CropField::harvest() {
	currentState->harvestCrops(this);
}
void CropField::harvestCrops() {
	currentState->harvestCrops(this);
}
