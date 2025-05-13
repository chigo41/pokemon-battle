#ifndef POKEMON_HPP
#define POKEMON_HPP

#include "move.hpp"
#include <string>

class Pokemon {
	private:
    		std::string name;
    		std::string type;
    		Move* moves;
    		int numMoves;
    		int attack;
    		int defense;
    		int hp;
    		int max_hp;
    		int level;
    		bool healed;

	public:

    /**
     * Function: Pokemon
     * Description: Default constructor for the Pokemon class.
     * Parameters: None
     * Returns: None
     * Side effects: Initializes member variables to default values.
     */
    		Pokemon();
    
/**
     * Function: Pokemon
     * Description: Parameterized constructor for the Pokemon class.
     * Parameters: name, type, moves, numMoves, attack, defense, hp, max_hp, level, healed
     * Returns: None
     * Side effects: Dynamically allocates memory for moves array.
     */	
		Pokemon(const std::string& name, const std::string& type, Move* moves, int numMoves, int attack, int defense, int hp, int max_hp, int level, bool healed);
    
/**
     * Function: Pokemon (Copy Constructor)
     * Description: Creates a deep copy of a Pokemon object.
     * Parameters: other - The Pokemon object to copy.
     * Returns: None
     * Side effects: Allocates new memory for the moves array.
     */
		Pokemon(const Pokemon& other);
    
/**
     * Function: operator=
     * Description: Assignment operator for the Pokemon class.
     * Parameters: other - The Pokemon object to copy.
     * Returns: A reference to the assigned Pokemon object.
     * Side effects: Deletes existing moves array and allocates new memory.
     */
		Pokemon& operator=(const Pokemon& other);
    
/**
     * Function: ~Pokemon
     * Description: Destructor for the Pokemon class.
     * Parameters: None
     * Returns: None
     * Side effects: Frees dynamically allocated memory for moves array.
     */
		~Pokemon();

    /**
     * Function: printMoves
     * Description: Prints all moves of the Pokemon to the console.
     * Parameters: None
     * Returns: None
     * Side effects: Outputs move information to the console.
     */
    		void printMoves() const;
    		
		/**
     * Function: useMove
     * Description: Executes a move against a target Pokemon.
     * Parameters: target - The target Pokemon, moveIndex - The index of the move to use.
     * Returns: None
     * Side effects: Reduces move count and potentially reduces target's HP.
     */
		void useMove(Pokemon& target, int moveIndex);
    		
 /**
     * Function: heal
     * Description: Heals the Pokemon by a fixed amount.
     * Parameters: None
     * Returns: None
     * Side effects: Increases Pokemon's HP, sets healed flag.
     */
		void heal();
    		
/**
     * Function: isFainted
     * Description: Checks if the Pokemon has fainted.
     * Parameters: None
     * Returns: true if HP is 0, false otherwise.
     * Side effects: None
     */
		bool isFainted() const;
    
 /**
     * Function: takeDamage
     * Description: Reduces the Pokemon's HP by a specified amount.
     * Parameters: damage - The amount of damage to apply.
     * Returns: None
     * Side effects: Adjusts HP value.
     */
		void takeDamage(int damage);
    
/**
     * Function: calculateDamage
     * Description: Calculates damage based on move and target Pokemon.
     * Parameters: move - The move used, target - The target Pokemon.
     * Returns: The calculated damage as an integer.
     * Side effects: None
     */
		int calculateDamage(const Move& move, const Pokemon& target) const;

   /**
     * Function: getName
     * Description: Retrieves the Pokemon's name.
     * Parameters: None
     * Returns: The name as a string.
     * Side effects: None
     */
    		std::string getName() const;
    		
/**
     * Function: getType
     * Description: Retrieves the Pokemon's type.
     * Parameters: None
     * Returns: The type as a string.
     * Side effects: None
     */
		std::string getType() const;
    	
/**
     * Function: getMaxHP
     * Description: Retrieves the maximum HP of the Pokemon.
     * Parameters: None
     * Returns: The max HP as an integer.
     * Side effects: None
     */
		int getHP() const;
    		
		/**
     * Function: getMaxHP
     * Description: Retrieves the maximum HP of the Pokemon.
     * Parameters: None
     * Returns: The max HP as an integer.
     * Side effects: None
     */
		int getMaxHP() const;
    		int getAttack() const;
    		int getDefense() const;
    		int getNumMoves() const;
    		
/**
     * Function: getLevel
     * Description: Retrieves the level of the Pokemon.
     * Parameters: None
     * Returns: The level as an integer.
     * Side effects: None
     */
		int getLevel() const;
    		
/**
     * Function: isHealed
     * Description: Checks if the Pokemon has been healed.
     * Parameters: None
     * Returns: true if healed, false otherwise.
     * Side effects: None
     */
		bool isHealed() const;
    		
		/**
     * Function: getMove
     * Description: Retrieves a specific move by index.
     * Parameters: index - The index of the move.
     * Returns: The move object.
     * Side effects: None
     */
		Move getMove(int index) const;
};

#endif

