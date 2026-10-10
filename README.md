# Pokémon Battle Simulator

A two-player, turn-based Pokémon battle game for the terminal, written in C++. Each trainer picks a starter, Charmander, Squirtle, or Bulbasaur, and the two take turns attacking or healing until one Pokémon faints.

The project practices object-oriented design in C++: class composition, manual dynamic memory management (the Rule of Three), and input validation.

## Demo

```text
Trainer 1: Which pokemon would you like?
1. Charmander
2. Squirtle
3. Bulbasaur
Your choice: 1
Trainer 2: Which pokemon would you like?
1. Squirtle
2. Bulbasaur
Your choice: 1
Charmander HP: 18/18
Squirtle HP: 22/22
Charmander's turn! Choose an action:
1. Use Move
2. Heal
Choice: 1
1. Ember (15 uses remaining)
Select move: 1
Performing damage calculation...
Value of type_interaction: 0.5
Value of random_critical: 1
Value of damage: 3
Charmander used Ember! Squirtle took 3 damage.
```

## Features

- **Two-player local battles.** Trainer 2 can't pick the same Pokémon as Trainer 1.
- **Type matchups.** Fire beats grass, water beats fire, and grass beats water (×2). The reverse matchups deal half damage (×0.5).
- **Critical hits.** Each attack has a 10% chance to deal triple damage.
- **Limited move uses.** Every move has a set number of uses, and the game tracks what's left.
- **One heal per battle.** A Pokémon can restore 10 HP once, up to its max HP.
- **Input validation.** Invalid menu choices and move numbers are rejected and the player is asked again.

## The Pokémon

| Pokémon | Type | HP | Attack | Defense | Moves (base damage / uses) |
|---|---|---|---|---|---|
| Charmander | Fire | 18 | 6 | 4 | Ember: fire, 5 / 15 |
| Squirtle | Water | 22 | 4 | 6 | Tackle: normal, 3 / unlimited · Water Gun: water, 5 / 3 |
| Bulbasaur | Grass | 20 | 5 | 5 | Tackle: normal, 3 / unlimited · Vine Whip: grass, 5 / 3 |

## Damage formula

```
damage = ceil( base_damage × (attacker.attack / defender.defense) × type_multiplier × critical )
```

`type_multiplier` is 2, 1, or 0.5, and `critical` is 3 (10% chance) or 1.

## Build and run

You need a C++11 compiler such as `g++` or `clang++`.

```bash
g++ -std=c++11 main.cpp pokemon.cpp move.cpp battle.cpp startup.cpp -o pokemon
./pokemon
```

## Project structure

| File | Purpose |
|---|---|
| `main.cpp` | Seeds the random number generator, sets up the chosen Pokémon and their moves, and starts the battle |
| `startup.hpp/.cpp` | Starter selection menus with input validation |
| `pokemon.hpp/.cpp` | `Pokemon` class: stats, a dynamic array of moves, damage calculation, healing, fainting |
| `move.hpp/.cpp` | `Move` class: name, type, base damage, remaining uses |
| `battle.hpp/.cpp` | `Battle` class: turn loop, action menu, status display, winner check |

## Design notes

- **Composition.** A `Battle` holds two `Pokemon`, and each `Pokemon` owns an array of `Move` objects.
- **Dynamic memory.** Each Pokémon stores its moves in a heap-allocated array (`new Move[]`). The class follows the **Rule of Three**: a copy constructor, a copy assignment operator, and a destructor all make deep copies and free memory safely, so Pokémon can be copied into the battle without memory leaks or double frees.
- **Encapsulation.** All state is private and read through const getters. Only `takeDamage`, `heal`, and `useMove` change a Pokémon.

## Possible improvements

- Make the battle menu recover from non-numeric input (the starter menus already handle this).
- Add a single-player mode with a computer opponent.
- Add more Pokémon, types, and moves, loaded from a data file.
- Replace the raw move array with `std::vector<Move>`.


