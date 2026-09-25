class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int MaxSum = nums[0];
        int MinSum=nums[0];
        int maxxSum = nums[0];
        int minnSum=nums[0];
        int res=abs(nums[0]);

        for (int i = 1; i < nums.size(); i++) {

            MaxSum = max(nums[i], MaxSum + nums[i]);
            MinSum=min(nums[i],MinSum + nums[i]);
            maxxSum = max(maxxSum, MaxSum);
            minnSum=min(minnSum,MinSum);
            res=max(maxxSum,abs(minnSum));
        }

        return res;
    }
};