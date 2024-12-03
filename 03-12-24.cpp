class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        result.reserve(s.size() + spaces.size());

        int spaceIndex = 0;
        for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex) {
            if (spaceIndex < spaces.size() &&
                stringIndex == spaces[spaceIndex]) {
                result += ' ';
                ++spaceIndex;
            }
            result += s[stringIndex];
        }

        return result;
    }
};