
class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> firstIndex;

        firstIndex[0] = -1;

        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) {
                prefixSum--;
            } else {
                prefixSum++;
            }

            if (firstIndex.count(prefixSum)) {

                int len = i - firstIndex[prefixSum];

                maxLen = max(maxLen, len);

            } else {
                firstIndex[prefixSum] = i;
            }
        }

        return maxLen;
    }
};
