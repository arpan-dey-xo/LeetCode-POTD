class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());

        int bannedIdx = 0, count = 0;
        
        for (int num = 1; num <= n && maxSum >= 0; num++) {
            if (bannedIdx < banned.size() && banned[bannedIdx] == num) {
                while (bannedIdx < banned.size() && banned[bannedIdx] == num) {
                    bannedIdx++;
                }
            }
            else {
                maxSum -= num;
                if (maxSum >= 0) {
                    count++;
                }
            }
        }
        return count;
    }
};