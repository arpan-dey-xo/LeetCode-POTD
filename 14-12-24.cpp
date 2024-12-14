class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        deque<int> maxQ, minQ;
        int left = 0;
        long long count = 0;

        for (int right = 0; right < nums.size(); right++) {
            while (!maxQ.empty() && nums[maxQ.back()] < nums[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(right);

            while (!minQ.empty() && nums[minQ.back()] > nums[right]) {
                minQ.pop_back();
            }
            minQ.push_back(right);

            while (!maxQ.empty() && !minQ.empty() &&
                   nums[maxQ.front()] - nums[minQ.front()] > 2) {
                if (maxQ.front() < minQ.front()) {
                    left = maxQ.front() + 1;
                    maxQ.pop_front();
                }
                else {
                    left = minQ.front() + 1;
                    minQ.pop_front();
                }
            }
            count += right - left + 1;
        }
        return count;
    }
};