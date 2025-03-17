class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> frequency;
            for (int num : nums) {
                frequency[num]++;
            }
    
            for (auto& entry : frequency) {
                if (entry.second % 2 != 0) {
                    return false;
                }
            }
    
            return true;
        }
    };