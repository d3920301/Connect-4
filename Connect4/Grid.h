#pragma once
#include <iostream>
#include <vector>

class Grid
{
private:
	int rows = 7;
	int cols = 7;

	std::vector<std::vector<char>> grid = {
	{'-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-'}
	};

public:
	/*Grid();*/

	void InitGrid();
	void DrawGrid();

	bool IsStalemate();

	// Getters/Setters
	std::vector<std::vector<char>> GetGrid() { return grid; }
	char GetCell(int row, int col) { return grid[row][col]; }
	void SetGrid(int row, int col, char val) { grid[row][col] = val; }
	int GetRows() { return rows; }
	int GetCols() { return cols; }
};

