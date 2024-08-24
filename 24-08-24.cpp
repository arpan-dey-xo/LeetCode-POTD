class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        int i = len % 2 == 0 ? len / 2 - 1 : len / 2;
        long firstHalf = stol(n.substr(0, i + 1));
        vector<long> possibilities;
        possibilities.push_back(halfToPalindrome(firstHalf, len % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf + 1, len % 2 == 0));
        possibilities.push_back(halfToPalindrome(firstHalf - 1, len % 2 == 0));
        possibilities.push_back((long)pow(10, len - 1) - 1);
        possibilities.push_back((long)pow(10, len) + 1);

        long diff = LONG_MAX, res = 0, nl = stol(n);
        for (auto cand : possibilities) {
            if (cand == nl) continue;
            if (abs(cand - nl) < diff) {
                diff = abs(cand - nl);
                res = cand;
            } else if (abs(cand - nl) == diff) {
                res = min(res, cand);
            }
        }

        return to_string(res);
    }

private:
    long halfToPalindrome(long left, bool even) {
        long res = left;
        if (!even) left = left / 10;
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        return res;
    }
};