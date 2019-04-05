#include "Gameboard.h"
#include "Point.h"
#include <iomanip>
#include <vector>
using namespace std;
Gameboard::Gameboard()
{
	empty();
}

int Gameboard::getContent(Point pt) const
{
	int content = grid[pt.getX()][pt.getY()];
	return content;
}

int Gameboard::getContent(int x, int y) const
{
	return grid[x][y];
}

void Gameboard::setContent(Point pt, int content)
{
	grid[pt.getX()][pt.getY()] = content;
}

void Gameboard::setContent(int x, int y, int content)
{
	grid[x][y] = content;
}

void Gameboard::setContent(std::vector<Point> locs, int content)
{
	for (auto &loc : locs) {
		setContent(loc, content);
	}
}

bool Gameboard::areLocsEmpty(std::vector<Point> locs) const
{
	for (auto &loc : locs) {
		if (loc.getX() >= 0 && loc.getX() < MAX_X && loc.getY() >= 0 && loc.getY() < MAX_Y) {
			if (getContent(loc) != EMPTY_BLOCK) { 
				return false; 
			}
		}
	}
	return true;
}

int Gameboard::removeCompletedRows()
{	
	int completedRows = 0;
	vector<int> completedRowIndices = getCompletedRowIndices();
	removeRows(completedRowIndices);
	for (auto row : completedRowIndices) {
		completedRows += 1;
	}
	return completedRows;
}

void Gameboard::empty()
{
	for (int y = 0; y < MAX_Y; y++) {
			fillRow(y, EMPTY_BLOCK);
	}
}

Point Gameboard::getSpawnLoc() const
{
	return spawnLoc;
}

void Gameboard::printToConsole() const
{
	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			cout << setw(2) << grid[x][y];
		}
		cout << endl;
		
	}
	cout << endl;

}

bool Gameboard::isRowCompleted(int rowIndex) const
{	
		for (int x = 0; x < MAX_X; x++) {
			if (grid[x][rowIndex] != EMPTY_BLOCK) {
				continue;
			}
			else if (grid[x][rowIndex] == EMPTY_BLOCK) {
				return false;
			}
		}
	return true;
}

std::vector<int> Gameboard::getCompletedRowIndices() const
{	
	vector<int> completeRows;
	for (int y = 0; y < MAX_Y; y++) {
		if (isRowCompleted(y)) {
			completeRows.push_back(y);
		}
	}
	return completeRows;
}

void Gameboard::removeRow(int rowIndex)
{
		
		for (int y = rowIndex; y > 0; y--) {
			copyRowIntoRow(y - 1, y);

		}

		fillRow(0, EMPTY_BLOCK);

}

void Gameboard::removeRows(std::vector<int> rowIndices)
{
	for (auto &row : rowIndices) {
		removeRow(row);
	}
}

void Gameboard::fillRow(int rowIndex, int content)
{
	for (int x = 0; x < MAX_X; x++) {
		grid[x][rowIndex] = content;
	}
}

void Gameboard::copyRowIntoRow(int sourceRowIndex, int targetRowIndex)
{
	for (int x = 0; x < MAX_X; x++) {
		grid[x][targetRowIndex] = grid[x][sourceRowIndex];
	}
}

