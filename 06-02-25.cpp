class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();

        vector<int> pairProducts;

        int totalNumberOfTuples = 0;

        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                 secondIndex++) {
                pairProducts.push_back(nums[firstIndex] * nums[secondIndex]);
            }
        }

        sort(pairProducts.begin(), pairProducts.end());

        int lastProductSeen = -1;
        int sameProductCount = 0;

        for (int productIndex = 0; productIndex < pairProducts.size();
             productIndex++) {
            if (pairProducts[productIndex] == lastProductSeen) {
                sameProductCount++;
            }
            else {
                int pairsOfEqualProduct =
                    (sameProductCount - 1) * sameProductCount / 2;

                totalNumberOfTuples += 8 * pairsOfEqualProduct;

                lastProductSeen = pairProducts[productIndex];
                sameProductCount = 1;
            }
        }

        int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
        totalNumberOfTuples += 8 * pairsOfEqualProduct;

        return totalNumberOfTuples;
    }
};