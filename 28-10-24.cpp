class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int longestStreak = 0;

        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());

        for (int startNumber : nums) {
            int currentStreak = 0;
            long long current = startNumber;

            while (uniqueNumbers.find((int)current) != uniqueNumbers.end()) {
                currentStreak++;

                if (current * current > 1e5) break;

                current *= current;
            }

            longestStreak = max(longestStreak, currentStreak);
        }

        return longestStreak < 2 ? -1 : longestStreak;
    }
};