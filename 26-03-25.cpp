class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> numsArray;
            int result = INT_MAX;
    
            for (int row = 0; row < grid.size(); row++) {
                for (int col = 0; col < grid[0].size(); col++) {
                    if (grid[row][col] % x != grid[0][0] % x) return -1;
                    numsArray.push_back(grid[row][col]);
                }
            }
    
            sort(numsArray.begin(), numsArray.end());
    
            int length = numsArray.size();
            vector<int> prefixSum(length, 0);
            vector<int> suffixSum(length, 0);
    
            for (int index = 1; index < length; index++) {
                prefixSum[index] = prefixSum[index - 1] + numsArray[index - 1];
            }
    
            for (int index = length - 2; index >= 0; index--) {
                suffixSum[index] = suffixSum[index + 1] + numsArray[index + 1];
            }
    
            for (int index = 0; index < length; index++) {
                int leftOperations =
                    (numsArray[index] * index - prefixSum[index]) / x;
    
                int rightOperations =
                    (suffixSum[index] - numsArray[index] * (length - index - 1)) /
                    x;
    
                result = min(result, leftOperations + rightOperations);
            }
    
            return result;
        }
    };