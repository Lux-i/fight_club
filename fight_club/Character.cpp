#include "Character.h"
#include <iomanip>

void Character::attack(Character& opponent) {
	int choice = rand() % abilities.size();
	abilities[choice]->execute(*this, opponent);
}

void Character::printStats() const {
	const float winrate = (float)wins / std::max(1, wins + losses) * 100;
	std::cout << "===== " << name << " Stats =====\n";
	std::cout << "\033[0;92mWins: " << wins;
	std::cout << "\033[0;37m | ";
	std::cout << "\033[0;91mLosses: " << losses;
	std::cout << "\033[0;37m | ";
	std::cout << "\033[0;95mW/L: " << winrate << std::setprecision(3) << "%\n";
	std::cout << "\033[0;37m=======================\n";
}