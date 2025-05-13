#include "move.hpp"
#include <iostream>

// Default Constructor
Move::Move() : name(""), type(""), baseDamage(0), remainingUses(0) {}

// Parameterized Constructor
Move::Move(const std::string& name, const std::string& type, int baseDamage, int remainingUses)
    : name(name), type(type), baseDamage(baseDamage), remainingUses(remainingUses) {}

// Use Move
void Move::useMove() {
    	if (remainingUses > 0) {
        	remainingUses--;
    	}
}

// Check if Move has uses left
bool Move::hasUses() const {
    	return remainingUses > 0;
}

// Getters
std::string Move::getName() const { return name; }
std::string Move::getType() const { return type; }
int Move::getBaseDamage() const { return baseDamage; }
int Move::getRemainingUses() const { return remainingUses; }



