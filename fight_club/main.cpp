#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "Ability.h"
#include "Character.h"

void fight(Character& c1, Character& c2) {
	std::cout << "Kampf: " << c1.getName() << " vs " << c2.getName() << "!\n";
	while (!c1.isDefeated() && !c2.isDefeated()) {
		c1.attack(c2);
		if (!c2.isDefeated()) c2.attack(c1);
	}

	if (c1.isDefeated()) {
		std::cout << c1.getName() << " wurde besiegt!\n";
		c1.increaseLoss();
		c2.increaseWin();
	}
	else {
		std::cout << c2.getName() << " wurde besiegt!\n";
		c2.increaseLoss();
		c1.increaseWin();
	}
}

int main() {
	srand(time(nullptr));

	std::vector<Character> characters;
	characters.emplace_back("Bruce", std::make_unique<Punch>(), std::make_unique<Kick>());
	characters.emplace_back("Chuck", std::make_unique<Kick>(), std::make_unique<Heal>());

	fight(characters[0], characters[1]);

	return 0;
}