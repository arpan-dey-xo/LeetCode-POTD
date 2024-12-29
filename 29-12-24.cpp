class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        vector<vector<int>> charFrequency(wordLength, vector<int>(26, 0));
        for (const string& word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFrequency[j][word[j] - 'a']++;
            }
        }

        vector<long> prevCount(targetLength + 1, 0);
        vector<long> currCount(targetLength + 1, 0);

        prevCount[0] = 1;

        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            currCount = prevCount;
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                int curPos = target[currTarget - 1] - 'a';
                currCount[currTarget] += (charFrequency[currWord - 1][curPos] *
                                          prevCount[currTarget - 1]) %
                                         MOD;
                currCount[currTarget] %= MOD;
            }
            prevCount = currCount;
        }

        return currCount[targetLength];
    }
};