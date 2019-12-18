#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include "Map.h"

using namespace std;

void Map::getFileChar(const char* level)
{
	ifstream nChar(level);
	int nCol;
	string saveChar;

	for (nCol = 0; nCol < colNum; nCol++)
	{
		getline(nChar, saveChar);
		for (int nRow = 0; nRow < saveChar.size(); nRow++)
		{
			charArray[nCol][nRow] = saveChar[nRow];
		}
	}
}

void Map::drawMap(char input, std::vector<Dealer>& dealers)
{
	tempX = playerMov.x;
	tempY = playerMov.y;
	charArray[tempY][tempX] = ' ';
	playerMov.doAction(input, dealers, charArray);

	if (charArray[playerMov.y][playerMov.x] != ' ')
	{
		playerMov.x = tempX;
		playerMov.y = tempY;
	}

	for (col = 0; col < colNum; col++)
	{
		for (row = 0; row < rowNum; row++)
		{
			if (row == playerMov.x && col == playerMov.y)
			{
				charArray[playerMov.y][playerMov.x] = '@';
			}
			cout << charArray[col][row];
		}
		cout << '\n';
	}
}