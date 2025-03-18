#include "Ability.h"
#include "Character.h"

void Punch::execute(Character& attacker, Character& defender) {
	std::cout << attacker.getName() << " schlaegt " << defender.getName() << "!\n";
	defender.takeDamage(3);
}

void Kick::execute(Character& attacker, Character& defender) {
	std::cout << attacker.getName() << " tritt " << defender.getName() << "!\n";
	defender.takeDamage(5);
}

void Heal::execute(Character& attacker, Character&) {
	std::cout << attacker.getName() << " heilt sich selbst!\n";
	attacker.heal(2);
}