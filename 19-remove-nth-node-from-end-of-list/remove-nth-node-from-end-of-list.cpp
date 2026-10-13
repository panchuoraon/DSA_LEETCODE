

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        if(n==len){
            head=head->next;
            return head;
        }
        int m=len-n+1;
        int idx=m-1;
        ListNode* mid=head;
        for(int i=1;i<=idx-1;i++){
            mid=mid->next;
        }
        mid->next=mid->next->next;
        return head;
    }
};