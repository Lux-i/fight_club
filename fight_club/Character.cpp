#include "Character.h"

void Character::attack(Character& opponent) {
	int choice = rand() % abilities.size();
	abilities[choice]->execute(*this, opponent);
}

void Character::printStats() const {
	std::cout << "===== " << name << " Stats =====\n";
	std::cout << "Health: " << health << "\n";
	std::cout << "Wins: " << wins << " | Losses: " << losses << "\n";
	std::cout << "=======================\n";
}