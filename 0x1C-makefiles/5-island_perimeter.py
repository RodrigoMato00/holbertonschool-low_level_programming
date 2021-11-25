#!/usr/bin/python3
"""
returns the perimeter of the island described in grid:
grid is a list of list of integers:
-0 represents a water zone
-1 represents a land zone
-One cell is a square with side length 1
-Grid cells are connected horizontally/vertically (not diagonally).
-Grid is rectangular, width and height don’t exceed 100
"""
def island_perimeter(grid):
    """ grid is a list of list of integers:
    -0 represents a water zone
    -1 represents a land zone
    -One cell is a square with side length 1
    -Grid cells are connected horizontally/vertically (not diagonally).
    -Grid is rectangular, width and height don’t exceed 10
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i == 0 or grid[i-1][j] == 0:
                    perimeter += 1
                if j == 0 or grid[i][j-1] == 0:
                    perimeter += 1
                if i == len(grid)-1 or grid[i+1][j] == 0:
                    perimeter += 1
                if j == len(grid[i])-1 or grid[i][j+1] == 0:
                    perimeter += 1
    return perimeter
