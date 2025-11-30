# SUDOKU-Game-Checker
## Team members
- Muhammad Salman Ali Malik
- Syed Muhammad Usman Shah
- Muhammad Nouman Majeed

A Sudoku Puzzle with solver and hints

<img width="977" height="1601" alt="sudoku" src="https://github.com/user-attachments/assets/2d0931c5-51e4-46cd-8b2b-58a977c4399c" />
# **Sudoku Generator and Player Code – Explanation**

## **Purpose**

The purpose of this program is to create a playable Sudoku puzzle. It generates a fully completed 9×9 Sudoku board, then removes some values to allow the user to fill them in. It ensures that all rules of Sudoku are followed, namely that each number 1–9 appears exactly once in each row, column, and 3×3 subgrid.

---

## **Core Functionality**

1. **Board Representation**

   * The program uses a 2D integer array of size 9×9 to represent the Sudoku board.
   * Each cell stores a number from 1 to 9 or 0 if the cell is empty.

2. **Checking Constraints**

   * **Row Check:** Ensures no repeated number exists in the same row.
   * **Column Check:** Ensures no repeated number exists in the same column.
   * **Box Check:** Ensures no repeated number exists in the 3×3 subgrid corresponding to a cell.

3. **Board Generation**

   * Numbers are filled recursively, often using **backtracking**:

     * The algorithm tries a number in a cell.
     * It checks if the number violates any Sudoku rules.
     * If valid, it moves to the next cell.
     * If invalid, it tries a different number or backtracks to the previous cell.
   * This ensures the generated board is always valid and solvable.

4. **Removing Numbers for the Puzzle**

   * After generating a complete board, the program randomly removes some cells to create a playable puzzle.
   * The number of removed cells can determine difficulty.
   * The resulting board is partially filled, ready for user input.

5. **User Interaction**

   * The user can input numbers into empty cells.
   * The program can validate the user’s moves to prevent rule violations.

---

## **Programming Concepts Used**

* **Recursion and Backtracking:** To fill the board and ensure each number placement is valid.
* **Random Number Generation:** For creating unpredictable Sudoku puzzles.
* **Array Manipulation:** For handling the 2D board and checking constraints.
* **Input/Output Handling:** For interacting with the user and displaying the board.

---

## **Summary**

This C++ Sudoku program is an example of algorithmic problem-solving rather than AI. It efficiently generates a valid Sudoku puzzle and allows the user to play it. While it uses recursion and constraint checking to ensure rules are followed, it does not employ machine learning or predictive algorithms. The program demonstrates logical thinking, backtracking techniques, and structured programming for a classic puzzle game.


