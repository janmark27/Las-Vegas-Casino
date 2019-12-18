#pragma once
#include "Player.h"
#include "Dealer.h"

class Map
{
public:
	
	int tempX = 0, tempY = 0, col = 0, row = 0;
	static const int rowNum = 30;
	static const int colNum = 10;
	char charArray[colNum][rowNum];
	Player playerMov;
	void getFileChar(const char* level);
	void drawMap(char input, std::vector<Dealer>& enemies);
};