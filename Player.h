#pragma once
#include <cstdlib>
#include <vector>

class Dealer;

class Player
{
private:
	void gamble(std::vector<Dealer>& dealers, char charArray[10][30]);

public:
	int playerMoney = 10;

	int x = 1 , y = 4;
	void doAction(char key, std::vector<Dealer>& dealers, char charArray[10][30]);
};