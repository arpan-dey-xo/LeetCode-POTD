class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyNumbersSet; 
        uglyNumbersSet.insert(1);  

        long currentUgly = 1;
        for (int i = 0; i < n; i++) {
            currentUgly =
                *uglyNumbersSet
                     .begin(); 
            uglyNumbersSet.erase(
                uglyNumbersSet.begin()); 

            uglyNumbersSet.insert(currentUgly * 2);
            uglyNumbersSet.insert(currentUgly * 3);
            uglyNumbersSet.insert(currentUgly * 5);
        }

        return static_cast<int>(currentUgly);  
    }
};