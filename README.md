# Snake Game (C++)

A classic Snake game implemented in C++ as a console application. The player controls the snake to collect food while avoiding collisions with walls and itself. This project demonstrates object-oriented programming, modular design, and real-time input handling.

## Features
- Real-time snake movement controlled via arrow keys
- Food spawning and score tracking
- Collision detection with walls and self
- Modular structure separating game logic, player, food, and UI handling

## Technologies Used
- **Language:** C++
- **Concepts:** Object-Oriented Programming, Game Loops, Collision Detection, Console I/O
- **Tools:** Visual Studio Code, g++ Compiler, Makefile

## How to Run
1. Clone or download the repository.  
2. Open the project in Visual Studio Code (or your preferred C++ IDE).  
3. Build the project using the provided `Makefile`:
   ```bash
   make  
(This compiles all .cpp files into an executable.)
4. Run the game:
   ./Project
5. To play the game, control the snake with the arrow keys. Eat the food and avoid collisions to score points.

## Project Structure
- `Project.cpp` – Main entry point
- `Player.cpp` / `Player.h` – Snake player logic
- `Food.cpp` / `Food.h` – Food spawning and logic
- `GameMechs.cpp` / `GameMechs.h` – Core game mechanics and logic
- `objPos.cpp` / `objPos.h` – Positioning system for objects
- `objPosArrayList.cpp` / `objPosArrayList.h` – Dynamic storage of object positions
- `MacUILib.cpp` / `MacUILib.h` – Optional UI library for macOS console
- `Makefile` – Build automation
- `.gitignore` – Git ignore rules
- `README.md` – Project description and instructions

