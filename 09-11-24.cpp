#define ll long long

class Solution {
public:
    long long minEnd(int n, int x) {
        ll result = 0, bit;
        --n;

        vector<int> binaryX(64, 0);
        vector<int> binaryN(64, 0);

        ll longX = x;
        ll longN = n;

        for (int i = 0; i < 64; ++i) {
            bit = (longX >> i) & 1;
            binaryX[i] = bit;

            bit = (longN >> i) & 1;
            binaryN[i] = bit;
        }

        int posX = 0, posN = 0;

        while (posX < 63) {
            while (binaryX[posX] != 0 && posX < 63) {
                ++posX;
            }
            binaryX[posX] = binaryN[posN];
            ++posX;
            ++posN;
        }

        for (int i = 0; i < 64; ++i) {
            if (binaryX[i] == 1) {
                result += pow(2, i);
            }
        }

        return result;
    }
};