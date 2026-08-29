class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;

        double multiple2 = 1;

        while (multiple2 < n) {
            multiple2 *= 2;
        }

        return multiple2 == n;
    }
};