# Cpp Version

# 参考教程

- 1. [github解法](https://github.com/pezy/LeetCode) 
- 2. [gihub](https://github.com/liuyubobobo/Play-Leetcode)
- 3. [用法说明，查看](https://en.cppreference.com/w/) 

# 贪心算法

贪心算法思想：问题整体可以分成很多独立的个体，使得每个个体达到最优解，最后整体
可以达到最优解.

## twoSum

- [reference](./code/cpp/twosum.cpp) 

需要用到的容器unordered_map, 普通的map是有序的，按照key进行排序，这里不需要有
序

哈希表的数据查找时间复杂度为O(1), 假如出现一个key，经过哈希计算，会得到一个数
字，用这个数字除以内存地址长度，余数就是这个数据存的位置，当余数一样，就会以链
表的方式存储.

- [method1](./code/cpp/twosum.cpp) 
- [method2](./code/cpp/twosum1.cpp) 


注意以下几点：

1. 使用find方法查找元素，返回的是一个迭代器，map的find返回的是map迭代器，如果
   没找到，则会返回map的end迭代器
```
unordered_map<int, int>::iterator it = hashmap.find(target - nums[i]);
```

2. map可以通过 下标来进行索引和数据存储

```
hashmap[nums[i]] = i;
```

## 两数反转

注意以下几点：

- cpp 中余数是负整数， 即 -10 % 9 = -1， 在python中是正整数
- cpp中有定义的几种常数 `INT_MAX` int最大值, `INT_MIN` int最小值

[method](./code/cpp/reverse.cpp) 

## 罗马数字转整数

c++ 字符串操作

```
s = "hello world";
s[0] = 'H'; // 获取和修改字符串的值

// 遍历字符串
for (string::iterator it=s.begin(); it != s.end(); it++)
  cout << *it << endl;

// 从第一个字符开始遍历
for (string::iterator cur = s.begin() + 1; cur != s.end(); cur++)

// 也可以不使用迭代器的方式遍历字符串，直接使用长度
for (int cur = 0; cur < s.length(); cur++)
  cout << s[cur];
```

这道题思想就是：因为罗马数字会有出现在左边的情况，如`IV` 这种情况就是5 - 1，所
以如果pre的字符小于cur的字符，就减去pre

这样几句导致会少一个字符cur加不到，所以可以在后面补充，Q为停止字符，并且Q要小
于I的字面值。

[method1](./code/cpp/romanToInt.cpp) 
[method2](./code/cpp/romanToInt1.cpp) 

另一种方法是同样的思路，我们知道如果左边比右边小，就做减法，这样推算，最右边数
就一定做加法，因此可以用当前位与下一位判断，如果比下一位小，则减去当前位，如果
没有下一位，则直接相加.

## 455饼干发放

思路：假设有小孩 1 3 4 5 饼干 1 2 3 4 

那么可以满足多少个小孩？先从小到大排序好，注意审题清楚. 如果饼干尺寸不满足，是
不能分给小孩的.

注意代码以下几点：
- sort排序方式
```
sort(g.begin(), g.end());
```

## 135分发糖果

注意这个题目的条件
- 每个孩子至少分配到一个糖果
- 评分更高的孩子必须比两侧相邻的孩子分的糖果多

对于第一个条件，那么我们就可以初始化所有人分一个糖果

对于第二个条件, 评分更高，说明要同时大于左边，也同时大于右边，常规思路是使用
left mid right来使得同时满足，但这样会复杂代码，我们可以使用两次for循环，即将
中间那个数同时大于左边，同时大于右边，分成以下条件：

1. 先从左边遍历，判断当前数与左边的数的大小关系，如果右边分数大于左边，那么右边糖果数比左边多一，这个是肯定的，一定
  会比左边多1，因为如果不多1，那么就不满足条件分更高的糖果更多。所以条件1一定
  成立
2. 从右边往左边遍历，判断当前数与右边数的关系，如果当前数的评分比右边数高，如果
  只满足这个条件，不能说明中间分数比两边高。因为条件1确定了，但我们却没用上。
  此时只能说明当前分比右边高，所以要想办法将条件1利用起来。将当前评分和右边评
  分，看成从左边遍历，如果右边评分 大于 当前评分，那么左遍历的时候，右边评分一
  定会比当前评分的糖果多1，也就是说，如果右边糖果比当前糖果多，那么右边评分一
  定大于当前评分。反过来，如果右边糖果比当前糖果少, 则当前评分一定大于等于右边
  评分


```
问题1:使用两次遍历的时候，我们使用先从左边往右边遍历，然后再使用从右边往左边遍历，为什么两次遍历不都从左边往右边遍历呢(第二次遍历用i+1与i比较)？

举个例子，假设现在分数为1，0，2，先初始化所有糖果为1，从左往右边遍历，糖果数更新为1，1，2，我们此时可以看到最右边更新为2了，即最右边一定满足局部最优，如果从左边往右遍历，就没有用到这个确定的最优状态更新前面不确定的状态，只有从右边往左遍历，才使用了这个条件，不断更新前面的状态，达到最优。

问题2:为什么分两次遍历，记录从左边往右边遍历的糖果数，存在数组中left，同时记录从右边往左遍历的糖果数，然后取最大值即可满足中间一定最大。

这可以转换成很简单的数学问题。
从左往右边遍历，x>ax>a x为中间糖果，a为右边糖果，从右边往左边遍历，y>by>b y为中间糖果，b为右边糖果，证明max(x,y)>a and bmax(x,y)>aandb

证明如下，假设a = b，显然max(x，y)大于a和b
假设 a > b,因为x>a 所以取x即可满足
同理可证。所以两次遍历，然后取最大糖果数，即可满足中间最大条件
```


## 435无重叠区间

贪心的一般思路是，如果题目没有要求不能排序，一般使用排序，这题重叠区间末端是按从小
到大排序，如果末端的区间越小越好，这样就可以使得重叠的可能性越低。然后for循环
遍历排序好的子区间，如果子区间的起始点小于之前的末端，那么说明有重合，则跳过，
如果没重叠，则更新末端.

```
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[1] < b[1];});
        int remove_count = 0;
        if (intervals.size() < 2)
            return 0;
        int pre_v = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < pre_v)
                remove_count++;
            else
                pre_v = intervals[i][1];
        }
        return remove_count;
    }
};
```

## 605. 种花问题

思路：因为花不能有间隔，所以从0开始跳跃即可，如果当前位置为0，且下一个位置不是
1，则可以种花。如果下一个位置是1，则i加1，然后又从1位置开始跳跃，因为1位置后面
一定是0，所以可以不用全部遍历

```
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i+=2)
        {
            if (flowerbed[i] == 0)
            {
                if (i+1 == flowerbed.size() || flowerbed[i+1] == 0)
                    n--;
                else
                    i++;
            }
        }
        return n <= 0;
    }
};
```

## 452. 用最少数量的箭引爆气球

思路：这个和435题差不多，435是无重叠区域，这个题是相当于找最大重合的，因为数组
是二维的，所以可以先排序，从数组的第一个元素开始排。设置start和end，start为重
叠的最大，end为重叠最小部分，每次遍历看有没有在这个区间，有就更新。

```
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){if (a[1] == b[1]) return a[0] < b[0]; else return a[1] < b[1];});
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){return a[0] < b[0];});
        //print(points);
        int arrow_count = 1;
        int start = points[0][0], end = points[0][1];
        for (int i = 1; i < points.size(); i++)
        {
            if (start <= points[i][0] && points[i][0] <= end)
            {
                points[i][0] > start ? start = points[i][0] : start = start;
                points[i][1] < end ? end = points[i][1] : end = end;
            }
            else
            {
                arrow_count++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return arrow_count;
    }
};
```
# 双指针


## 142. 环形链表 II

两个方法：

1. 方法1: 使用set存储链表的节点，如果遇到了重复的节点，那么就返回该节点，否则
   返回NULL

```
unordered_set<ListNode *> visited;
```


2. 使用快慢指针，由于fast指针速度是slow指针速度的两倍，所以两者的路程差距一定
   是nb，b为环的长度。可以设置slow走的路程刚好是nb，fast的路程则为2nb，由于不
   知道相遇点在哪，所以还要走a步即可。参考: https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/


## 76. 最小覆盖子串(TODO)


```

```


## 633. 平方数之和

要注意这里要用long类型的数据，为了避免溢出，long的长度为32，right为31，2*31还
是小于32长度，所以保证不会溢出.

```
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (int)sqrt(c);
        long sum;
        while (left < right)
        {
            sum = left * left + right * right;
            if (sum < c)
                ++left;
            else if (sum > c)
                --right;
            else
                return true;
        }
        return false;
    }
};
```

## 680. 验证回文字符串 Ⅱ

写个额外的验证代码即可，判断子串是不是也是回文字符串

# 二分查找

二分查找的序列，一定要事先排序好.

当我们将区间[l, r]划分成[l, mid]和[mid + 1, r]时，其更新操作是r = mid或者l = mid + 1，计算mid时不需要加1，即mid = (l + r)/2。

参考：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/tu-jie-er-fen-zui-qing-xi-yi-dong-de-jia-ddvc/

## 69. x 的平方根

就是每次搜索区间折半

如果mid * mid 会溢出，那么将数据设置成 (long long)mid * mid

- [参考代码](./code/cpp/mySqrt.cpp) 


## 34. 在排序数组中查找元素的第一个和最后一个位置

一般写法

```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int i = 0;
        for (; i < nums.size() && nums[i] <= target; i++)
        {
            if (res.empty() && nums[i] == target)
                res.push_back(i);
        }
        if (res.empty())
            return {-1, -1};
        res.push_back(i-1);
        return res;
    }
};
```

二分搜索:

二分搜索找两个位置，实现两次二分查找:
- 第一个位置为第一个找到目标的位置, 如果mid位置的数大于等于target，则往左边找
  ，这样就能找到第一个位置(等价于先找到mid等于target的位置，然后往左边找左区间)
- 第二个位置为刚好大于目标的位置, 如果mid位置的数大于等于target，则往右边位置
  找，这样能找到右边界

如果目标不在数组中，那么会怎么样？

- 如果不在数组中，left会大于right

- [参考代码](./code/cpp/searchRange.cpp) 

## 33. 搜索旋转排序数组(TODO)


# cpp中的字符串

```

```

<++>

# c++中的链表

参考教程：https://blog.csdn.net/ccblogger/article/details/81176338

整个链表有两个结构，一是节点类，二是链表类, 首先构造节点类

```
struct Node
{
  public:
    double value; // 存储数据
    Node *next; // 指向下一个node

  public: // 构造函数初始化参数，以及构造函数的重载
    Node() : value(0), next(nullptr) {};
    Node(int val) : value(val), next(nullptr) {};
    Node(int val, Node *next) : value(0), next(next) {};
};
```

节点类包括以下内容：

- 存储当前数据
- 存储下一个数据地址

上面代码实现了三种构造函数的代码

然后是链表类代码的实现：

```
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
};
```

该类中包括
- 头指针，指向第一节点的地址
- 两个构造函数，所以可以使用两种方法创建链表

方法1:
```
Node *node = new Node(4);
List list(node);
```

方法2:

```
List list(4);
```

因为list实现了下面方法：

```
List(int val) : head(new Node(val)) {}; // 初始化了一个链表
```

一定要使用new创建节点，因为如果不用new，函数在创建完就会释放，new的空间不会释
放

- [参考代码](./code/cpp/listNode.cpp) 

## 203. 移除链表元素

题目链接：https://leetcode-cn.com/problems/remove-linked-list-elements/

思路链接：https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.md

代码讲解：

```
// 思路1：设置虚拟头节点
ListNode* dummy = new ListNode(0, head); // 一定要使用new创建一个新节点
ListNode* cur = dummy; // 设置个cur指针类型，用来专门移动, 因为如果dummy移动了
，就找不回链表了

```

## 707. 设计链表

```
// 首先定义Link类
class MyLinkedList {};

// 然后在类中实现Node节点数据结构
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

// 定义私有变量size和dummynode，方便代码维护
private:
    int _size;
    LinkedNode* _dummyHead;

// 结构体初始化, 不需要head来维护，只要虚拟头节点就好
public:
    MyLinkedList() {
        _size = 0; // 初始化长度，方便链表的维护
        _dummyHead = new LinkedNode(0); // 初始化虚拟头节点，同样方便维护
    }
```

- [参考代码](./code/cpp/MyLinkedList_707.cpp) 

## 24. 两两交换链表中的节点

- 最好添加个虚拟头节点
- 最好画图，然后实现

```
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
```

## 19. 删除链表的倒数第 N 个结点

- 使用快慢指针，快指针比慢指针先走
- 同时使用虚拟头节点

```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *fast = dummyHead, *slow = dummyHead;
        while (n--)
            fast = fast->next;
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead;
    }
};
```

# 哈希表

cpp中的哈希表有好几种类型，包括：

- map
- set
- 数组

## 242. 有效的字母异位词

从这道题中可以学习：

```
int l[2] = {0}; // 这样就是定义{0, 0}
```

字符相减是整数

```
'a' - 'a' // 0
```

使用三个循环，这题只用普通的数组即可，统计s字符，维护一个数组，有26个字母，出
现则加1

第二个循环对该数组减法

第三个循环遍历数组，如果所有元素不为0，则返回false


## 1002. 查找共用字符

```
string s(1, 'a');

两个字符串相减或者相加，会变成整数

'a' - 'a' // 0

可以利用string将int/char转换成string
string s(1, 1 + 'a');
```

- 将数组初始化为0, 按字节来初始化
```
memset(hashOtherStr, 0, 26 * sizeof(int));
```

## 349. 两个数组的交集

新的遍历方式

```
for (int num : nums2)
{
  if (temp.find(num) != nums2.end())
    res.insert(num);
}

```

vector转set

```
unordered_set<int> temp(nums1.begin(), nums1.end()); // 将vector转换成set
```

`unordered_set` 底层实现是哈希，其他set是红黑树，所以效率会更快点.


## 1. 两数之和

迭代器有两种写法：

```
1. 使用auto关键字
auto it = hashmap.find(target - nums[i]);

// 正确写法如下:
unordered_map<int, int>::iterator it = hashmap.find(target - nums[i]);
```

哈希表赋值也有以下方法：

```
hashmap[nums[i]] = i;

// 使用pair进行赋值
hashmap.insert(pair<int, int>(nums[i], i))
```

## 454.四数相加


## 15 三数之和

我的思路：要考虑初始化，代码结构复杂

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {}; // 如果长度小于3，则返回空矩阵
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        // 初始化，为了避免和之前元素值相同, 所以初始化为原来减1
        int left = 0;
        int pre_left = nums[left] - 1;
        for (; left < nums.size() - 2; left++)
        {
            if (nums[left] == pre_left) // 避免重复
                continue;
            int mid = left + 1, right = nums.size() - 1;
            int pre_mid = nums[mid] - 1, pre_right = nums[right] - 1;
            while (mid < right)
            {
                int sum = nums[left] + nums[mid] + nums[right];
                if (sum == 0)
                {
                    cout << left << " " << mid << " " << right << endl;
                    res.push_back({nums[left], nums[mid], nums[right]});
                    pre_mid = nums[mid];
                    mid++;
                    while (nums[mid] == pre_mid && mid < right)
                        mid++;
                    pre_right = nums[right];
                    right--;
                    while (nums[right] == pre_right && mid < right)
                        right--;
                }
                else if (sum < 0)
                {
                    pre_mid = nums[mid];
                    mid++;
                    while (nums[mid] == pre_mid && mid < right)
                        mid++;
                }
                else
                {
                    pre_right = nums[right];
                    right--;
                    while (nums[right] == pre_right && mid < right)
                        right--;
                }
            }
            pre_left = nums[left];
        }
        return res;
    }
};

```

```
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res; // res初始化为空矩阵
        if (nums.size() < 3) return res; // 如果长度小于3，则返回空矩阵
        sort(nums.begin(), nums.end());
        // 初始化，为了避免和之前元素值相同, 所以初始化为原来减1
        for (int left = 0; left < nums.size() - 1; left++)
        {
            if (nums[left] > 0) return res;
            if (left > 0 && nums[left] == nums[left - 1]) // 使用left > 0去除重复
                continue;
            int mid = left + 1, right = nums.size() - 1;
            while (mid < right)
            {
                int sum = nums[left] + nums[mid] + nums[right];
                if (sum > 0)
                {
                    right--;
                    while (right > mid && nums[right] == nums[right + 1]) right--;
                }
                else if (sum < 0)
                {
                    mid++;
                    while (right > mid && nums[mid] == nums[mid - 1]) mid++;
                }
                else
                {
                    res.push_back({nums[left], nums[mid], nums[right]});
                    right--;
                    mid++;
                    while (right > mid && nums[right] == nums[right + 1]) right--;
                    while (right > mid && nums[mid] == nums[mid - 1]) mid++;
                }
            }
        }
        return res;
    }
};
```


## 18四数之和

解决此题溢出的问题：

```
long sum = (long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right];
```

# 字符串

## 541. 反转字符串 II

1. 交换两个字符的位置

```
while (left <= right)
{
  swap(s[left], s[right]);
  left++;
  right--;
}
```

2. reverse的写法

```
reverse(s.begin() + left, s.begin() + right + 1);

