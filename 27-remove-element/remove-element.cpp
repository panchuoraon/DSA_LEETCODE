class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        vector<int> temp;

        for (int x : nums) {
            if (x != val) {
                temp.push_back(x);
            }
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }

        return temp.size();
    }
};