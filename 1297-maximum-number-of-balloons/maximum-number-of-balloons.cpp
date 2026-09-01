class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};

        // Count frequency of every character
        for (char ch : text) {
            freq[ch - 'a']++;
        }

        // l and o are required twice
        freq['l' - 'a'] /= 2;
        freq['o' - 'a'] /= 2;

        // Find limiting character
        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'],
            freq['o' - 'a'],
            freq['n' - 'a']
        });
    }
};