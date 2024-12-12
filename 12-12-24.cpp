class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n = gifts.size();

        vector<int> sortedGifts = gifts;
        sort(sortedGifts.begin(), sortedGifts.end());

        for (int i = 0; i < k; i++) {
            int maxElement = sortedGifts[n - 1];
            sortedGifts.pop_back();

            auto spotOfSqrt = upper_bound(sortedGifts.begin(),
                                          sortedGifts.end(), sqrt(maxElement));

            sortedGifts.emplace(spotOfSqrt, sqrt(maxElement));
        }
        
        long long int numberOfRemainingGifts =
            accumulate(sortedGifts.begin(), sortedGifts.end(), 0LL);

        return numberOfRemainingGifts;
    }
};