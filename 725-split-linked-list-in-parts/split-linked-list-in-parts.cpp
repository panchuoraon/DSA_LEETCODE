class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;

        // Step 1: Count total nodes
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        int size = n / k;
        int extra = n % k;

        vector<ListNode*> ans(k, nullptr);
        curr = head;

        // Step 2: Split into k parts
        for (int i = 0; i < k; i++) {
            ans[i] = curr;

            int partSize = size;
            if (extra > 0) {
                partSize++;
                extra--;
            }

            // Move to the last node of this part
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            // Disconnect this part
            if (curr != nullptr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }

        return ans;
    }
};