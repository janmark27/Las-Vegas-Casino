#include "Player.h"
#include "Dealer.h"

using namespace std;

void Player::doAction(char key, std::vector<Dealer>& dealers, char charArray[10][30])
{
	switch (key) {
	case 'a':
		x--;
		break;

	case 'd':
		x++;
		break;

	case 'w':
		y--;
		break;

	case 's':
		y++;
		break;

	case 'g':
		gamble(dealers, charArray);
		break;
	}
}

void Player::gamble(std::vector<Dealer>& dealers, char charArray[10][30])
{
	for (int i = 0; i < dealers.size(); i++)
	{
		if (abs(dealers[i].getX() - x) <= 1 && abs(dealers[i].getY() - y) <= 1)
		{
			dealers[i].dealerMoney--;

			if (dealers[i].dealerMoney == 0)
			{
				charArray[dealers[i].getY()][dealers[i].getX()] = ' ';
				dealers.erase(dealers.begin() + i);
			}
		}
	}
}