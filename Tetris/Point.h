#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <math.h>

class Point {
	friend class TestSuite;

	// Private members
	private:
		int x;
		int y;
	
	// Public members
	public:
		Point();

		Point(int newX, int newY);

		int getX() const;

		int getY() const;

		void setX(int x);
		
		void setY(int y);

		void setXY(int x, int y);

		void swapXY();

		void multiplyX(int factor);

		void multiplyY(int factor);

		std::string toString() const;
};
#endif /* POINT_H */