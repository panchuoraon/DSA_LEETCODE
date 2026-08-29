class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s1;
        unordered_set<int> ans;

        // Store nums1 elements
        for (int x : nums1) {
            s1.insert(x);
        }

        // Check nums2 elements
        for (int x : nums2) {

            if (s1.count(x)) {
                ans.insert(x);
            }
        }

        // Convert set to vector
        return vector<int>(ans.begin(), ans.end());
    }
};