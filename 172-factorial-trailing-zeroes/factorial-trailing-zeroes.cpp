class Solution {
public:
    int trailingZeroes(int n) {
        int count2=0;
        // while(n>=2){
        //     count2+=n/2;
        //     n=n/2;
        // }
        int count5=0;
        while(n>=5){
            count5+=n/5;
            n=n/5;
        }
         return count5;
    }
};