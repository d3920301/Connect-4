#include "Player.h"

Player::Player(Grid *newGrid)
{
	curGrid = newGrid;

	SetNewIcon();
}

bool Player::IsIconValid(char newIcon)
{
	if ((newIcon < 0) || (newIcon > 127))
	{
		std::cout << "Invalid icon. Please select a new one." << std::endl;
		return false;
	}

	return true;
}

bool Player::IsIconUnique(std::vector<Player> playerVector)
{
	for (int i = 0; i < playerVector.size(); i++)
	{
		if (playerVector[i].GetIcon() == icon)
		{
			return 0;
		}
	}

	return true;
}

void Player::SetNewIcon()
{
	std::cout << "Please select a letter to represent you: ";
	char playerChar;
	std::cin >> playerChar;
	std::cout << std::endl;
	while (!IsIconValid(playerChar))
	{
		std::cout << "Please select a letter to represent you: ";
		char playerChar;
		std::cin >> playerChar;
		std::cout << std::endl;
	}
	icon = playerChar;
}

bool Player::HandleInput(int selCol)
{
	if ((selCol >= curGrid->GetCols()) || (selCol < 0))
	{
		std::cout << " Invalid Column!" << std::endl << std::endl;
		return false;
	}

	for (int i = curGrid->GetRows() - 1; i >= 0; i--)
	{
		if ((curGrid->GetCell(i, selCol) == '-'))
		{
			curGrid->SetGrid(i, selCol, icon);
			return true;
		}
		else if (curGrid->GetCell(0, selCol) != '-')
		{
			std::cout << " Column Full! Please select another column." << std::endl;
			return false;
		}
	}

	return false;
}

bool Player::WinCheck()
{
	// Straight line check
	for (int i = 0; i < curGrid->GetRows(); i++)
	{
		for (int j = 0; j < (curGrid->GetCols() - 3); j++)
		{
			if ((curGrid->GetCell(i, j) == icon) && (curGrid->GetCell(i, j + 1) == icon) && (curGrid->GetCell(i, j + 2) == icon) && (curGrid->GetCell(i, j + 3) == icon))
			{
				return 1;
			}
		}
	}

	// Vertical line check
	for (int i = 0; i < (curGrid->GetRows() - 3); i++)
	{
		for (int j = 0; j < curGrid->GetCols(); j++)
		{
			if ((curGrid->GetCell(i, j) == icon) && (curGrid->GetCell(i + 1, j) == icon) && (curGrid->GetCell(i + 2, j) == icon) && (curGrid->GetCell(i + 3, j) == icon))
			{
				return 1;
			}
		}
	}

	// Diagonal line check
	// For each row we check we want to check the row below and the next column
	// This will get downwards diagonals
	// We can just go back up to 4 columns for upward diagonals. It would be easiest to do on a new code snippet
	for (int i = 3; i < curGrid->GetRows(); i++)
	{
		// GetCols() - 1 otherwise we will be trying to access non-accessable memory
		for (int j = (curGrid->GetCols() - 1); j > 2; j--)
		{
			if ((curGrid->GetCell(i, j) == icon) && (curGrid->GetCell(i - 1, j - 1) == icon) && (curGrid->GetCell(i - 2, j - 2) == icon) && (curGrid->GetCell(i - 3, j - 3) == icon))
			{
				return 1;
			}
		}
	}

	for (int i = 3; i < curGrid->GetRows(); i++)
	{
		for (int j = 0; j < (curGrid->GetCols() - 3); j++)
		{
			if ((curGrid->GetCell(i, j) == icon) && (curGrid->GetCell(i - 1, j + 1) == icon) && (curGrid->GetCell(i - 2, j + 2) == icon) && (curGrid->GetCell(i - 3, j + 3) == icon))
			{
				return 1;
			}
		}
	}

	return 0;
}

bool Player::HandleContPlayInput(char playAgain)
{
	bool responseValid = 0;

	while (!responseValid)
	{
		if ((playAgain == 'Y') || (playAgain == 'y') || (playAgain == '1'))
		{
			// Reset the grid and draw it again since we don't leave the while loop so the player will be prompted for input before seeing the grid.
			curGrid->InitGrid();
			curGrid->DrawGrid();

			return 1;
		}
		else if ((playAgain == 'N') || (playAgain == 'n') || (playAgain == '0'))
		{
			return 0;
		}
		else
		{
			std::cout << " Invalid response." << std::endl;
			std::cout << " Would you like to play again? (Y/n): ";
			std::cin >> playAgain;
			std::cout << std::endl;
		}
	}
}