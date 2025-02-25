class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
            const int MOD = 1e9 + 7;
            int n = arr.size();
            for (auto& num : arr) {
                num %= 2;
            }
    
            vector<int> dpEven(n), dpOdd(n);
    
            if (arr[n - 1] == 0) {
                dpEven[n - 1] = 1;
            }
            else {
                dpOdd[n - 1] = 1;
            }
    
            for (int num = n - 2; num >= 0; num--) {
                if (arr[num] == 1) {
                    dpOdd[num] = (1 + dpEven[num + 1]) % MOD;
                    dpEven[num] = dpOdd[num + 1];
                }
                else {
                    dpEven[num] = (1 + dpEven[num + 1]) % MOD;
                    dpOdd[num] = dpOdd[num + 1];
                }
            }
    
            int count = 0;
            for (auto oddCount : dpOdd) {
                count += oddCount;
                count %= MOD;
            }
    
            return count;
        }
    };