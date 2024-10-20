class Solution {
public:
    bool parseBoolExpr(string expression) {
        while (expression.length() > 1) {
            int start = expression.find_last_of("!&|");
            int end = expression.find(')', start);
            string subExpr = expression.substr(start, end - start + 1);
            char result = evaluateSubExpr(subExpr);
            expression.replace(start, end - start + 1, 1, result);
        }
        return expression[0] == 't';
    }

private:
    char evaluateSubExpr(const string& subExpr) {
        char op = subExpr[0];
        string values = subExpr.substr(2, subExpr.length() - 3);

        if (op == '!') return values[0] == 't' ? 'f' : 't';
        if (op == '&') return values.find('f') != string::npos ? 'f' : 't';
        if (op == '|') return values.find('t') != string::npos ? 't' : 'f';

        return 'f';
    }
};