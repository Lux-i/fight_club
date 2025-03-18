#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "Ability.h"
#include "Character.h"
#include <string>

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
	//set health back to 20
	c1.heal(20 - c1.getHealth());
	c2.heal(20 - c2.getHealth());
}

Character& selectCharacter(std::vector<Character>& characters) {
	std::string input;
	unsigned int input_uint;
	for (int i = 0; i < characters.size(); i++) {
		std::cout << i << ": " << characters[i].getName() << std::endl;
	}
	std::cout << "Choose a character: ";
	std::getline(std::cin, input);
	input_uint = std::stoul(input);
	if (input_uint < characters.size()) {
		return characters[input_uint];
	}
	//if above if does not return use this recursive loop
	std::cout << input << std::endl;
	std::cout << input_uint << std::endl;
	std::cout << "Invalid character Number!\n";
	return selectCharacter(characters);
}

int main() {
	srand(time(nullptr));

	std::vector<Character> characters;
	characters.emplace_back("Bruce", std::make_unique<Punch>(), std::make_unique<Kick>());
	characters.emplace_back("Chuck", std::make_unique<Kick>(), std::make_unique<Heal>());

	fight(characters[0], characters[1]);

	//menu loop
	while (true) {
		std::string input;
		std::cout << "1: Start fight" << std::endl;
		std::cout << "2: Create Character" << std::endl;
		std::cout << "3: View Statistics" << std::endl;
		std::cout << "4: Quit" << std::endl;
		std::cout << "Your choice: ";
		std::getline(std::cin, input);
		const char command = input[0];
		switch (command) {
		case '1':
			break;
		case '2':
			break;
		case '3':
			selectCharacter(characters).printStats();
			break;
		case '4':
			return 0;
		default:
			std::cout << "Invalid Input!\n\n";
		}
	}
}