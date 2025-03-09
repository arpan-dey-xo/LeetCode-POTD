class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            for (int i = 0; i < k - 1; i++) {
                colors.push_back(colors[i]);
            }
    
            int length = colors.size();
            int result = 0;
            int left = 0;
            int right = 1;
    
            while (right < length) {
                if (colors[right] == colors[right - 1]) {
                    left = right;
                    right++;
                    continue;
                }
    
                right++;
    
                if (right - left < k) continue;
    
                result++;
                left++;
            }
    
            return result;
        }
    };