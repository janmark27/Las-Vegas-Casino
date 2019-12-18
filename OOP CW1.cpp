#include <iostream>
#include <fstream>
#include <vector>
#include "Map.h"
#include "Player.h"
#include <conio.h>
#include "Dealer.h"

using namespace std;

char input;

std::vector<int> xE = { 14, 14, 19, 26, 26 }, yE = { 2, 7, 5, 2, 7 };

std::vector<Dealer> dealers;

void SpawnDealer() 
{
	for (size_t i = 0; i < xE.size(); i++)
	{
		dealers.push_back(Dealer(xE[i], yE[i]));
	}
}

int main()
{
	Map Map;
	Map.getFileChar("Level1.txt");

	SpawnDealer();
	while (Map.playerMov.playerMoney > 0 && dealers.size() > 0)
	{	
		cout << "LAS VEGAS CASINO ROYALE XXXL (FEATURING DANTE FROM THE DEVIL MAY CRY SERIES)" << endl;
		cout << "                                Money    "<< Map.playerMov.playerMoney << endl;
		cout << "                                Player Bet  30" << "/" << Dealer::GetDealerGambleProbability() << "  Dealer Bet " << endl;
		cout << " WASD to Move    G to Gamble" << endl;
		for (Dealer& enemy : dealers)
		{
			enemy.dealerCheck(Map.playerMov.x, Map.playerMov.y, Map.playerMov);
			enemy.drawDealer(Map.charArray);
		}
		
		Map.drawMap(input, dealers);
		input = _getch();

		system("CLS");

	}
	return 0;
};