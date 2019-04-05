#include "Tetromino.h"
using namespace std;

// Sets the default shape of the tetromino to the "S" shape
Tetromino::Tetromino() {
	//setShape(getRandomShape());
	setShape(TetShape::SHAPE_O);
}



// Method to get the color of the current tetromino
TetColor Tetromino::getColor()
{
	return color;
}

// Method to get the shape of the current tetromino
TetShape Tetromino::getShape() {
	return this->shape;
}

// Method to set the shape of the tetromino
void Tetromino::setShape(TetShape shape) {
	blockLocs.empty();
	this->shape = shape;
	switch (shape) {
		case (TetShape::SHAPE_S):
			this->color = (static_cast<TetColor>(static_cast<int>(shape)));
			blockLocs = { Point(-1, 0), Point(0,0), Point(0, 1), Point(1,1) };
			break;

		case (TetShape::SHAPE_Z):
			this->color = (static_cast<TetColor>(static_cast<int>(shape)));
			blockLocs = { Point(0, 0), Point(1, 0), Point(0, 1), Point(-1, 1) };
			break;
		
		case (TetShape::SHAPE_L):
			this->color = (static_cast<TetColor>(static_cast<int>(shape)));
			blockLocs = { Point(0, 1), Point(0, 0), Point(0, -1), Point(1, -1) };
			break;

		case (TetShape::SHAPE_O):
			this->color = (static_cast<TetColor>(static_cast<int>(shape)));
			blockLocs = { Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 0) };
			break;

		case (TetShape::SHAPE_J):
			this->color = (static_cast<TetColor>(static_cast<int>(shape)));
			blockLocs = { Point(0, 0), Point(0, -1), Point(-1, -1), Point(0, 1) };
			break;

		case(TetShape::SHAPE_I):
			this->color = (static_cast<TetColor>(static_cast<int>(shape)));
			blockLocs = { Point(0, 0), Point(0, -1), Point(0, 1), Point(0, 2) };
			break;

		case(TetShape::SHAPE_T):
			this->color = (static_cast<TetColor>(static_cast<int>(shape)));
			blockLocs = { Point(0, 0), Point(0, -1), Point(0, 1), Point(-1, 0) };
			break;
	}
}

TetShape Tetromino::getRandomShape()
{
	int shapeCount = static_cast<int>(TetShape::TetShapeCount);
	int randShape = rand() % shapeCount;
	return static_cast<TetShape>(randShape);
}

// Method to rotate the current tetromino 90 degrees clockwise
void Tetromino::rotateCW() {
	for (int i = 0; i < blockLocs.size(); i++) {
		blockLocs[i].swapXY();
		blockLocs[i].multiplyY(-1);
		// cout << "Points when rotating: " << blockLocs[i].getX() << " : " << blockLocs[i].getY() << endl;
	};
	
}

// Method to print the grid to the console and the position of 
// the tetromino
void Tetromino::printToConsole() {
	bool check = false;
	for (int y = 3; y > -4; y--) {
		for (int x = -3; x < 4; x++) {
			for (auto const &point : blockLocs) {
				(point.getX() == x && point.getY() == y) ? check = true : check = false;
				if (check) { break; }
			}
			check ? cout << "x" : cout << ".";
			check = false;

		}
		cout << endl;
	}
}
