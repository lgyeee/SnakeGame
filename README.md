# Snake Game

A classic Snake game built using SFML (Simple and Fast Multimedia Library). This project includes basic snake movement, fruit collection, scorekeeping, and game-over conditions.

## Features

- Basic snake movement controlled by arrow keys
- Fruit collection to increase score and snake length
- Game-over conditions when snake collides with itself or the boundaries
- Scoreboard to keep track of the player's score
- Pause and resume functionality
- High-quality font for displaying scores and messages

## Upcoming Features

- Different types of fruits with varying scores
- Mines that deduct points or end the game
- More sound effects for different actions
- Special power-ups and obstacles
- Level progression and increasing difficulty
- Improved graphical effects and animations

## Requirements

- C++11 or higher
- SFML library (2.6.1 or later)
- A compatible compiler (e.g., g++, clang++)

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/lgyeee/SnakeGame.git
   cd SnakeGame
   ```

2. Install SFML:

   On macOS:
   ```bash
   brew install sfml
   ```

   On Ubuntu:
   ```bash
   sudo apt-get install libsfml-dev
   ```

3. Build the project using Makefile:

   ```bash
   make
   ```

4. Run the game:

   ```bash
   ./build/SnakeGame
   ```

## Usage

### Controls

- **Arrow Keys**: Control the direction of the snake.
  - `Up Arrow`: Move the snake up.
  - `Down Arrow`: Move the snake down.
  - `Left Arrow`: Move the snake left.
  - `Right Arrow`: Move the snake right.
- **P Key**: Pause and resume the game.
- **Escape Key**: Exit the game.

### Game Interactions

- **Collect Fruits**: Increase your score and snake length by collecting fruits.
- **Avoid Collisions**: 
    - Prevent the snake from colliding with itself 
    - Prevent the snake from hitting boundaries to avoid game over.
- **Pause/Resume**: You can pause the game at any time by pressing the \`P\` key and resume by pressing it again.
- **Exit Game**: Press the \`Escape\` key to exit the game at any time.

## Project Structure

```
.
├── Makefile           # Build configuration
├── README.md          # Project documentation
├── src                # Source files
│   ├── main.cpp       # Entry point of the game
│   ├── Game.cpp       # Main game logic
│   ├── Snake.cpp      # Snake class implementation
│   ├── Fruit.cpp      # Fruit class implementation
├── include            # Header files
│   ├── Game.h         # Game class declaration
│   ├── Snake.h        # Snake class declaration
│   ├── Fruit.h        # Fruit class declaration
├── assets             # Assets for the game
│   ├── fonts          # Font files
│   │   └── font.ttf
│   ├── sounds         # Sound effect files
│   │   ├── move.wav
│   │   ├── eat.wav
│   │   └── gameover.wav
│   └── textures       # Texture files
│       ├── snake_head.png
│       ├── snake_body.png
│       └── fruit.png
└── build              # Compiled binary and object files
    └── SnakeGame      # Executable file
```

## Contributing

Contributions are welcome! Please fork this repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE.txt) file for more details.

## Contact

If you have any questions or suggestions, feel free to reach out to me at  [guanyilin0713@gmail.com].

---

Enjoy playing the Snake Game!
