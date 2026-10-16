#include <vector>
#include <assert.h>
#include "Islands.h"
#include <array>
#include <iostream>

/*
 * To analyze satellite images, a geospatial company studies maps of remote ocean regions.
 * Each map is represented as a grid where land and water are identified.
 *
 * Your task is to determine how many separate islands are present on a given map.
 * The map is represented as a 2D grid of characters :
 *    - '1' represents land
 *    - '0' represents water
 *
 * An island is defined as a group of connected land cells.
 * Cells are considered connected if they are adjacent horizontally or vertically(not diagonally).
 * The grid is surrounded by water.
 * 
 * Implement the function count_islands which returns the total number of islands present in the map.
 */

struct Direction 
{
    int dx;
    int dy;
};


constexpr std::array<Direction, 4> directions = { {
    {-1,  0}, // Haut
    { 1,  0}, // Bas
    { 0, -1}, // Gauche
    { 0,  1}  // Droite
} };
void ParcoursProfondeur(std::vector<std::vector<char>>& grid, int x, int y)
{
    int nbLignes = grid.size();
    int nbColonnes = grid[0].size();

    grid[x][y] = '0';

    for (const auto& dir : directions)
    {
        int voisinR = x + dir.dx;
        int voisinC = y + dir.dy;

        if (voisinR >= 0 && voisinR < nbLignes && voisinC >= 0 && voisinC < nbColonnes)
        {
            if (grid[voisinR][voisinC] == '1')
            {
                ParcoursProfondeur(grid, voisinR, voisinC);
            }
        }
    }
}

int count_islands(std::vector<std::vector<char>>& grid)
{
    if (grid.empty() || grid[0].empty()) return 0;

    int island_count = 0;
    int nbLignes = grid.size();
    int nbColonnes = grid[0].size();

    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
        {
            if (grid[i][j] == '1')
            {
                island_count++;
                ParcoursProfondeur(grid, i, j);
            }
        }
    }

    return island_count;
}

int main()
{
    {
        std::vector<std::vector<char>> grid = {
            {'1','1','0','0'},
            {'1','1','0','0'},
            {'0','0','1','0'},
            {'0','0','0','1'}
        };

        int result = count_islands(grid);
        std::cout << result << std::endl;

        assert(result == 3);
    }

    return 0;
}