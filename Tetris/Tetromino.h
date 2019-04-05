#ifndef TETROMINO_H
#define TETROMINO_H



#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include "Point.h"


enum class TetColor { RED, ORANGE, YELLOW, GREEN, BLUE_LIGHT, BLUE_DARK, PURPLE };
enum class TetShape { SHAPE_S, SHAPE_Z, SHAPE_L, SHAPE_J, SHAPE_O, SHAPE_I, SHAPE_T, TetShapeCount };

class Tetromino {
	friend class TestSuite;

	// public vector of blocklocs
	protected:
	
		std::vector<Point> blockLocs;

	// private declarations
	private:
		TetColor color;
		TetShape shape;

	// public declarations
	public:
		Tetromino();

		TetColor getColor();

		TetShape getShape();

		void setShape(TetShape shape);

		static TetShape getRandomShape();

		void rotateCW();

		void printToConsole();
};
#endif /* TETROMINO_H */
