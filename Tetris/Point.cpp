#include "Point.h"
using namespace std;

// Initialize the point to the new X and New Y cords given
Point::Point(int newX, int newY) {
	x = newX;
	y = newY;
}

// Initialize the point to a default of 0, 0
Point::Point() {
	x = 0;
	y = 0;
}

// Method to return the X cord of the point
int Point::getX() const {
	return this->x;
}

// Method to return the Y cord of the point
int Point::getY() const {
	return this->y;
}

// Method to set the X cord
void Point::setX(int x) {
	this->x = x;
}

// Method to set the Y cord 
void Point::setY(int y) {
	this->y = y;
}

// Method to set both the X and Y cords
void Point::setXY(int x, int y) {
	this->x = x;
	this->y = y;
}


// Swap the X and Y cords of the point
void Point::swapXY(){
	int tempX = getX();
	int tempY = getY();
	x = tempY;
	y = tempX;
}
// Method to multiply the X by the factors
void Point::multiplyX(int factor) {
	x *= factor;
}

// Method to multiply the Y by the factor
void Point::multiplyY(int factor) {
	y *= factor;
}

// Method to print the point as a string and returns that string
string Point::toString() const {
	string cords = "[" + to_string(x) + "," + to_string(y) + "]";
	return cords;
}