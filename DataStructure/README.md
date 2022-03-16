# 目录
<!--ts-->
* [目录](#目录)
* [数据结构与算法](#数据结构与算法)
   * [推荐资料](#推荐资料)
   * [vim 打开二进制文件](#vim-打开二进制文件)
   * [字符串与数字之间的转换](#字符串与数字之间的转换)
   * [cpp中查找序列的最大值](#cpp中查找序列的最大值)
   * [数组元素反转](#数组元素反转)
* [队列](#队列)
* [堆](#堆)
* [二叉树](#二叉树)
* [递归](#递归)
* [二分搜索](#二分搜索)
* [滑动窗口](#滑动窗口)
* [链表](#链表)
* [KMP算法](#kmp算法)

<!-- Added by: zwl, at: Wed Mar 16 22:11:39 CST 2022 -->

<!--te-->
# 数据结构与算法

## 推荐资料

- [数据结构与算法 [Fucking Algorithm]](https://github.com/labuladong/fucking-algorithm) 
- [代码随想录](https://github.com/youngyangyang04/leetcode-master#%E6%95%B0%E7%BB%84) 

刷数据结构与算法的时候，遇到cpp语法问题，回到[CppNotes](https://github.com/mikaizhu/CppNotes) 进行补充

**算法其实也是遍历的一种方法，只不过相对于暴力解法，它排除掉了某些情况.** 

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

更准确一点:
1. 找整个递归的终止条件：递归应该在什么时候结束？
2. 找返回值：应该给上一级返回什么信息？
3. 本级递归应该做什么：在这一级递归中，应该完成什么任务？

参考: https://lyl0724.github.io/2020/01/25/1/


[【↥ back to top】](#目录)
# 二分搜索

二分查找的序列, 需要满足的条件:
- 数组已经排序好了
- 需要查找的元素，在数组中是唯一的

二分查找有两种模板：这里只介绍一种[left, right], 两边都是闭区间, 流程如下：
- while left <= right
- if nums[mid] < target right = mid - 1 
- else if nums [mid] > target left = mid + 1
- else return mid

[讲解参考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.md) 


[【↥ back to top】](#目录)
# 滑动窗口

主要思路：

- 窗口内是什么？
- 如何移动窗口的起始位置？
- 如何移动窗口的结束位置？


[【↥ back to top】](#目录)
# 链表

链表中值得注意的是：
- 自己创造一个虚拟节点会方便很多
- 有时候设置size变量手动调整长度，会方便很多

[参考笔记](https://github.com/mikaizhu/CppNotes#%E9%93%BE%E8%A1%A8) 


[【↥ back to top】](#目录)
# KMP算法

**KMP算法主要是解决字符串匹配的问题**

```
字符串:aabaabaaf
模式串:aabaaf
```

如果使用暴力解法, 使用两层for循环
```
for(int i = 0; i < s1.size(); i++) {
  int j = 0;
  for (; j < s2.size(); j++) {
    if (s1[i+j] != s2[j]) break;
   }
   if (j == s2.size()) return true;
}
return false;
```
可见，当匹配到f时，出现了冲突，暴力解法的话，是从下一个字符开始
```
aabaabaaf
     ^ 这里出现错误
aa
 ^ 暴力解法是从这里开始下一次匹配
aabaab
  ^  KMP是从这里开始
```

KMP是怎么做到跳过某些字母呢？主要依靠**前缀表（next ｜ prefix）** ,
遇到冲突的时候，就会利用前缀表进行查询，然后跳转到对应位置开始匹配

什么是前缀表？

- 什么是前缀
- 什么是后缀
- 什么是最长公共前后缀

1) 前缀是不包括最后一个字符的连续字符串，如`aabaaf` 的前缀为:

```
a
aa
aab
aaba
aabaa
```
2) 同理，后缀是不包括第一个字符的连续字符串：

```
f
af
aaf
baaf
abaaf
```

3) 最长相等前后缀怎么寻找？还是以`aabaaf`为例子:

```
a 的最长前后缀为0
aa 的前缀 [a] 后缀 [a] 所以最长相等前后缀为1
aab [a, aa] [b, ab] 0
aaba [a, aa, aab] [a, ba, aba] 1
aabaa [a, aa, aab, aaba] [a, aa, baa, abaa] 2
aabaaf [a, aa, aab, aaba, aabaa] [f, af, aaf, baaf, abaaf] 0
```

所以前缀表：得到这个前缀表后就可以反复利用

```
a a b a a f
0 1 0 1 2 0
```

之前暴力解法中，我们知道f位置出现错误，要是你的话，会从哪里开始匹配呢？

```
aabaabaaf
     ^ 这里出现错误
aa
 ^ 暴力解法是从这里开始下一次匹配
aabaab
  ^  KMP是从这里开始
```
当f位置出现错误，从冲突的位置的前一个符号前缀表进行查询，为2，所以从最开始a往后2个位置地方进行查询

```
aabaabaaf
     ^
aabaaf 
     ^ 发现错误

aabaabaaf
     ^ 待搜索字符指针不变
aabaaf
  ^  模式字符从前缀表中搜索，然后跳转到下一个位置,
  f前面的aa已经匹配过了，所以不用重新匹配，可以跳过, 也只是跳过某些匹配模式

aabaabaaf
aabaaf
   ^
```

[可以参考这个图片](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md#:~:text=%E5%86%8D%E6%9D%A5%E7%9C%8B%E4%B8%80%E4%B8%8B%E5%A6%82%E4%BD%95%E5%88%A9%E7%94%A8%20%E5%89%8D%E7%BC%80%E8%A1%A8%E6%89%BE%E5%88%B0%20%E5%BD%93%E5%AD%97%E7%AC%A6%E4%B8%8D%E5%8C%B9%E9%85%8D%E7%9A%84%E6%97%B6%E5%80%99%E5%BA%94%E8%AF%A5%E6%8C%87%E9%92%88%E5%BA%94%E8%AF%A5%E7%A7%BB%E5%8A%A8%E7%9A%84%E4%BD%8D%E7%BD%AE%E3%80%82%E5%A6%82%E5%8A%A8%E7%94%BB%E6%89%80%E7%A4%BA%EF%BC%9A) 

从图中可以看出，假设字符串的长度为n，模式字符串的长度为m，最后算法的复杂度为O(n+m), 暴力解法为O(n*m), 步骤如下：
- 先算出查询表，复杂度O(m)
- 遍历字符串，并不断根据前缀表，更新前缀表匹配的位置

```
a
aa
aab
aaba
aabaa
aabaaf

前缀表之所以这样弄，是因为每个位置都可能是检查点(可能会发生冲突)，所以要得到每个位置的最长公共前缀
```

如何编程实现前后缀表呢？

```
a 的最长前后缀为0
aa 的前缀 [a] 后缀 [a] 所以最长相等前后缀为1
aab [a, aa] [b, ab] 0
aaba [a, aa, aab] [a, ba, aba] 1
aabaa [a, aa, aab, aaba] [a, aa, baa, abaa] 2
aabaaf [a, aa, aab, aaba, aabaa] [f, af, aaf, baaf, abaaf] 0
```

有以下几种情况：

```
1. 如果当前位置前缀为0，然后来了个新字符，只要比较当前字符和第一个字符是不是一样即可，如果一样，则前缀加1，否则为0
aab [a, aa] [b, ab] 0
aaba [a, aa, aab] [a, ba, aba] 1

从上面可以看出来了个新字符a，与第一个字符相等，则加1，不可能大于1，为什么呢？因为前面不对称。
写出所有情况[a, aa, aab] [a, ba, aba], a与a比较相等，而这两种情况：aa与ba比较,
aab与aba比较，怎么利用上一个比较结果，确定这两个肯定不会对称呢？我们知道开头的a和末尾的a一定对称的，那么中间只要有不对称的，就一定不对称。
aa & ba --> a & b; aab & aba --> aa && ab

2. 如果当前前缀为1，然后来了个新字符,
   如果新字符与第二个相等，则前缀在之前的基础上加1，如果不同，则不能继承之前的前缀了(第三点讨论), 依次类推，来了第二个就比较第三个b

aaba [a, aa, aab] [a, ba, aba] 1
aabaa [a, aa, aab, aaba] [a, aa, baa, abaa] 2

3. 前缀大于0，且新来的字符与第一个不匹配,
   那么新字符的前缀一定比前一个字符前缀小(如果比之前的大，肯定要继承之前的前缀，然而新字符不匹配)

假如字符: 其中t为新来的字符，从a开始往后，前缀分别为1，2，3，4，5，6，7
a g c t a g c a g c t a g c t
(a g c t a g c) (a g c t a g c) t

我们用肉眼可以发现最小前缀为agct
0 0 0 0 1 2 3 1 2 3 4 5 6 7 ?
a g c t a g c a g c t a g c t

前缀表流程如下：
i = a 
j = g

i = a
j = g

i = a
j = c

i = a
j = t

i = a
j = a 

i = g
j = g

...

当到:
i = a
j = t时 出现不相等, 查找前一个位置的前缀为3，于是跳到3位置,
接下来，字符串从模式匹配的3位置开始继续匹配即可

i = t
j = t 所以t的前缀为4
```

算法流程如下：

```
1. 求前缀表
  1. 初始化最开始为0，因为假如模式只有a，无前缀后缀
  2. 定义前缀开始位置和后缀开始位置i，j
  3. 开始进行匹配
    - 如果前缀后缀i，j相同，则i++, j++
    - 如果不一样，则把前缀i不断往回退，直到s[i] = s[j]
3. 利用前缀表开始匹配
```

**参考** :
- [csdn KPM](https://blog.csdn.net/yearn520/article/details/6729426) 
- [知乎1](https://www.zhihu.com/question/21923021) 
- [知乎2 [状态机]](https://zhuanlan.zhihu.com/p/83334559) 
- [算法实现](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md#28-%E5%AE%9E%E7%8E%B0-strstr) 
