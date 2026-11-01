
class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        int groupSize = 1;

        while (prev->next != NULL) {

            // Find actual group length
            ListNode* curr = prev->next;
            int count = 0;

            while (curr != NULL && count < groupSize) {
                curr = curr->next;
                count++;
            }

            // Reverse only if actual length is even
            if (count % 2 == 0) {

                ListNode* groupStart = prev->next;
                ListNode* nextGroup = curr;

                ListNode* p = NULL;
                ListNode* c = groupStart;

                // Reverse current group
                for (int i = 0; i < count; i++) {

                    ListNode* nextNode = c->next;

                    c->next = p;
                    p = c;
                    c = nextNode;
                }

                // Connect reversed group
                prev->next = p;
                groupStart->next = nextGroup;

                // Move prev to the end of reversed group
                prev = groupStart;
            }
            else {

                // Skip odd-length group
                for (int i = 0; i < count; i++) {
                    prev = prev->next;
                }
            }

            groupSize++;
        }

        return dummy.next;
    }
};
