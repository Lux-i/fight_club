#include "Ability.h"
#include "Character.h"

void Punch::execute(Character& attacker, Character& defender) {
	std::cout << attacker.getName() << " punches " << defender.getName() << "!\n";
	defender.takeDamage(3);
}

void Kick::execute(Character& attacker, Character& defender) {
	std::cout << attacker.getName() << " kicks " << defender.getName() << "!\n";
	defender.takeDamage(5);
}

void Heal::execute(Character& attacker, Character&) {
	std::cout << attacker.getName() << " heals themselves!\n";
	attacker.heal(2);
}