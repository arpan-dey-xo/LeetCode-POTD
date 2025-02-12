class Solution {
    private:
        int calculateDigitSum(int num) {
            int digitSum = 0;
            while (num > 0) {
                digitSum += num % 10;
                num /= 10;
            }
            return digitSum;
        }
    
    public:
        int maximumSum(vector<int>& nums) {
            vector<priority_queue<int, vector<int>, greater<int>>> digitSumGroups(
                82);
    
            int maxPairSum = -1;
    
            for (int number : nums) {
                int digitSum = calculateDigitSum(number);
                digitSumGroups[digitSum].push(number);
                if (digitSumGroups[digitSum].size() > 2) {
                    digitSumGroups[digitSum].pop();
                }
            }
            for (auto& minHeap : digitSumGroups) {
                if (minHeap.size() == 2) {
                    int first = minHeap.top();
                    minHeap.pop();
                    int second = minHeap.top();
                    maxPairSum = max(maxPairSum, first + second);
                }
            }
    
            return maxPairSum;
        }
    };