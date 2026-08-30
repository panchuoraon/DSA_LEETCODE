class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans="";
        vector<string> str;
        while(ss>>word){
         str.push_back(word);
        }
        for(int i=str.size()-1;i>=0;i--){
            ans+=str[i];
            ans+=' ';
        }
        ans.pop_back();
        return ans;
        
    }
};