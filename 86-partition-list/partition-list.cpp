
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lo = new ListNode(100);
        ListNode* hi = new ListNode(200);

        ListNode* tl = lo;
        ListNode* th = hi;
        ListNode* temp = head;

        while (temp) {
            if (temp->val < x) {
                tl->next = temp;
                tl = tl->next;
            } else {
                th->next = temp;
                th = th->next;
            }

            temp = temp->next;
        }

        th->next = nullptr;
        tl->next = hi->next;

        return lo->next;
    }
};
