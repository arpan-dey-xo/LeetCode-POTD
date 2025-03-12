class Solution {
    private:
        int lowerBound(vector<int> &nums) {
            int start = 0, end = nums.size() - 1;
            int index = nums.size();
    
            while (start <= end) {
                int mid = (start + end) / 2;
    
                if (nums[mid] < 0) {
                    start = mid + 1;
                } else if (nums[mid] >= 0) {
                    end = mid - 1;
                    index = mid;
                }
            }
    
            return index;
        }
    
        int upperBound(vector<int> &nums) {
            int start = 0, end = nums.size() - 1;
            int index = nums.size();
    
            while (start <= end) {
                int mid = (start + end) / 2;
    
                if (nums[mid] <= 0) {
                    start = mid + 1;
                } else if (nums[mid] > 0) {
                    end = mid - 1;
                    index = mid;
                }
            }
    
            return index;
        }
    
    public:
        int maximumCount(vector<int> &nums) {
            int positiveCount = nums.size() - upperBound(nums);
            int negativeCount = lowerBound(nums);
    
            return max(positiveCount, negativeCount);
        }
    };