
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Copy the original list
        ListNode dummy(0);
        ListNode* tail = &dummy;
        ListNode* temp = head;

        while (temp != nullptr) {
            tail->next = new ListNode(temp->val);
            tail = tail->next;
            temp = temp->next;
        }

        ListNode* original = dummy.next;

        // Reverse the original linked list
        ListNode* prev = nullptr;
        temp = head;

        while (temp != nullptr) {
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }

        // Compare reversed list with the copy
        ListNode* rev = prev;

        while (original != nullptr && rev != nullptr) {
            if (original->val != rev->val) {
                return false;
            }

            original = original->next;
            rev = rev->next;
        }

        return true;
    }
};
