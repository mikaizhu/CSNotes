class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int la = 0, lb = 0;
        while (curA != NULL)
        {
            la++;
            curA = curA->next;
        }
        while (curB != NULL)
        {
            lb++;
            curB = curB->next;
        }
        int diff = max(la, lb) - min(la, lb);
        if (la > lb)
        {
            curA = curA->next;
            la--;
        }
        else if (la < lb)
        {
            curB = curB->next;
            lb--;
        }
        while (curA != curB)
        {
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};
