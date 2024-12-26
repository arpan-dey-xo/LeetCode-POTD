class Solution {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> memo(
            nums.size(),
            vector<int>(2 * totalSum + 1, numeric_limits<int>::min()));
        return calculateWays(nums, 0, 0, target, memo);
    }

    int calculateWays(vector<int>& nums, int currentIndex, int currentSum,
                      int target, vector<vector<int>>& memo) {
        if (currentIndex == nums.size()) {
            if (currentSum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        else {
            if (memo[currentIndex][currentSum + totalSum] !=
                numeric_limits<int>::min()) {
                return memo[currentIndex][currentSum + totalSum];
            }
            // Calculate ways by adding the current number
            int add =
                calculateWays(nums, currentIndex + 1,
                              currentSum + nums[currentIndex], target, memo);

            int subtract =
                calculateWays(nums, currentIndex + 1,
                              currentSum - nums[currentIndex], target, memo);

            memo[currentIndex][currentSum + totalSum] = add + subtract;

            return memo[currentIndex][currentSum + totalSum];
        }
    }
};