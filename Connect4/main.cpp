// Each string has a space before it to make it look better
// @TODO: FIX LETTER IN COLUMN CHOOSE
// @TODO: CHECK EVERTHING!! Game almost done just needs runtime checks

#include <iostream>
#include <memory>
#include "Grid.h"
#include "Player.h"

int main()
{
	// Grid
	Grid grid;
	Grid* gridPtr = &grid;

	bool windowShouldClose = 0;

	std::cout << " Welcome to Connect 4!" << std::endl << std::endl;

	// Players
	// Ask for num of plyrs first, the for loop through the setup of players
	// Must used signed int otherwise player can type negative numbers
	char howManyPlayers;
	std::cout << "How many players are playing: ";
	std::cin >> howManyPlayers;
	int howManyPlayersInt = static_cast<int>(howManyPlayers) - 48;
	while ((howManyPlayersInt < 1) || (howManyPlayersInt > 9))
	{
		if (howManyPlayersInt < 1)
		{
			std::cout << "Please select a number above 0." << std::endl;
		}
		if (howManyPlayersInt > 9)
		{
			std::cout << "Please select a number below 10." << std::endl;
		}
		std::cout << "How many players are playing: ";
		std::cin >> howManyPlayersInt;
	}

	std::vector<Player> players;

	for (int i = 0; i < howManyPlayersInt; i++)
	{
		std::cout << "Player " << i + 1 << ", Please choose an icon." << std::endl;
		Player newPlayer(gridPtr);
		// Validate player icon..... this shouldn't be done here
		while (!newPlayer.IsIconUnique(players))
		{
			std::cout << "Icon is already taken. Please try again." << std::endl;
			newPlayer.SetNewIcon();
		}

		players.push_back(newPlayer);
	}

	// Draw the grid as the last thing before the game loop so the players can see the board before being prompted for input.
	grid.DrawGrid();

	while (!windowShouldClose)
	{
		for (int i = 0; i < players.size(); i++)
		{
			std::cout << "Player " << (i + 1) << ": Which column would you like to place your piece: ";
			int playerCol;
			std::cin >> playerCol;
			std::cout << std::endl;

			while (!players[i].HandleInput(playerCol - 1))
			{
				grid.DrawGrid();
				std::cout << " Player " << (i + 1) << " : Which column would you like to place your piece : ";
				std::cin >> playerCol;
				std::cout << std::endl;
			}

			grid.DrawGrid();

			if (grid.IsStalemate())
			{
				std::cout << " Stalemate. No more available positions." << std::endl;
				std::cout << " Would you like to play again? (Y/n): ";
				char playAgain = 'Y';
				std::cin >> playAgain;
				std::cout << std::endl;
				if (!players[i].HandleContPlayInput(playAgain))
				{
					return 0;
				}
			}
			
			if (players[i].WinCheck())
			{
				std::cout << " Player " << (i + 1) << " Connect 4!" << std::endl;
				std::cout << " Would you like to play again? (Y/n): ";
				char playAgain = 'Y';
				std::cin >> playAgain;
				std::cout << std::endl;
				if (!players[i].HandleContPlayInput(playAgain))
				{
					return 0;
				}

				// Set i to 0 here so it will always restart with player 1 as the first player
				i = 0;
			}
		}
	}

	return 0;
}
