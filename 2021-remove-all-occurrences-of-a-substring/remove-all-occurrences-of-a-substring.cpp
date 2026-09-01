class Solution {
public:
    string removeOccurrences(string s, string part) {

        int index;

        while ((index = s.find(part)) != string::npos) {

            s.erase(index, part.length());
        }

        return s;
    }
};