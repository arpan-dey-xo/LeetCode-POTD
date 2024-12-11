class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxBeauty = 0;

        for (int i = 0; i < nums.size(); i++) {
            int upperBound = findUpperBound(nums, nums[i] + 2 * k);
            maxBeauty = max(maxBeauty, upperBound - i + 1);
        }
        return maxBeauty;
    }

private:
    int findUpperBound(vector<int>& arr, int val) {
        int low = 0, high = arr.size() - 1, result = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= val) {
                result = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return result;
    }
};