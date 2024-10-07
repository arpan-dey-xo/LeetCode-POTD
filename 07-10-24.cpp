class Solution {
public:
    int minLength(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            if (stack.empty()) {
                stack.push(currentChar);
                continue;
            }

            if (currentChar == 'B' && stack.top() == 'A') {
                stack.pop();
            }
            else if (currentChar == 'D' && stack.top() == 'C') {
                stack.pop();
            }
            else {
                stack.push(currentChar);
            }
        }

        return stack.size();
    }
};