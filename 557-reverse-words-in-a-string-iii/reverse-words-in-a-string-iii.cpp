class Solution {
public:
    string reverseWords(string s) {

        int n = s.size();
        int l = 0;

        for(int i = 0; i < n; i++) {

            // Found the end of a word
            if(s[i] == ' ' || i == n - 1) {

                int r;

                if(s[i] == ' ')
                    r = i - 1;
                else
                    r = i;

                // Reverse current word
                while(l < r) {
                    swap(s[l], s[r]);
                    l++;
                    r--;
                }

                // Start of next word
                l = i + 1;
            }
        }

        return s;
    }
};