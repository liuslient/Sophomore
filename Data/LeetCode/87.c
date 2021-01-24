struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *h1=head;
    while(h1!=NULL&&h1->next!=NULL)
    {
        if(h1->val==h1->next->val)
        {
            h1->next=h1->next->next;
        }
        else
        {
            h1=h1->next;
        }
    }
    return head;
}
