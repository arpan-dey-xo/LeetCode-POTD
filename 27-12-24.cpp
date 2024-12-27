class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();

        int maxLeftScore = values[0];

        int maxScore = 0;

        for (int i = 1; i < n; i++) {
            int currentRightScore = values[i] - i;
            maxScore = max(maxScore, maxLeftScore + currentRightScore);

            int currentLeftScore = values[i] + i;
            maxLeftScore = max(maxLeftScore, currentLeftScore);
        }

        return maxScore;
    }
};