#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            // slow走一步，fast走两步
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
            {
                fast = head;
                while (fast != slow)
                {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};

int main()
{

}
