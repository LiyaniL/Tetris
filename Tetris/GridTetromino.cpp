#include "GridTetromino.h"


// constructor, initialize gridLoc to 0,0
GridTetromino::GridTetromino()
{
	gridLoc.setX(0);
	gridLoc.setY(0);
}


// return the tetromino's grid/gameboard loc (x,y)
Point GridTetromino::getGridLoc() const
{
	return gridLoc;
}


// sets the tetromino's grid/gameboard loc using x,y
void GridTetromino::setGridLoc(int x, int y)
{
	gridLoc.setXY(x, y);
}


// sets the tetromino's grid/gameboard loc using a Point
void GridTetromino::setGridLoc(const Point & pt)
{
	gridLoc.setXY(pt.getX(), pt.getY());
}


// transpose the gridLoc of this shape
//	(1,0) represents a move to the right (x+1)
//	(-1,0) represents a move to the left (x-1)
//	(0,1) represents a move down (y+1)
void GridTetromino::move(int xOffset, int yOffset)
{
	gridLoc.setXY(gridLoc.getX() + xOffset, gridLoc.getY() + yOffset);
	// std::cout << "Points when moving: " << (gridLoc.getX() + xOffset) << " : " << (gridLoc.getY() + yOffset) << "\n";
}


// build and return a vector of Points to represent our inherited
// blockLocs vector mapped to the gridLoc of this object instance.
// eg: if we have a Point [x,y] in our vector,
// and our gridLoc is [5,6] the mapped Point would be [5+x,6+y].
std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const
{
	std::vector<Point> gridLocPoints;
	for (auto &point : Tetromino::blockLocs) {
		int xPoint = gridLoc.getX() + point.getX();
		int yPoint = gridLoc.getY() + point.getY();
		Point newPoint = Point(xPoint, yPoint);
		gridLocPoints.push_back(newPoint);
	}

	return gridLocPoints;
}
