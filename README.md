C practice
============

**Objective:** Reproduce the Game of Life cellurar automaton (Conway, 1970)

**Quick description:** The universe of the Game of Life is an infinite two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead. Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent.

**Rules:**

- Any live cell with fewer than two live neighbours dies, as if caused by under-population.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overcrowding.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction


**GUI Usage**
Requires Python 2.7.x. Version 2.6 might work, but untested. Not functional in Python 3.

	`python gol_gui.py <compiled_executable_name>`
