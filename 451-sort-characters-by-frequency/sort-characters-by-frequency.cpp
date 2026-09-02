class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<int, char>> characters;

        for (auto& entry : freq) {
            characters.push_back({entry.second, entry.first});
        }

        sort(characters.rbegin(), characters.rend());

        string ans;

        for (auto& entry : characters) {
            int frequency = entry.first;
            char ch = entry.second;

            ans.append(frequency, ch);
        }

        return ans;
    }
};