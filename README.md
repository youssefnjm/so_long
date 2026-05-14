# so_long - A Simple 2D Game

## Project Overview

**so_long** is a project at 42 School that involves developing a basic 2D game using the **MiniLibX** library. The goal is to create a small "top-down" game where a character collects items and reaches an exit while navigating a map.

This project focuses on window management, handling user input (keyboard and mouse), and implementing essential game mechanics like movement and map validation.

## Features

* **Smooth Movement**: Character movement handled via `WASD` or Arrow keys.
* **Sprite Rendering**: Textures for the player, walls, collectibles, and the exit.
* **Move Counter**: Real-time display of the number of steps taken in the terminal.
* **Map Validation**: Ensures the map is playable before the game starts.
* **Event Handling**: Clean exit on `ESC` or clicking the window's close button.

## Map Validation & Flood Fill

A critical requirement of **so_long** is ensuring the map is valid. I implemented a **Flood Fill algorithm** to verify that:

1. There is a **valid path** to collect all items (`C`).
2. The **exit** (`E`) is reachable from the player's starting position (`P`).

The algorithm works by "flooding" the map from the player's position and checking if all required components were reached. If the map is unplayable, the program exits gracefully with a custom error message.

## Technical Details

* **Language**: C
* **Library**: MiniLibX (Graphic library for X11/Cocoa)
* **Graphics**: XPM texture handling.
* **Memory Management**: 100% leak-free, with all textures and window pointers properly cleared on exit.

## Installation & Usage

1. **Clone the repository:**
```bash
git clone git@github.com:youssefnjm/so_long.git
cd so_long
```


2. **Compile:**

```bash
make
```
3.  **Run a map:**
    
```bash
./so_long maps/level1.ber
```

## Map Requirements
The game parses `.ber` files which must follow these rules:
*   The map must be a **rectangle** surrounded by walls (`1`).
*   It must contain at least one **Exit** (`E`), one **Collectible** (`C`), and one **Starting Position** (`P`).
*   Empty spaces are represented by `0`.

## What I Learned
*   **Graphic Programming**: Understanding how the game loop works and how to push images to a window.
*   **Algorithm Design**: Implementing **Flood Fill** to solve pathfinding verification.
*   **System Calls**: Managing file descriptors for map reading and error handling.
