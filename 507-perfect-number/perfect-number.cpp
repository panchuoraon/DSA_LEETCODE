class Solution {
public:
    bool checkPerfectNumber(int num) {
        int fsum=1;
        if(num==1) return false;
        for(int i=2;i<num;i++){
            if(num%i==0) fsum+=i;
        }
        if(fsum==num) return true;
        else return false;
    }
};