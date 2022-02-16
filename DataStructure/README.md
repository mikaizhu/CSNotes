# 目录
<!--ts-->
* [目录](#目录)
* [数据结构与算法](#数据结构与算法)
   * [vim 打开二进制文件](#vim-打开二进制文件)
   * [字符串与数字之间的转换](#字符串与数字之间的转换)
   * [cpp中查找序列的最大值](#cpp中查找序列的最大值)
   * [数组元素反转](#数组元素反转)
* [队列](#队列)
* [堆](#堆)
* [二叉树](#二叉树)
* [递归](#递归)
* [二分搜索](#二分搜索)

<!-- Added by: zwl, at: 2022年 2月16日 星期三 11时08分51秒 CST -->

<!--te-->
# 数据结构与算法

## vim 打开二进制文件

```
转换成二进制
:% ! xxd

转回原来的
:% ! xxd -r
```

## 字符串与数字之间的转换

常用知识点：

```
string s = "123";
int i = stoi(s); // 字符串转数字
// stod (s to double)
// stol (s to long)
cout << i << endl;
s = to_string(i);
```

## cpp中查找序列的最大值

```
int res;
vector<int> ve = {1, 2, 3, 4};
res = *max_element(ve.begin(), ve.end());
```

## 数组元素反转

```
reverse(res.begin(), res.end());
```



[【↥ back to top】](#目录)
# 队列

队列指的是deque，先进先出，并且内存结构不是连续的。

- 单端队列(queue)

> 只允许对一端进行插入操作，可以查看两端数据

- 双端队列(deque)

> 可以对两端进行插入和删除操作

- 单调队列

> 队列中的元素要么单调增，要么单调减，需要自己手动实现

- 优先队列

> 优先队列一般使用堆来实现, 普通队列为先进先出，优先队列给每个元素赋予优先级，优
> 先级最高的最先删除，返回等操作.

优先队列用法总结：https://blog.csdn.net/xiaoquantouer/article/details/52015928

`priority_queue<Type, Container, Functional>`

Type为数据类型， Container为保存数据的容器(我们知道堆是用vector实现的，所以这
里默认用vector)，Functional为元素比较方式。

```
priority_queue<int, vector<int>, cmp> pri_queue;

// 自定义数据类型，用vector装自定义数据类型
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pri_queue;
```



[【↥ back to top】](#目录)
# 堆

堆就是用数组实现的二叉树，所以它没有使用父指针或者子指针。堆根据“堆属性”来排序，“堆属性”决定了树中节点的位置。

参考：jianshu.com/p/6b526aa481b1

堆分为大顶堆和小顶堆，大顶表示父节点比左右节点都大。

```
// 利用仿函数，排序自己定义的数据结构
class cmp {
    public:
      bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
          return lhs.second > rhs.second; // second是元素的频率，因为堆是完全二叉树，右边大于左边，表示最小堆
      }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> _que; // 小顶堆实
现
```


[【↥ back to top】](#目录)
# 二叉树

二叉树节点的定义：

```
struct treeNode {
  public:
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(NULL), right(NULL) {}; // 初始化
    treeNode(int val) : val(val), left(NULL), right(NULL) {}; // 初始化
    treeNode(int val, treeNode *left, treeNode *right) : val(val), left(left), right(right) {}; // 初始化
};
```

前中后序遍历：[参考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E9%80%92%E5%BD%92%E9%81%8D%E5%8E%86.md) 

前序

```
// 不用this也可以
class Solution {
public:
    void traversal(TreeNode *root, vector<int>& res) {
        if (root == NULL) return;
        res.push_back(root->val);
        this->traversal(root->left, res);
        this->traversal(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        this->traversal(root, res);
        return res;
    }
};
```

除了使用递归的方式，还有使用栈进行迭代

层序遍历：一层一层从左往右边输出，使用队列数据结构来实现，因为先进先出

如何记录每一层呢？队列queue是动态变化的，我们可以记录每一层的个数，就可以区分
开来。第一层弹出队列后，队列的大小就是第二层的个数。



[【↥ back to top】](#目录)
# 递归

递归三部曲：

1. 确定递归函数需要的参数
2. 确定递归的终止条件
3. 确定递归的内容，哪些逻辑需要重复处理


[【↥ back to top】](#目录)
# 二分搜索

二分查找的序列，一定要事先排序好.

模板: 当我们将区间[l, r]划分成[l, mid]和[mid + 1, r]时，其更新操作是r = mid或者l = mid + 1，计算mid时不需要加1，即mid = (l + r)/2。

Q1: right长度是多少呢？nums.size() - 1 还是 nums.size() ? 

这个要具体问题具体分析，如果right = nums.size() - 1, 那么循环条件是l < r的时候
，l最多可以返回到nums.size(), 如果题目的答案可能大于nums.size(), 那么right 应
该等于 nums.size()

Q2: 为什么循环的结束条件是 while (l < r) 而不是 while (l <= r) ?

如果使用上面模板，则不应该使用小于等于, 这样可能回进入死循环, 这里要具体问题具
体分析

参考：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/tu-jie-er-fen-zui-qing-xi-yi-dong-de-jia-ddvc/

