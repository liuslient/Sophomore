struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *l3,*p;
    if(l1 == NULL ) return l2;
    if(l2 == NULL ) return l1;
    if(l1->val<=l2->val)
    {
        l3=l1;
        l1=l1->next;
    }
    else
    {
        l3=l2;
        l2=l2->next;
    }
    p=l3;
    while(l1&&l2)
    {
        if(l1->val <= l2->val)
        {
            l3->next=l1;
            l1=l1->next;
        }
        else
        {
            l3->next=l2;
            l2=l2->next;
        }
        l3=l3->next;
    }
    if(l1)
    {
        l3->next=l1;
    }
    else
    {
        l3->next=l2;
    }
    return p;
}
