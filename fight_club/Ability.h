#include <iostream>

#pragma once
class Ability {
public:
	virtual void execute(class Character& attacker, class Character& defender) = 0;
	virtual std::string getName() const = 0;
	virtual ~Ability() = default;
};

class Punch : public Ability {
public:
	void execute(Character& attacker, Character& defender) override;
	std::string getName() const override { return "Punch"; }
};

class Kick : public Ability {
public:
	void execute(Character& attacker, Character& defender) override;
	std::string getName() const override { return "Kick"; }
};

class Heal : public Ability {
public:
	void execute(Character& attacker, Character& defender) override;
	std::string getName() const override { return "Heal"; }
};