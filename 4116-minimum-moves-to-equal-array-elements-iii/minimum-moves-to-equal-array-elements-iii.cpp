
class Solution {
public:
    int minMoves(vector<int>& nums) {

        int mx = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i]);
            sum += nums[i];
        }

        return (mx * nums.size()) - sum;
    }
};
