#include <iostream>
#include <vector>
#include "Ability.h"

#pragma once
class Character {
private:
	std::string name;
	int health;
	std::vector<std::unique_ptr<Ability>> abilities;
	int wins = 0;
	int losses = 0;

public:
	Character(std::string n, std::unique_ptr<Ability> ab1, std::unique_ptr<Ability> ab2)
		: name(std::move(n)), health(20) {
		abilities.push_back(std::move(ab1));
		abilities.push_back(std::move(ab2));
	}

	void attack(Character& opponent);
	bool isDefeated() const { return health <= 0; }
	void takeDamage(int dmg) { health -= dmg; }
	void heal(int amount) { health += amount; if (health > 20) health = 20; }
	void increaseWin() { wins++; }
	void increaseLoss() { losses++; }

	void printStats() const;
	std::string getName() const { return name; }
	int getHealth() const { return health; }
};
