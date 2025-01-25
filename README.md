# Snakes and Ladders Game Simulation

This project is a C implementation of a **Snakes and Ladders Game** with enhanced gameplay mechanics. It simulates a board game with four players and features ladders, snakes, and dice rolls. Players progress on the board according to dice rolls and special rules for jumps.

---

## Features

- **Dynamic Linked List Board**: The game board is implemented using a doubly linked list.
- **Snakes and Ladders**: Special positions on the board allow players to jump forward or backward.
- **Multiplayer Support**: Up to 4 players can participate in a game.
- **Dice Rolls**: Players roll a dice (values from 1 to 10) to move forward on the board.
- **Custom Rules**: Rolls greater than 6 move players backward and include ladder or snake jumps.
- **Game End**: The game ends when a player reaches position 100.

---

## How to Run

1. Clone this repository:
   
   - git clone https://github.com/<your-username>/snakes-and-ladders-game.git

## Navigate to the project directory:

  - cd snakes-and-ladders-game
## Compile the code:

  - gcc snakes_and_ladders.c -o snakes_and_ladders
## Run the game:

  - ./snakes_and_ladders

## Rules
- The board consists of 100 positions (1 to 100), with predefined ladders and snakes.
- Players take turns rolling the dice.
- Rolling a number greater than 6 moves the player backward by specific steps.
- Ladders allow players to jump forward, while snakes move them backward.
- The first player to reach position 100 wins.

## Sample Output

  Player[1] press Enter to roll the dice
  Player[1] got:7
  Player[1] got jumped from his position... to:25
  Player 1 at position: 25
  Player 2 at position: 1
  Player 3 at position: 1
  Player 4 at position: 1
  
## Future Enhancements
  - Add support for custom board sizes.
  - Allow players to set snake and ladder positions.
  - Add a graphical user interface (GUI).
