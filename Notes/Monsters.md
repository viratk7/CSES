## Problem

Given a grid with monsters and a player, find an escape path such that the player always reaches every cell before any monster.

---

## Solution

1. Run a multi-source BFS from all monsters.
2. Compute the earliest time each monster reaches every cell.
3. Run BFS from the player's starting position.
4. Only move into a cell if

   `monster_time > my_time + 1`

5. Store parent pointers and reconstruct the path if an exit is reached.

---

## Code

```codefile
../Monsters.cpp
```