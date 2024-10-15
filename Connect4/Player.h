#pragma once
#include "Grid.h"
#include <vector>

class Player
{
private:
	char icon = 127;
	Grid *curGrid;

protected:
	bool IsIconValid(char newIcon);

public:
	Player(Grid *newGrid);

	bool IsIconUnique(std::vector<Player> playerVector);
	void SetNewIcon();

	bool HandleInput(int sel);
	bool WinCheck();
	bool HandleContPlayInput(char playAgain);

	// Getters/Setters
	char GetIcon() { return icon; }
	void SetIcon(char newIcon) { icon = newIcon; }
};

