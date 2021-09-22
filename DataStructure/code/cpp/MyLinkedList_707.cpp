#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MyLinkedList {
// 定义链表节点数据结构
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };
    /** Initialize your data structure here. */
// 定义私有变量，方便链表维护
private:
    int _size;
    LinkedNode* _dummyHead;
public:
    MyLinkedList() {
        _size = 0; // 初始化长度，方便链表的维护
        _dummyHead = new LinkedNode(0); // 初始化虚拟头节点，同样方便维护
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        LinkedNode* cur = _dummyHead->next;
        if (0 > index || index >= _size)
            return -1;
        while (index--)
            cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkedNode* new_node = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = new_node;
        _size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index <= _size)
        {
            LinkedNode* cur = _dummyHead;
            LinkedNode* newNode = new LinkedNode(val);
            while (index--)
                cur = cur->next;
            newNode->next = cur->next;
            cur->next = newNode;
            _size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        // 不管index是不是0节点，都在前面加个虚拟节点
        if (0 <= index && index < _size)
        {
            LinkedNode* cur = _dummyHead;
            LinkedNode* temp;
            while (index--)
            {
                cur = cur->next;
            }
            temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            _size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main()
{

}
