#include <iostream>
#include <vector>

using namespace std;

struct Node
{
  public:
    double value; // 存储数据
    Node *next; // 指向下一个node

  public: // 构造函数初始化参数，以及构造函数的重载
    Node() : value(0), next(nullptr) {};
    Node(int val) : value(val), next(nullptr) {};
    Node(int val, Node *next) : value(val), next(next) {};
};

struct List
{
  public:
    List(int val) : head(new Node(val)) {};
    List(Node *node) : head(node) {};
    ~List()
    {
        if (head != nullptr)
            delete head;
        head = nullptr;
    }
  public:
    Node *head;
  public:
    void push_back(double value)
    {
        Node *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        Node *node = new Node(value);
        cur->next = node;
    }

    void travel()
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main()
{
    Node *node = new Node(4);
    // 方法1
    //List list(node);
    // 方法2
    List list(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    list.travel();
}
