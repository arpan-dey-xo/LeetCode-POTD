class Solution {
public:
    long long minimumSteps(string s) {
        long long totalSwaps = 0;
        int blackBallCount = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                totalSwaps += (long long)blackBallCount;
            } else {
                blackBallCount++;
            }
        }

        return totalSwaps;
    }
};