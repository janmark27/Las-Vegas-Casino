#pragma once
#include <cstdlib>
#include <vector>
class Player;

class Dealer
{
private:
	int xPos, yPos;
	static int dealerGambleProbability;

public:

	int dealerMoney = 4;
	int getX() { return xPos; }
	int getY() { return yPos; }

	Dealer(int newXPos, int newYPos);

	void dealerCheck(int playerX, int playerY, Player& player);
	void dealerGamble(Player& player);
	void drawDealer(char charArray[10][30]);

	static int GetDealerGambleProbability() { return dealerGambleProbability; }
};