假如字符串是as
说明: 比如是reverse(s.begin(), s.begin() + 1)
本来以为会将as反转过来, 其实不会，要s.begin() + 2 才会
```

## 剑指Offer 05.替换空格

两种方法，第一种要申请额外的空间, 使用字符串的拼接

```
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for (char c : s)
        {
            if (c == ' ') res += "%20";
            else res += c;
        }
        return res;
    }
};
```

另一种是提前申请空间，然后将字符补充进去，所以需要从右边往左遍历

```
class Solution {
public:
    string replaceSpace(string s) {
        // 统计有多少个空格
        int count = 0;
        for (char c : s)
            if (c == ' ') count++;
        if (count == 0) return s;
        int left = s.size() - 1;
        s.resize(s.size() + 2*count); 
        // 2是多出来的字符长度, risize后，末尾都是空字符
        // 然后从右边开始遍历, 遇到空格就向右边移动，所以从右边开始遍历
        int right = s.size() - 1;
        while (left >= 0)
        {
            if (s[left] != ' ') 
            {
                s[right] = s[left];
                right--;
            }
            else
            {
                s[right] = '0';
                s[right-1] = '2';
                s[right-2] = '%';
                right -= 3;
            }
            left--;
        }
        return s;
    }
};

```

# 栈与队列

队列能实现的操作有以下几种：

- pop()
- push()
- empty()


## 用栈实现队列

如果要用两个栈实现队列，队列是先进先出，而栈是先进后出，如果利用两个栈，就可以
实现先进先出。

如果一个栈是先进后出，将一个栈的元素再输入到另一个栈中，两个先进后出，就变成先
进后出了。

- [参考代码](./code/cpp/MyQueue_232.cpp) 

## 用队列实现栈

可以使用两个队列来实现，用一个队列进行数据备份，队列可以使用的操作有

- size()
- front()
- back()
- pop()

## 有效括号

利用栈的思想，最完美的写法如下：

```
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (char c : s)
        {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            // 进过上面if else后，如果stack为空，说明没有左括号，输入只有右括号
            else if (st.empty() || st.top() != c) return false;
            else st.pop();
        }
        return st.empty();
    }
};
```


## Leetcode 1047 删除字符串中的所有相邻重复项

输入字符串 “abbaca”
其中bb相邻，先删除bb，删除后aa变成相邻的，于是删除aa，最后剩下ca返回

思路就是用一个栈，算法实现后栈内会剩下 a c

对字符串拼接然后反转字符串，就可以得到答案

        s = string("");
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());


另一个思路是直接拼接和反转字符串一起

        s = string("");
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }

第二种超时了，不知道是什么原因？

```

```

上面要用到额外的空间，另一种方法可以直接使用字符串作为栈的形式，要用到字符串的
几个方法:

- empty()
- back()
- push_back()
- pop_back()

```
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char c : s)
        {
            if (res.empty() || res.back() != c)
                res.push_back(c);
            else
                res.pop_back();
        }
        return res;
    }
};
```


