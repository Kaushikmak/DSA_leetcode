#include <bits/stdc++.h>
#include  <vector>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> > &grid) {
        const unsigned int m = grid.size();
        const unsigned int n = grid[0].size();
        int maxarea = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid,i,j,area);
                    maxarea = max(maxarea,area);
                }
            }
        }
        return maxarea;
    }

private:
    void dfs(vector<vector<int> > &grid, int i, int j, int &area) {
        const unsigned int rows = grid.size();
        const unsigned int columns = grid[0].size();
        if (i < 0 || i >= rows || j < 0 || j >= columns || grid[i][j] == 0) {
            return;
        }
        area++;
        grid[i][j] = 0;
        dfs(grid, i + 1, j, area);
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j + 1, area);
        dfs(grid, i, j - 1, area);
    }
};
