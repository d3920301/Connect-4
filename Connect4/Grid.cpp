#include "Grid.h"

//Grid::Grid()
//{
//	std::cout << "Please enter the amount of rows you want (Leave blank for default (7): ";
//	int rowAmount;
//	std::cin >> rowAmount;
//	std::cout << std::endl;
//
//	std::cout << "Please enter the amount of columns you want (Leave blank for default (7): ";
//	int colAmount;
//	std::cin >> colAmount;
//	std::cout << std::endl;
//}

void Grid::InitGrid()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = '-';
		}
	}
}

void Grid:: DrawGrid()
{
	std::cout << " | 1 | 2 | 3 | 4 | 5 | 6 | 7 | " << std::endl << std::endl;

	for (int i = 0; i < rows; i++)
	{
		// Beautify without changing the grid dimensions
		std::cout << " | ";

		for (int j = 0; j < cols; j++)
		{
			std::cout << grid[i][j];

			// Beautify without changing the grid dimensions
			std::cout << " | ";
		}

		// This isnt part of the beautification
		std::cout << std::endl;
	}

	return;
}

bool Grid::IsStalemate()
{
	bool isStalemate = 1;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (grid[i][j] == '-')
			{
				isStalemate = 0;
			}
		}
	}

	return isStalemate;
}
