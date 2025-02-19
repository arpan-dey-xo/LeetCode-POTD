class Solution {
    public:
        string getHappyString(int n, int k) {
            stack<string> stringsStack;
            int indexInSortedList = 0;
            stringsStack.push("");
    
            while (stringsStack.size() > 0) {
                string currentString = stringsStack.top();
                stringsStack.pop();
    
                if (currentString.size() == n) {
                    indexInSortedList++;
                    if (indexInSortedList == k) {
                        return currentString;
                    }
                    continue;
                }
    
                for (char currentChar = 'c'; currentChar >= 'a'; currentChar--) {
                    if (currentString.size() > 0 &&
                        currentString.back() == currentChar)
                        continue;
                    stringsStack.push(currentString + currentChar);
                }
            }
            return "";
        }
    };