#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "Ability.h"
#include "Character.h"
#include <string>

void fight(Character& c1, Character& c2) {
	std::cout << "Fight: ";
	std::cout << "\033[0;96m" << c1.getName() << "\033[0;37m";
	std::cout << " vs ";
	std::cout << "\033[0;94m" << c2.getName() << "\033[0;37m" << "!\n";
	std::cout << "\033[0;37m";
	while (!c1.isDefeated() && !c2.isDefeated()) {
		std::cout << "\033[0;96m";
		c1.attack(c2);
		std::cout << "\033[0;94m";
		if (!c2.isDefeated()) c2.attack(c1);
		std::cout << "\033[0;37m";
	}

	if (c1.isDefeated()) {
		std::cout << "\033[0;31m" << c1.getName() << " has been defeated!\n";
		std::cout << "\033[0;32m" << c2.getName() << " won!\n";
		std::cout << "\033[0;37m";
		c1.increaseLoss();
		c2.increaseWin();
	}
	else {
		std::cout << "\033[0;31m" << c2.getName() << " has been defeated!\n";
		std::cout << "\033[0;32m" << c1.getName() << " won!\n";
		std::cout << "\033[0;37m";
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

void startFight(std::vector<Character>& characters) {
	std::cout << "First character to fight:\n";
	Character& char1 = selectCharacter(characters);
	std::cout << "Second character to fight:\n";
	//using a pointer first in case it needs to be reassigned
	//which cannot be done with reference
	Character* char2_ptr = &selectCharacter(characters);

	while (char1.getName() == char2_ptr->getName()) {
		std::cout << "\033[0;31mYou cannot pick the same character twice!\n";
		std::cout << "\033[0;37m";
		char2_ptr = &selectCharacter(characters);
	}
	Character& char2 = *char2_ptr;

	std::cout << "\nStarting fight between " << char1.getName() << " and " << char2.getName() << std::endl;
	fight(char1, char2);
}

std::unique_ptr<Ability> selectAbility() {
	std::string input;
	unsigned int input_uint;
	//hardcoded Ability-selector :(
	std::cout << "1: Punch\n2: Kick\n3: Heal\n";
	std::cout << "Your selection: ";
	std::getline(std::cin, input);
	input_uint = std::stoul(input);
	switch (input_uint) {
	case 1:
		return std::make_unique<Punch>();
	case 2:
		return std::make_unique<Kick>();
	case 3:
		return std::make_unique<Heal>();
	default:
		std::cout << "\033[0;31mInvalid Ability Number!\n\n";
		std::cout << "\033[0;37m";
		//recursive loop
		return selectAbility();
	}
}

void addCharacter(std::vector<Character>& characters) {
	std::string name;
	std::cout << "Characters name: ";
	std::getline(std::cin, name);
	std::unique_ptr<Ability> ab1 = selectAbility();
	std::unique_ptr<Ability> ab2 = selectAbility();
	//check if both pointers are the same
	while (ab2->getName() == ab1->getName()) {
		std::cout << "\033[0;31mYou cannot pick the same ability 2 times!\n";
		std::cout << "\033[0;37m";
		ab2 = selectAbility();
	}
	characters.emplace_back(name, std::move(ab1), std::move(ab2));
	std::cout << "\033[0;32m" << name + " has been added.\n";
	std::cout << "\033[0;37m";
}

int main() {
	srand(time(nullptr));
	//setting starting output color to be white
	std::cout << "\033[0;37m";

	std::vector<Character> characters;
	characters.emplace_back("Bruce", std::make_unique<Punch>(), std::make_unique<Kick>());
	characters.emplace_back("Chuck", std::make_unique<Kick>(), std::make_unique<Heal>());

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
			startFight(characters);
			break;
		case '2':
			addCharacter(characters);
			break;
		case '3':
			selectCharacter(characters).printStats();
			break;
		case '4':
			return 0;
		default:
			std::cout << "\033[0;31mInvalid Input!\n\n";
			std::cout << "\033[0;37m";
		}
	}
}