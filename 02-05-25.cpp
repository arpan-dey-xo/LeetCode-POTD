class Solution {
    public:
        string pushDominoes(string S) {
            int N = S.size();
            vector<int> forces(N, 0);
    
            int force = 0;
            for (int i = 0; i < N; ++i) {
                if (S[i] == 'R') force = N;
                else if (S[i] == 'L') force = 0;
                else force = max(force - 1, 0);
                forces[i] += force;
            }
    
            force = 0;
            for (int i = N - 1; i >= 0; --i) {
                if (S[i] == 'L') force = N;
                else if (S[i] == 'R') force = 0;
                else force = max(force - 1, 0);
                forces[i] -= force;
            }
    
            string result;
            for (int f : forces) {
                if (f > 0) result += 'R';
                else if (f < 0) result += 'L';
                else result += '.';
            }
    
            return result;
        }
    };