#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur(NULL, head);
        while (cur->next != nullptr)
        {
            if (cur->next->value == val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};

int main()
{

}
