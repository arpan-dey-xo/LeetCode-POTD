class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int left = 0, right = nums.size();
            int result = 1;
    
            while (left <= right) {
                int length = left + (right - left) / 2;
                if (canFormNiceSubarray(length, nums)) {
                    result = length;
                    left = length + 1;
                } else {
                    right = length - 1;
                }
            }
            return result;
        }
    
    private:
        bool canFormNiceSubarray(int length, vector<int>& nums) {
            if (length <= 1) return true;
    
            for (int start = 0; start <= nums.size() - length; ++start) {
                int bitMask = 0;
                bool isNice = true;
    
                for (int pos = start; pos < start + length; ++pos) {
                    if ((bitMask & nums[pos]) != 0) {
                        isNice = false;
                        break;
                    }
                    bitMask |= nums[pos];
                }
    
                if (isNice)
                    return true;
            }
            return false;
        }
    };