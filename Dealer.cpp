#include "Dealer.h"
#include "Player.h"

int Dealer::dealerGambleProbability = 0;

Dealer::Dealer(int newXPos, int newYPos)
{
	xPos = newXPos;
	yPos = newYPos;
}

void Dealer::dealerCheck(int playerX, int playerY, Player& player)
{
	if (abs(xPos - playerX) <= 1 && abs(yPos - playerY) <= 1)
	{
		dealerGamble(player);
	}
}

void Dealer::dealerGamble(Player& player)
{
	dealerGambleProbability = rand() % 100;
	if (dealerGambleProbability > 30)
	{
		player.playerMoney--;
	}
	else
	{
		player.playerMoney++;
	}
}

void Dealer::drawDealer(char charArray[10][30])
{
	
	charArray[yPos][xPos] = 'D';

}