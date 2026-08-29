class Solution {
public:
    int climbStairs(int n) {
        int first=1;
        int second=2;
        if(n==1) return first;
        if(n==2) return second;
        int stair;
        for(int i=3;i<=n;i++){
            stair =first+second;
            first=second;
            second=stair;
        }
        return stair;
    }
};