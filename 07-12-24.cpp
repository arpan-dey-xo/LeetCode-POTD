class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = 0;

        for (auto num : nums) {
            right = max(right, num);
        }
        
        while (left < right) {
            int middle = (left + right) / 2;

            if (isPossible(middle, nums, maxOperations)) {
                right = middle;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }

private:
    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOperations) {
        int totalOperations = 0;

        for (int num : nums) {
            int operations = ceil(num / (double)maxBallsInBag) - 1;
            totalOperations += operations;

            if (totalOperations > maxOperations) return false;
        }
        return true;
    }
};