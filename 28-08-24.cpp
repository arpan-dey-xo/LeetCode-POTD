class Solution {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    bool isCellLand(int x, int y, vector<vector<int>>& grid) {
        return grid[x][y] == 1;
    }

public:
    bool isSubIsland(int x, int y, vector<vector<int>>& grid1,
                     vector<vector<int>>& grid2,
                     vector<vector<bool>>& visited) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        int isSubIsland = true;

        queue<pair<int, int>> pendingCells;
        pendingCells.push({x, y});
        visited[x][y] = true;

        while (!pendingCells.empty()) {
            int currX = pendingCells.front().first;
            int currY = pendingCells.front().second;
            pendingCells.pop();

            if (!isCellLand(currX, currY, grid1)) {
                isSubIsland = false;
            }

            for (auto& direction : directions) {
                int nextX = currX + direction[0];
                int nextY = currY + direction[1];
                if (nextX >= 0 && nextY >= 0 && nextX < totalRows &&
                    nextY < totalCols && !visited[nextX][nextY] &&
                    isCellLand(nextX, nextY, grid2)) {
                    pendingCells.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }

        return isSubIsland;
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int totalRows = grid2.size();
        int totalCols = grid2[0].size();

        vector<vector<bool>> visited(totalRows, vector<bool>(totalCols, false));
        int subIslandCounts = 0;
        for (int x = 0; x < totalRows; ++x) {
            for (int y = 0; y < totalCols; ++y) {
                if (!visited[x][y] && isCellLand(x, y, grid2) &&
                    isSubIsland(x, y, grid1, grid2, visited)) {
                    subIslandCounts += 1;
                }
            }
        }
        return subIslandCounts;
    }
};