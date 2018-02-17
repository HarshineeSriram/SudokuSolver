# SudokuSolver

This program deals with the solving of a sudoku solver.
Steps involved are:
1. Find a cell with least number of legal moves.
2. Assign the first legal number to it.
3. Then finds the next cell with least number of legal moves.
4. When a dead end is encountered, it assign the next legal number in step 2.
Working:
1.The Algorithm first visits each empty cell and assign it a priority value based on the number of legal moves by checking row, column, and 3x3 box constraints.
2.The legal moves are checked by comparing numbers 1 to 9 with each row, column and 3x3 box constraints.
3.After assigning the priority value to each empty cell, it assigns the empty cell with the least priority value.
4.For easy puzzles the priority value of the empty cells is mostly one, so the puzzle is easily solved by just assigning each empty cell with the correct value one by one.
5.But if the least priority value is greater than one, it assigns the empty cell with first legal number, and places a tracker variable on it. And proceed in the same way.
6.A dead end is encountered when an empty cell have no legal moves. In this case the algorithm assigns the empty cell with the tracker variable with the next possible number and deletes all the cells which are entered after the empty cell with the tracker variable.
7.The tracker variables record the sequence in which different empty cells are assigned with values. They are used to delete and modify the incorrect cells.
And hence the Algorithm finds the correct solution for each valid Sudoku puzzle.
