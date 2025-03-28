class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int rowCount = grid.size(), colCount = grid[0].size();
            vector<int> result(queries.size(), 0);
            vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
            vector<pair<int, int>> sortedQueries;
            for (int index = 0; index < queries.size(); index++) {
                sortedQueries.push_back({queries[index], index});
            }
            sort(sortedQueries.begin(), sortedQueries.end());
    
            priority_queue<pair<int, pair<int, int>>,
                           vector<pair<int, pair<int, int>>>, greater<>>
                minHeap;
            vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
            int totalPoints = 0;
            minHeap.push({grid[0][0], {0, 0}});
            visited[0][0] = true;
    
            for (auto [queryValue, queryIndex] : sortedQueries) {
                while (!minHeap.empty() && minHeap.top().first < queryValue) {
                    auto [cellValue, position] = minHeap.top();
                    minHeap.pop();
                    int currentRow = position.first, currentCol = position.second;
                    totalPoints++;
    
                    for (auto [rowOffset, colOffset] : DIRECTIONS) {
                        int newRow = currentRow + rowOffset,
                            newCol = currentCol + colOffset;
    
                        if (newRow >= 0 && newCol >= 0 && newRow < rowCount &&
                            newCol < colCount && !visited[newRow][newCol]) {
                            minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
                result[queryIndex] = totalPoints;
            }
            return result;
        }
    };