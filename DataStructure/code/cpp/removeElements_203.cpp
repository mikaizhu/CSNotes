#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x) , next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x) , next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头节点
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next != nullptr) 
        {
            if (cur->next->val == val)  // 如果下一个节点的值是val，则删除
            {
                ListNode* temp = cur->next; // 需要temp存储中间节点，最后删除
                cur->next = cur->next->next; // 将当前指针，链接到后面指针
                delete temp;
            }
            else
                cur = cur->next; // cur指针在移动
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main()
{

}
