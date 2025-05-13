#include "pokemon.hpp"
#include "move.hpp"
#include <iostream>
#include <cmath>

// Default Constructor
Pokemon::Pokemon() : name(""), type(""), moves(nullptr), numMoves(0), attack(0), defense(0), hp(0), max_hp(0), level(1), healed(false) {}

// Parameterized Constructor
Pokemon::Pokemon(const std::string& name, const std::string& type, Move* moves, int numMoves, int attack, int defense, int hp, int max_hp, int level, bool healed)
    : name(name), type(type), attack(attack), defense(defense), hp(hp), max_hp(max_hp), level(level), healed(healed), numMoves(numMoves) {
    	this->moves = new Move[numMoves];
    	for (int i = 0; i < numMoves; i++) {
        	this->moves[i] = moves[i];
    	}
}

// Copy Constructor
Pokemon::Pokemon(const Pokemon& other) : name(other.name), type(other.type), attack(other.attack), defense(other.defense), hp(other.hp), max_hp(other.max_hp), level(other.level), healed(other.healed), numMoves(other.numMoves) {
    	this->moves = new Move[numMoves];
    	for (int i = 0; i < numMoves; i++) {
        	this->moves[i] = other.moves[i];
    	}
}

// Assignment Operator
Pokemon& Pokemon::operator=(const Pokemon& other) {
    	if (this != &other) {
        	delete[] moves;
        	name = other.name;
        	type = other.type;
        	attack = other.attack;
        	defense = other.defense;
        	hp = other.hp;
        	max_hp = other.max_hp;
        	level = other.level;
        	healed = other.healed;
        	numMoves = other.numMoves;

        	moves = new Move[numMoves];
        	for (int i = 0; i < numMoves; i++) {
            		moves[i] = other.moves[i];
        	}
    	}
    	return *this;
}

// Destructor
Pokemon::~Pokemon() {
    	delete[] moves;
}

// Getters
std::string Pokemon::getName() const { return name; }
std::string Pokemon::getType() const { return type; }
int Pokemon::getHP() const { return hp; }
int Pokemon::getMaxHP() const { return max_hp; }
int Pokemon::getAttack() const { return attack; }
int Pokemon::getDefense() const { return defense; }
int Pokemon::getNumMoves() const { return numMoves; }
int Pokemon::getLevel() const { return level; }
bool Pokemon::isHealed() const { return healed; }

Move Pokemon::getMove(int index) const {
    	if (index >= 0 && index < numMoves) {
        	return moves[index];
    	}
    	return Move();
}

// Member Functions
void Pokemon::printMoves() const {
    	for (int i = 0; i < numMoves; i++) {
        	std::cout << i + 1 << ". " << moves[i].getName() << " (" << moves[i].getRemainingUses() << " uses remaining)" << std::endl;
    	}
}

void Pokemon::takeDamage(int damage) {
    	hp -= damage;
    	if (hp < 0) hp = 0;
}

void Pokemon::heal() {
    	if (!healed) {
        	int healAmount = 10;
        	hp = std::min(hp + healAmount, max_hp);
        	healed = true;
    	}
}

bool Pokemon::isFainted() const {
    	return hp <= 0;
}

void Pokemon::useMove(Pokemon& target, int moveIndex) {
    	if (moveIndex >= 0 && moveIndex < numMoves) {
        	Move& selectedMove = moves[moveIndex];
        	if (selectedMove.getRemainingUses() > 0) {
            		int damage = calculateDamage(selectedMove, target);
            		target.takeDamage(damage);
            		selectedMove.useMove();
            			std::cout << name << " used " << selectedMove.getName() << "! " << target.getName() << " took " << damage << " damage." << std::endl;
        } else {
            std::cout << "No uses remaining for this move!" << std::endl;
        }
    }
}

int Pokemon::calculateDamage(const Move& move, const Pokemon& target) const {
    	float typeMultiplier = 1.0f;
    
    	if (move.getType() == "fire" && target.getType() == "grass") typeMultiplier = 2.0f;
    	if (move.getType() == "water" && target.getType() == "fire") typeMultiplier = 2.0f;
    	if (move.getType() == "grass" && target.getType() == "water") typeMultiplier = 2.0f;
    	if (move.getType() == "fire" && target.getType() == "water") typeMultiplier = 0.5f;
    	if (move.getType() == "water" && target.getType() == "grass") typeMultiplier = 0.5f;
    	if (move.getType() == "grass" && target.getType() == "fire") typeMultiplier = 0.5f;

    // Determine critical hit (10% chance of 3x damage, 90% chance of normal damage)
    	int randomCritical = (rand() % 10 == 0) ? 3 : 1;

    	float baseDamage = static_cast<float>(move.getBaseDamage());
    	float damage = baseDamage * (static_cast<float>(attack) / target.getDefense()) * typeMultiplier * randomCritical;
    	damage = std::ceil(damage);

    // Print the required output
    	std::cout << "Performing damage calculation..." << std::endl;
    	std::cout << "Value of type_interaction: " << typeMultiplier << std::endl;
    	std::cout << "Value of random_critical: " << randomCritical << std::endl;
    	std::cout << "Value of damage: " << static_cast<int>(damage) << std::endl;

    	return static_cast<int>(damage);
}

