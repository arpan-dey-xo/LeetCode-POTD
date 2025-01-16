class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();

        unordered_map<int, long> freq;

        for (int num : nums1) {
            freq[num] += len2;
        }

        for (int num : nums2) {
            freq[num] += len1;
        }

        int ans = 0;
        for (auto& [num, count] : freq) {
            if (count % 2 == 1) {
                ans ^= num;
            }
        }

        return ans;
    }
};