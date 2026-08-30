class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {

        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;

        // Count words1
        for(string word : words1) {
            mp1[word]++;
        }

        // Count words2
        for(string word : words2) {
            mp2[word]++;
        }

        int ans = 0;

        // Check words from mp1
        for(auto [word, freq] : mp1) {

            if(freq == 1 && mp2[word] == 1) {
                ans++;
            }
        }

        return ans;
    }
};