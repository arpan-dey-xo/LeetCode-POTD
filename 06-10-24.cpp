class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        stringstream ss1(s1), ss2(s2);
        string word;
        vector<string> s1Words, s2Words;
        while (ss1 >> word) s1Words.push_back(word);
        while (ss2 >> word) s2Words.push_back(word);

        int start = 0, ends1 = s1Words.size() - 1, ends2 = s2Words.size() - 1;

        if (s1Words.size() > s2Words.size()) return areSentencesSimilar(s2, s1);

        while (start < s1Words.size() && s1Words[start] == s2Words[start])
            ++start;

        while (ends1 >= 0 && s1Words[ends1] == s2Words[ends2]) {
            --ends1;
            --ends2;
        }

        return ends1 < start;
    }
};