/*
Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contains:

grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.
*/

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
    int n = grid[0].size();
    int valid_submatrices = 0;

    // Arrays to store cumulative counts of 'X' and 'Y' from (0, 0) to each (i, j)
    vector<vector<int>> countX(m, vector<int>(n, 0));
    vector<vector<int>> countY(m, vector<int>(n, 0));

    // Initialize counts for the first cell
    countX[0][0] = (grid[0][0] == 'X' ? 1 : 0);
    countY[0][0] = (grid[0][0] == 'Y' ? 1 : 0);

    // Fill counts for the first row
    for (int j = 1; j < n; ++j) {
        countX[0][j] = countX[0][j - 1] + (grid[0][j] == 'X' ? 1 : 0);
        countY[0][j] = countY[0][j - 1] + (grid[0][j] == 'Y' ? 1 : 0);
    }

    // Fill counts for the first column
    for (int i = 1; i < m; ++i) {
        countX[i][0] = countX[i - 1][0] + (grid[i][0] == 'X' ? 1 : 0);
        countY[i][0] = countY[i - 1][0] + (grid[i][0] == 'Y' ? 1 : 0);
    }

    // Fill counts for the rest of the grid
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            countX[i][j] = countX[i - 1][j] + countX[i][j - 1] - countX[i - 1][j - 1] + (grid[i][j] == 'X' ? 1 : 0);
            countY[i][j] = countY[i - 1][j] + countY[i][j - 1] - countY[i - 1][j - 1] + (grid[i][j] == 'Y' ? 1 : 0);
        }
    }

    // Check each submatrix starting from (0, 0) to (i, j)
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (countX[i][j] > 0 && countX[i][j] == countY[i][j]) {
                valid_submatrices++;
            }
        }
    }

    return valid_submatrices;
    }
};
