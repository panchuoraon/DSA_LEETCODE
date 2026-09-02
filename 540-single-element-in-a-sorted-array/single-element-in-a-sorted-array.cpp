class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Ensure mid is an even index
            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] == nums[mid + 1]) {
                // Correct pairing: single element is on the right
                low = mid + 2;
            } else {
                // Pairing is broken: single element is at mid or left
                high = mid;
            }
        }

        return nums[low];
    }
};