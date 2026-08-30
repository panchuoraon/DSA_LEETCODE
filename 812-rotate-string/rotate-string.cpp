class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.length() != goal.length())
            return false;

        int n = s.length();

        for (int i = 0; i < n; i++) {

            if (s == goal)
                return true;

            // Move first character to the end
            char first = s[0];

            s.erase(s.begin());

            s.push_back(first);
        }

        return false;
    }
};