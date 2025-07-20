#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int> > &grid) {
        const unsigned int m = grid.size();
        const unsigned int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }
        for (int i=0; i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]==1) {
                    count++;
                    grid[i][j] = 0;
                }else if (grid[i][j]==-1) {
                    grid[i][j] = 1;
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<int> > &grid, int i, int j) {
        const unsigned int rows = grid.size();
        const unsigned int columns = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= columns || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = -1;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};
