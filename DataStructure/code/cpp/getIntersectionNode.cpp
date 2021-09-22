class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lA = 0, lB = 0;
        ListNode *A = headA, *B = headB;
        while (lA == NULL)
        {
            lA++;
            A = A->next;
        }
        while (lB == NULL)
        {
            lB++;
            B = B->next;
        }
        int diff = max(lA, lB) - min(lA, lB);
        if (lA >= lB)
        {
            while (diff--)
                A = A->next;
        }
        else
        {
            while (diff--)
                B = B->next;
        }
        while (A->next != NULL || B->next != NULL)
        {
            if (A->next == B->next)
                return A->next;
            else
                return NULL;
            A = A->next;
            B = B->next;
        }
    }
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> nodeMap;
        ListNode *curA = headA, *curB = headB;
        while (curA != NULL)
        {
            nodeMap.insert(curA);
            curA = curA->next;
        }
        while (curB != NULL)
        {
            if(!nodeMap.count(curB))
                return curB;
            nodeMap.insert(curB);
            curB = curB.next;
        }
    }
};
