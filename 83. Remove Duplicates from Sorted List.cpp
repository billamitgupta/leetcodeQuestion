class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* forward=NULL;
         ListNode* curr=head;
         if(curr==NULL) return NULL;
        while(curr->next!=NULL)
        {
            forward=curr->next;
            if(curr->val==forward->val)
            {
                forward=forward->next;
                curr->next=forward;
            }else{
                curr=forward;
                forward=forward->next;

            }
        }

        return head;
        
    }
};