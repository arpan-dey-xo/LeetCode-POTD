class Solution {
public:
    int bisectRight(vector<vector<int>>& events, int target) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (events[mid][0] <= target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        
        sort(events.begin(), events.end());

        for (int curIndex = n - 1; curIndex >= 0; --curIndex) {
            for (int count = 1; count <= k; ++count) {
                int nextIndex = bisectRight(events, events[curIndex][1]);
                dp[count][curIndex] = max(
                    dp[count][curIndex + 1], 
                    events[curIndex][2] + dp[count - 1][nextIndex]
                );
            }
        }

        return dp[k][0];
    }
};