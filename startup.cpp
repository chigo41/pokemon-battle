// You can edit this file however you'd like. You can even get rid of it if you
// want to replace it with your own solution.

#include <iostream>
#include "startup.hpp"

// Helper function to clear input buffer
void clearInputBuffer() {
    	std::cin.clear();
    	std::cin.ignore(10000, '\n');
}

int prompt_first_pokemon() {
    	int choice;
    	do {
        	std::cout << "Trainer 1: Which pokemon would you like?" << std::endl;
        	std::cout << "1. Charmander" << std::endl;
        	std::cout << "2. Squirtle" << std::endl;
        	std::cout << "3. Bulbasaur" << std::endl;
        	std::cout << "Your choice: ";

        	std::cin >> choice;
        	if (std::cin.fail() || choice < 1 || choice > 3) {
            	std::cout << "Invalid option! Please enter a valid choice." << std::endl;
            	clearInputBuffer();
        	} else {
            	break;
        }
        	std::cout << std::endl;
    	} while (true);

    	return choice;
}

int prompt_second_pokemon(int blacklisted_pokemon) {
    	int choice;
    	std::string options[3] = {"Charmander", "Squirtle", "Bulbasaur"};

    	do {
        	std::cout << "Trainer 2: Which pokemon would you like?" << std::endl;

        int index = 1;
        for (int i = 1; i <= 3; ++i) {
            	if (i != blacklisted_pokemon) {
                	std::cout << index << ". " << options[i - 1] << std::endl;
                	index++;
            	}
        }

        	std::cout << "Your choice: ";
        	std::cin >> choice;

        	if (std::cin.fail() || choice < 1 || choice > 2) {
            std::cout << "Invalid option! Please enter a valid choice." << std::endl;
            clearInputBuffer();
        } else {
            break;
        }
    	} while (true);

    // Adjust choice to match actual Pokémon index
    	if (blacklisted_pokemon == 1) {
        	return choice + 1;  // 1 = Squirtle, 2 = Bulbasaur
    	} else if (blacklisted_pokemon == 2) {
        	return (choice == 1) ? 1 : 3;  // 1 = Charmander, 2 = Bulbasaur
    	} else {
        	return choice;  // 1 = Charmander, 2 = Squirtle
    	}
}
