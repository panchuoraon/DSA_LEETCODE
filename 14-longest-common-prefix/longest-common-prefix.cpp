class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        string s="";
       for(int i=0;i<first.size()&&i<last.size();i++){
        if(first[i]==last[i]) s+=first[i];
        else break;
       }
        
        return s;
    }
};