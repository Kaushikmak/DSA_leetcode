#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    count++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return count;

    }
private:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited){
        int rows = grid.size();
        int columns = grid[0].size();

        if( i >= rows || i < 0 || j >= columns || j < 0 ||
         visited[i][j] == true || grid[i][j] == '0' ){
            return;
         }

        visited[i][j] = true;

        dfs(grid, i+1, j , visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);

    }
};