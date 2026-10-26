class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* nextNode=head;

        while(curr) {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        return prev;
    }
};
