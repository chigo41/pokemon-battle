#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "pokemon.hpp"
#include <iostream>

class Battle {
	private:
    		Pokemon pokemon_p1;
    		Pokemon pokemon_p2;
    		bool player1Turn;   
    		bool gameOver;      

	public:
    	
/**
     * Function: Battle
     * Description: Constructor for initializing a battle with two Pokémon.
     * Parameters: p1 - The first Pokémon, p2 - The second Pokémon.
     * Returns: None
     * Side effects: Initializes battle state and sets turn order.
     */
    		Battle(const Pokemon& p1, const Pokemon& p2);

     /**
     * Function: startBattle
     * Description: Initiates the battle loop until one Pokémon faints.
     * Parameters: None
     * Returns: None
     * Side effects: Alternates turns and checks for game over condition.
     */
    		void startBattle();
    
/**
     * Function: playerTurn
     * Description: Executes the current player's turn, allowing them to use a move or heal.
     * Parameters: None
     * Returns: None
     * Side effects: Adjusts HP, move uses, and battle state.
     */
		void playerTurn();
    
/**
     * Function: switchTurn
     * Description: Switches the active turn between the two players.
     * Parameters: None
     * Returns: None
     * Side effects: Updates the player1Turn flag.
     */
		void switchTurn();
    
/**
     * Function: checkWinner
     * Description: Checks if either Pokémon has fainted and ends the game if so.
     * Parameters: None
     * Returns: None
     * Side effects: Sets gameOver to true if a Pokémon faints.
     */
		void checkWinner();
    
/**
     * Function: isGameOver
     * Description: Checks the game state to see if the battle is over.
     * Parameters: None
     * Returns: true if the game is over, false otherwise.
     * Side effects: None
     */
		bool isGameOver() const;

    /**
     * Function: displayStatus
     * Description: Displays the current HP and status of both Pokémon.
     * Parameters: None
     * Returns: None
     * Side effects: Outputs to console.
     */
    		void displayStatus() const;
    		
/**
     * Function: displayMoves
     * Description: Displays the available moves for a given Pokémon.
     * Parameters: p - The Pokémon whose moves to display.
     * Returns: None
     * Side effects: Outputs move information to console.
     */		
		void displayMoves(const Pokemon& p) const;

/**
     * Function: healPokemon
     * Description: Allows the current player to heal their Pokémon.
     * Parameters: p - The Pokémon to be healed.
     * Returns: None
     * Side effects: Increases HP and sets the healed flag.
     */
    		void healPokemon(Pokemon& p);
};

#endif

