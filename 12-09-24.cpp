class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> isAllowed(26, false);

        for (int i = 0; i < allowed.length(); i++) {
            isAllowed[allowed[i] - 'a'] = true;
        }

        int consistentCount = 0;

        for (string& word : words) {
            bool isConsistent = true;

            for (int i = 0; i < word.length(); i++) {
                if (!isAllowed[word[i] - 'a']) {
                    isConsistent = false;
                    break;
                }
            }

            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};