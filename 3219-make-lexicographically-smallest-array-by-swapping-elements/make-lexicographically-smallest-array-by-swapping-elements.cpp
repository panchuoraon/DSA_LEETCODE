class Solution {
public:
    vector<int> lexicographicallySmallestArray(
        vector<int>& nums, int limit) {

        int n = nums.size();

        // Store indices
        vector<int> idx(n);

        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }

        // Sort indices according to nums values
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> ans(n);

        int i = 0;

        while (i < n) {

            int j = i + 1;

            // Find the current group
            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            // Collect indices of this group
            vector<int> positions(
                idx.begin() + i,
                idx.begin() + j
            );

            // Sort original positions
            sort(positions.begin(), positions.end());

            // Smallest values → smallest positions
            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};