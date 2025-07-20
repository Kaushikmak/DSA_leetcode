#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        const unsigned int m = board.size();
        const unsigned int n = board[0].size();
        //You should only run DFS from the border 'O's,
        //because those are the only ones that should not be flipped.
        //Any 'O' not connected to the border can be safely changed to 'X'.
        // that's why it's wrong
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (board[i][j] == 'O') {
        //             dfs(board, i, j);
        //         }
        //     }
        // }

        // use custom marker to mark border
        // then make b/w x to o
        for (int i=0; i<m; i++) {
            dfs(board,i,0);
            dfs(board,i,n-1);
        }
        for (int j=0; j<n; j++) {
            dfs(board,0,j);
            dfs(board,m-1,j);
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }

private:
    void dfs(vector<vector<char> > &grid, int i, int j) {
        const unsigned int rows = grid.size();
        const unsigned int columns = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= columns || grid[i][j] != 'O') {
            return;
        }

        grid[i][j] = '*';

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
