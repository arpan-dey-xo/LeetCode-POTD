class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = *max_element(nums.begin(), nums.end());
        
        vector<int> sieve(maxElement + 1, 1);
        sieve[1] = 0;
        for (int i = 2; i <= sqrt(maxElement + 1); i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = 0;
                }
            }
        }

        int currValue = 1;
        int i = 0;
        while (i < nums.size()) {
            int difference = nums[i] - currValue;

            if (difference < 0) {
                return 0;
            }

            if (sieve[difference] == 1 or difference == 0) {
                i++;
                currValue++;
            } else {
                currValue++;
            }
        }
        return 1;
    }
};