class Solution {
    ListNode* reverse(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        ListNode* nextNode=nullptr;

        while(curr) {
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }

        return prev;
    }
    ListNode* findMiddle(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* middle=slow->next;
        slow->next=nullptr;
        return middle;
    }
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* mid=findMiddle(head);

        mid=reverse(mid);
        ListNode* dummy=new ListNode(-1);
        ListNode* ptr=dummy;

        ListNode* p=head;
        ListNode*q=mid;
        bool flag=true;

        while(p && q) {
            if(flag) {
                ptr->next=p;
                p=p->next;
            }
            else {
                ptr->next=q;
                q=q->next;
            }
            ptr=ptr->next;
            flag=!flag;
        }
        if(p) ptr->next=p;
        if(q) ptr->next=q;

        return;
    }
};
