#include "battle.hpp"
#include <iostream>

// Constructor
Battle::Battle(const Pokemon& p1, const Pokemon& p2)
	: pokemon_p1(p1), pokemon_p2(p2), player1Turn(true), gameOver(false) {}

// Start Battle
void Battle::startBattle() {
	while (!gameOver) {
        	displayStatus();
        	playerTurn();
        	checkWinner();
        	switchTurn();
    }
}

// Display Status
void Battle::displayStatus() const {
    	std::cout << pokemon_p1.getName() << " HP: " << pokemon_p1.getHP() << "/" << pokemon_p1.getMaxHP() << std::endl;
    	std::cout << pokemon_p2.getName() << " HP: " << pokemon_p2.getHP() << "/" << pokemon_p2.getMaxHP() << std::endl;
}

// Display Moves
void Battle::displayMoves(const Pokemon& p) const {
    	p.printMoves();
}

// Player Turn
void Battle::playerTurn() {
    	Pokemon& attacker = player1Turn ? pokemon_p1 : pokemon_p2;
    	Pokemon& defender = player1Turn ? pokemon_p2 : pokemon_p1;

    	int choice;
    	bool validInput = false;

    	while (!validInput) {
        	std::cout << attacker.getName() << "'s turn! Choose an action: " << std::endl;
        	std::cout << "1. Use Move" << std::endl;
        	std::cout << "2. Heal" << std::endl;
        	std::cout << "Choice: ";
        	std::cin >> choice;

        if (choice == 1) {
            	displayMoves(attacker);
            	int moveIndex;
            	std::cout << "Select move: ";
            	std::cin >> moveIndex;
            	moveIndex -= 1;

            	if (moveIndex >= 0 && moveIndex < attacker.getNumMoves()) {
                	attacker.useMove(defender, moveIndex);
                	validInput = true;
            	} else {
                	std::cout << "Invalid move index! Please try again." << std::endl;
            	}
        }
        else if (choice == 2) {
            	if (!attacker.isHealed()) {
                	attacker.heal();
                	validInput = true;
            	} else {
                	std::cout << "You have already used your healing!" << std::endl;
            	}
        	} else {
            		std::cout << "Invalid choice! Please try again." << std::endl;
        	}
    	}
}

// Switch Turn
void Battle::switchTurn() {
    	player1Turn = !player1Turn;
}

// Check Winner
void Battle::checkWinner() {
    	if (pokemon_p1.isFainted()) {
        	std::cout << pokemon_p1.getName() << " has fainted! " << pokemon_p2.getName() << " wins!" << std::endl;
        	gameOver = true;
    	}
    	else if (pokemon_p2.isFainted()) {
        	std::cout << pokemon_p2.getName() << " has fainted! " << pokemon_p1.getName() << " wins!" << std::endl;
        	gameOver = true;
    	}
}

// Check Game Over State
bool Battle::isGameOver() const {
    	return gameOver;
}

