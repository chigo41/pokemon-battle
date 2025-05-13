/* Author: Chigozirim Odoemelam
Implement a simplified Pokémon battle game in C++ using OOP. Two trainers choose from Charmander, Squirtle, or Bulbasaur and take turns attacking or healing until one Pokémon's HP reaches zero. Focus on class composition, dynamic arrays, and error handling.
*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include "pokemon.hpp"
#include "battle.hpp"
#include "startup.hpp"

int main() {
	srand(static_cast<unsigned int>(time(0)));    


    // Prompt Trainer 1 for their Pokémon choice
    	int choice1 = prompt_first_pokemon();
    	int choice2 = prompt_second_pokemon(choice1);

    // Create Pokémon based on choices
    	Move charmanderMoves[] = { Move("Ember", "fire", 5, 15) };
    	Move squirtleMoves[] = { Move("Tackle", "normal", 3, 10000), Move("Water Gun", "water", 5, 3) };
    	Move bulbasaurMoves[] = { Move("Tackle", "normal", 3, 10000), Move("Vine Whip", "grass", 5, 3) };

    	Pokemon p1, p2;

    	if (choice1 == 1) p1 = Pokemon("Charmander", "fire", charmanderMoves, 1, 6, 4, 18, 18, 1, false);
    	else if (choice1 == 2) p1 = Pokemon("Squirtle", "water", squirtleMoves, 2, 4, 6, 22, 22, 1, false);
    	else if (choice1 == 3) p1 = Pokemon("Bulbasaur", "grass", bulbasaurMoves, 2, 5, 5, 20, 20, 1, false);

    	if (choice2 == 1) p2 = Pokemon("Charmander", "fire", charmanderMoves, 1, 6, 4, 18, 18, 1, false);
    	else if (choice2 == 2) p2 = Pokemon("Squirtle", "water", squirtleMoves, 2, 4, 6, 22, 22, 1, false);
    	else if (choice2 == 3) p2 = Pokemon("Bulbasaur", "grass", bulbasaurMoves, 2, 5, 5, 20, 20, 1, false);

    // Start the battle
    	Battle battle(p1, p2);
    	battle.startBattle();

        	return 0;
}

