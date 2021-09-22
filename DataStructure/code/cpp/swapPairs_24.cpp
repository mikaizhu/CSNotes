#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* cur = dummyHead, *temp1, *temp2, *temp;
        while (cur->next != NULL && cur->next->next != NULL)
        {
            temp2 = cur->next->next;
            temp = temp2->next;
            temp1 = cur->next;
            cur->next = temp2;
            cur->next->next = temp1;
            temp1->next = temp;
            cur = temp1;
        }
        return dummyHead->next;
    }
};

int main()
{
}
