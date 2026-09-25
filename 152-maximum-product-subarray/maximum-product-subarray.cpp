class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxend=nums[0];
        int minend=nums[0];
        int maxp=nums[0];
        for(int i=1;i<n;i++){
          int a=nums[i];
          int b=minend*nums[i];
          int c=maxend*nums[i];
          maxend=max(a,max(b,c));
          minend=min(a,min(b,c));
          maxp=max(maxp,max(minend,maxend));
        }
        return maxp;
    }
};