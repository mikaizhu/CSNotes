#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        while (head->next == NULL)
            return head;
        ListNode* temp = head;
        head = head->next;
        ListNode* cur = reverseList(head);
        cur->next = temp;
        head = cur;
        return head;
    }
};
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        int flag = 1;
        ListNode* pre = head;
        while (head->next != NULL)
        {
            ListNode* cur = head;
            head = head->next;
            if (flag)
            {
                cur->next = NULL;
                flag = 0;
            }
            else
                cur->next = pre;
            pre = cur;
        }
        return pre;
};

int main()
{

}
