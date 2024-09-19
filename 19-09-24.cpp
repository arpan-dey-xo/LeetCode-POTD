class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        if (expression.length() == 0) return results;

        if (expression.length() == 1) {
            results.push_back(stoi(expression));
            return results;
        }

        if (expression.length() == 2 && isdigit(expression[0])) {
            results.push_back(stoi(expression));
            return results;
        }

        for (int i = 0; i < expression.length(); i++) {
            char currentChar = expression[i];

            if (isdigit(currentChar)) continue;

            vector<int> leftResults =
                diffWaysToCompute(expression.substr(0, i));
            vector<int> rightResults =
                diffWaysToCompute(expression.substr(i + 1));

            for (int leftValue : leftResults) {
                for (int rightValue : rightResults) {
                    int computedResult = 0;

                    switch (currentChar) {
                        case '+':
                            computedResult = leftValue + rightValue;
                            break;
                        case '-':
                            computedResult = leftValue - rightValue;
                            break;
                        case '*':
                            computedResult = leftValue * rightValue;
                            break;
                    }

                    results.push_back(computedResult);
                }
            }
        }

        return results;
    }
};