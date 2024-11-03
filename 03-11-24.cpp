class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) return false;
        string doubledString = s + s;
        return doubledString.find(goal) < doubledString.length();
    }
};