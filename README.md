# SDL2 Game

This is a simple 2D game project using SDL2.

## Project Structure

- `main.cpp` — Entry point of the game
- `assets/` — Game assets (sprites, textures)
- `class/` — Source files for game classes
- `header/` — Header files for game classes

## Requirements

- SDL2 library (development files)
- C++ compiler (e.g., g++, clang++)

## Building

1. Make sure SDL2 is installed on your system.
2. Compile the project using your preferred C++ compiler. Example command:
   ```sh
   g++ -Iheader -I<SDL2_include_path> -L<SDL2_lib_path> main.cpp class/*.cpp -lSDL2 -o sdl2-game
   ```
   Replace `<SDL2_include_path>` and `<SDL2_lib_path>` with the actual paths to your SDL2 installation.

## Running

Run the compiled executable:
```sh
./sdl2-game
```

## Assets

All game textures are located in the `assets/` folder.

## License

This project is provided for educational purposes only.
