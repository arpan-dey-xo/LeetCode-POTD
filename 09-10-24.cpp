class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;

        int minAddsRequired = 0;
        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else {
                openBrackets > 0 ? openBrackets-- : minAddsRequired++;
            }
        }
        
        return minAddsRequired + openBrackets;
    }
};