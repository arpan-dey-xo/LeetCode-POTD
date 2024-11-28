class Solution {
private:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        minObstacles[0][0] = 0;

        deque<array<int, 3>> deque;
        deque.push_back({0, 0, 0});

        while (!deque.empty()) {
            auto current = deque.front();
            deque.pop_front();
            int obstacles = current[0], row = current[1], col = current[2];

            for (auto& dir : directions) {
                int newRow = row + dir[0], newCol = col + dir[1];

                if (isValid(grid, newRow, newCol) &&
                    minObstacles[newRow][newCol] == INT_MAX) {
                    if (grid[newRow][newCol] == 1) {
                        minObstacles[newRow][newCol] = obstacles + 1;
                        deque.push_back({obstacles + 1, newRow, newCol});
                    }
                    else {
                        minObstacles[newRow][newCol] = obstacles;
                        deque.push_front({obstacles, newRow, newCol});
                    }
                }
            }
        }

        return minObstacles[m - 1][n - 1];
    }

private:
    bool isValid(vector<vector<int>>& grid, int row, int col) {
        return row >= 0 && col >= 0 && row < grid.size() &&
               col < grid[0].size();
    }
};