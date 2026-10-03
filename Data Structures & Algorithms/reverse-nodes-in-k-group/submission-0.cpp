class Solution {
    int length(ListNode* head) {
        int len=0;
        while(head) {
            head=head->next;
            len++;
        }

        return len;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* nextNode=curr->next;

        while(curr!=nullptr) {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        return prev;
    }

    ListNode* f(ListNode* head,int n,int &k) {
        if(!head || !head->next || n<k) return head;
        ListNode * end=head;
        int u=min(n,k)-1;
        while(u--) {
            end=end->next;
        }

        ListNode* newHead=end->next;
        end->next=nullptr;

        ListNode* revHead=reverse(head);
        head->next=f(newHead,n-k,k);
        return revHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int l=length(head);

        return f(head,l,k);
    }
};