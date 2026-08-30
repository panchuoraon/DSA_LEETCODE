class Solution {
public:
    int firstUniqChar(string s) {
       int v[26] = {0};
       for(char i : s){
        v[i-'a']++;
       }

       for(int i=0;i<s.length();i++){
        if(v[s[i]- 'a']  == 1) {
            return i;
            break;
        }
       }
       return -1;



    }
};