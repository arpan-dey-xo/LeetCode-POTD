class Solution {
    public:
        bool check(string &sequence, string &pattern) {
            for (int patternIndex = 0; patternIndex < pattern.size();
                 patternIndex++) {
                if (pattern[patternIndex] == 'I') {
                    if (sequence[patternIndex] > sequence[patternIndex + 1])
                        return false;
                }
                else {
                    if (sequence[patternIndex] < sequence[patternIndex + 1])
                        return false;
                }
            }
            return true;
        }
    
        string smallestNumber(string pattern) {
            int patternLength = pattern.size();
            string sequence = "";
    
            for (int number = 1; number <= 1 + patternLength; number++) {
                sequence.push_back(number + '0');
            }
    
            string permutation = sequence;
    
            while (!check(permutation, pattern)) {
                next_permutation(permutation.begin(), permutation.end());
            }
    
            return permutation;
        }
    };