# 目录
<!--ts-->
* [目录](#目录)
* [数据结构与算法](#数据结构与算法)
   * [推荐资料](#推荐资料)
   * [vim 打开二进制文件](#vim-打开二进制文件)
   * [cin 用法](#cin-用法)
   * [cpp中查找序列的最大值](#cpp中查找序列的最大值)
* [数据类型强制转换](#数据类型强制转换)
* [cpp中的函数区间](#cpp中的函数区间)
* [数组](#数组)
* [哈希表](#哈希表)
* [字符串](#字符串)
* [二分搜索](#二分搜索)
* [滑动窗口](#滑动窗口)
* [链表](#链表)
* [KMP算法](#kmp算法)
* [队列与栈](#队列与栈)
* [单调队列](#单调队列)
* [优先队列](#优先队列)
* [二叉树](#二叉树)
* [递归](#递归)
* [树模型](#树模型)
   * [平衡二叉树](#平衡二叉树)
   * [遍历二叉树](#遍历二叉树)
   * [构造二叉树](#构造二叉树)
   * [二叉搜索树](#二叉搜索树)
   * [二叉树的静态成员函数问题](#二叉树的静态成员函数问题)

<!-- Added by: zwl, at: Thu Jul 14 18:50:08 CST 2022 -->

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

## cin 用法



## cpp中查找序列的最大值

```
int res;
vector<int> ve = {1, 2, 3, 4};
res = *max_element(ve.begin(), ve.end());

INT_MIN/INT_MAX
```


[【↥ back to top】](#目录)
# 数据类型强制转换
leetcode 18题

```
long sum = (long int) nums[i] + nums[j] + nums[left] + nums[right];
```


[【↥ back to top】](#目录)
# cpp中的函数区间
cpp中的函数一般是左闭右开，比如`reverse`函数，假如有数组`a = [0, 1, 2, 3]`
`a.begin() == 0`, `a.begin() + 1 == 1`因为是开区间，`reverse(a.begin(), a.begin() + 1`,则只对0起作用


[【↥ back to top】](#目录)
# 数组

数组是一块连续的内存地址, 二维数组也是连续的, 数组先会申请空间，如果空间不够，会申请一块新的内存, 这就导致很浪费时间

cpp 中的vector底层是使用array实现的

常用的方法：
- size
- push_back
- pop_back
- resize
- swap `swap(a[1], a[2])` 
- max_element()/min_element()

```
int maxn = *max_element(nums.begin(), nums.end());
int pos = max_element(nums.begin(), nums.end()) - nums.begin(); // 获取最大值的位置
```


一维数组初始化方法：

```
vector<int> v;
vector<int> v(3, 0); // 初始化大小为3，元素全为0
vector<int> v={1, 2, 3}; // 匿名
return vector<int>{1, 2, 3}; // 匿名
```

数据的切片：

```
vector<int> v1 = vector<int>(nums.begin() + pos1, nums.begin() + pos2);
```


二维数组：

```
vector<vector<int> > v;
vector<vector<int> > v(n, vector<int>(n, 0)); // 初始化二维数组，nxn大小
```

遍历方式：

```
// 主要有两种

for (int i = 0; i < nums.size(); i++)

for (vector<int>::iterator it; it != nums.end(); it++)
```


数组元素反转

```
reverse(res.begin(), res.end());
```

resize 用法：

```
可以减小内存空间的使用

a = [1, 2, 3, 4]
a.resize(2) // 1, 2
a.resize(5) // 1, 2, 3, 4, 0
```

数组排序:
```
sort(v.begin(), v.end(), [](int a, int b ) {return a > b})

struct compare {
  bool operator()(int a, int b) {
    return a > b;
  }
};

sort(v.begin(), v.end(), compare)
```

vector转set:

```
unordered_set<int> s(vector.begin(), vector.end());
unordered_set<int>(vector.begin(), vector.end());
```

- [参考cpp笔记](https://github.com/mikaizhu/CppNotes#vector)


[【↥ back to top】](#目录)
# 哈希表

常用的哈希表:
- map
- unordered_map
- set
- unordered_set

map和set底层实现是红黑树，unordered_map 底层是数组， unordered_set 底层是哈希表

map 和unordered_map 的区别是，map是有序的，unordered_map是无序的

set 和unordered_set 的区别是，set是有序的，unordered_set是无序的

map 常用的方法：

```
// 初始化
unodered_map<int, int> m;
unodered_map<int, int> m = {
  {1, 2},
  {2, 3}
};


// 插入元素
m.insert(pair<int, int>{1, 2})

// 获取大小
m.size()

// 寻找元素
m.find() // 返回的是迭代器
while (m.find() != m.end())

// 遍历元素
for(map<int, int>::iterator it=p.begin(); it != p.end(); it++) {
       cout << it->first << " " << it->second << endl; // 访问指针
}

for (auto it : map) {
  cout << it.second; // .访问属性
}
        


// 删除元素
m.erase(3);
m.erase(m.begin()+1);
```

set常用的方法：

```
// 初始化
unordered_set<int> s = {1, 2, 3};
unordered_set<int> s;

// 插入元素
s.insert(2);

// 获取大小
s.size();

// 寻找元素
s.find(2);  // 如果没有找到, 则返回s.end()

// 遍历元素
for (set<int>::iterator it; it != s.end(); it++)

// 删除元素
s.erase(3);

// for (auto i : s1) {
  cout << i << endl;
}
```

[【↥ back to top】](#目录)
# 字符串

字符串常用方法：

```
// 字符串的定义
string s;
string s(n, 'a');

// 字符串的反转
reverse(s.begin(), s.end());

// 字符串的拼接
string s1;
string s2;
s1 + s2;

// 数字转字符串
string s = "123";
int i = stoi(s); // 字符串转数字
// stod (s to double)
// stol (s to long)
cout << i << endl;

// 数字转字符串
s = to_string(i);

// char转字符串
string s(1, 'a');

// 字符串的遍历
for (int i = 0; i ...);

// 字符串的交换
swap(s[1], s[2]);
```




[【↥ back to top】](#目录)
# 二分搜索

二分查找的序列, 需要满足的条件:
- 数组已经排序好了
- 需要查找的元素，在数组中是唯一的

二分查找有两种模板：

一种是[left, right], 两边都是闭区间, 流程如下：
- while left <= right right == left 是有意义的
- if nums[mid] < target right = mid - 1 
- else if nums [mid] > target left = mid + 1
- else return mid

一种是[left, right), 两种区别在于，right此时为s.size() 而不是s.size() - 1, 否则就会少一个元素

```
while (left < right) {
  if (nums[mid] < target) {
    right = mid;
  }
  else {
    left = mid + 1;
  }
}
```

注意left和right的赋值

**重点**: 二分查找关键在于区间更新，每次搜索的内容，一定要保证在更新的区间[left, right] or [left, right)内！

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

链表一般是使用new进行管理，这样需要手动释放，万一有函数操作了链表，函数执行完后就释放了，会出现问题

链表创建方式如下：

```
class MyLink {
  private:
  int _size;
  Node *_fake;
  
  public:
  struct Node {
    int val;
    Node *next;

    Node(int val):val(val), next(nullptr) {};
    Node(int val, Node *next):val(val), next(next) {};
  };
  MyLink() {
    _size = 0;
    *fake = new Node(3);

    del fake; // 删除链表
    fake->next;
    fake->val;
  }
};
```


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

- KMP算法不会将字符串重新开始遍历，而是不断往前

```
aabaabaaf
     ^ 这里出现错误
aabaabaaf
 ^ 暴力解法是从这里开始下一次匹配, 同时模式串也重新开始匹配

aabaabaaf 
     ^ 字符串当前位置不变，模式串从b位置开始重新匹配
aabaaf
  ^  KMP是字符串不变，模式串从这里开始
```

KMP是怎么做到跳过某些字母呢？主要依靠**前缀表（next ｜ prefix）** ,
遇到冲突的时候，就会利用前缀表进行查询，然后跳转到对应模式串的位置开始匹配

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
aabaabaaf
 ^ 暴力解法是从这里开始下一次匹配

aabaabaaf
     ^ 这里出现错误
aabaaf
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
接下来，字符串从模式匹配的3位置开始继续匹配即可(如果还不匹配，则不断往前寻找，直到为0)

i = t
j = t 所以t的前缀为4
```

算法流程如下：

```
1. 求前缀表
  1. 初始化最开始为0，因为假如模式只有a，无前缀后缀
  2. 定义前缀开始位置和后缀开始位置i，j, i 为前缀开始位置，j为后缀开始位置: 如ab
     前缀为a 后缀为j, abb 前缀为a ab 后缀 b bb
  3. 开始进行匹配
    - 初始化i为0，j为1
    - 如果前缀后缀i，j相同，则i++, j++
    - 如果不一样，则把前缀i不断往回退i = next[i-1]，直到i = 0，则跳出循环
    - 给next赋值 next[j] = i
    - 说明：j的作用 1) 后缀开始位置 2）一系列字符串的末尾，如aab
      要得到每个位置的值，就要从aa aab计算a和b位置的
    - 说明：i的作用 1) 前缀开始的位置 2) 前缀表j位置的值
2. 利用前缀表开始匹配
  - int i=0 不断遍历字符串, 不回头
  - int j=0 不断遍历模式串
  - 如果不匹配，则不断回退，模式串j=next[j-1],
    然后比较当前j位置与i位置是否匹配，否则继续回退，直到j=0
  - 如果匹配，则i++,j++
```

代码如下：

```
// next计算代码
void get_next(int *next, string mode) {
    int i = 0;
    next[0] = i;
    for (int j = 1; j < mode.size(); j++) {
        while (i > 0 && mode[i] != mode[j]) { // 注意这里是while循环
            i = next[i-1];
        }
        if (mode[i] == mode[j]) {
            i++;
        }
        next[j] = i;
    }
}


// search匹配的代码
int strStr(string haystack, string needle) {
if (needle.size() == 0) return 0;
int next[needle.size()];
get_next(next, needle);
int j = 0;
for (int i = 0; i < haystack.size(); i++) {
  while (j > 0 && haystack[i] != needle[j]) { // 注意这里是while， 容易写成if
    j = next[j - 1];
  }
  if (haystack[i] == needle[j]) {
    j++;
  }
  if (j == needle.size()) return (i - needle.size() + 1);
}
return -1;
}
```

补充：next数组的意义是什么？

```
如模式串abcabcabc 由三个abc组成，这个模式串的前缀表怎么求呢？
i j 指针 从 ab开始
于是得到前缀表 000123456
a 初始化为0
ab s[i] != s[j] 所以为00
abc 000
abca 0001
abcab 最长公共前后缀为ab,此时i指向b j指向b i为2位置，所以为2
...
```
如何利用next数组找到重复的子字符串呢？
s字符串长度为9，next最后一个为6，如果`（9-6）% 3 ==
0`则说明有重复的，为什么末尾是6，则说明有重复的呢？

6表示位置6和当前字符一样**(这句话很重要)**，我们看第6个字符也是c，而第6个字符前缀是3，说明第三个字符也是c
5位置同理，4位置同理，3位置一样，重复的长度就是1开始前面的为0的，也就是9-6=3，模式长度为3

**参考** :
- [csdn KPM](https://blog.csdn.net/yearn520/article/details/6729426) 
- [知乎1](https://www.zhihu.com/question/21923021) 
- [知乎2 [状态机]](https://zhuanlan.zhihu.com/p/83334559) 
- [算法实现](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0028.%E5%AE%9E%E7%8E%B0strStr.md#28-%E5%AE%9E%E7%8E%B0-strstr) 


[【↥ back to top】](#目录)
# 队列与栈

队列：deque, queue
栈：stack

队列:
```
--------

--------
^      ^
队头   队尾
```
`deque` 是双端队列， `queue` 是普通队列

两者的区别主要在于：
1. 内部函数不一样
2. 添加元素的机制不一样

`queue` 实现了下面的函数，并且只能从一端`push`元素，从一端`pop`元素
- pop 将队头元素弹出来(注意并不会返回弹出来的元素，是void类型)
- push 将元素添加进队尾(注意是从队尾进入)
- front 返回队头元素
- back
- empty 判断队列是否为空
<<<<<<< HEAD
- size
=======
- size 查看大小
>>>>>>> 70a80c16324731bfa46216f4fcc6725561ba10af

`deque` 实现的是下面函数:
- pop_front
- pop_back
- push_back
- push_front
- empty
- front 查看队头元素
- back
- size

`stack` 实现的函数为:

- top
- pop
- push

```
sp -> ｜  ｜
      ｜  ｜
      ｜  ｜
      ｜  ｜
```


[【↥ back to top】](#目录)
# 单调队列

- 单调队列就是：队列中的元素都是单调递增或者递减的
- 单调队列可以不进行排序，优先队列要进行排序
- 单调队列的内容不是一层不变的，可以实现pop，push, top等函数，只要保证内部为单调的即可
- 单调队列的实现可以采用双端队列`deque` 


单调队列参考：
- https://labuladong.gitee.io/algo/2/21/53/
- https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.md


[【↥ back to top】](#目录)
# 优先队列

参考：
- https://labuladong.gitee.io/algo/2/21/55/

可以解决的题目：
- https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.md

涉及到的知识，二叉堆，大顶堆，小顶堆；

- 优先队列也属于一种队列数据结构，会按照内部数据的优先级进行排序，如可以从小到大或者从大到小排。
- 优先队列每次从队尾添加数据，队头弹出数据
- 优先队列使用的是数组进行实现的。
- 大顶堆是一种二叉树结构，父节点总是大于等于左右两个子节点，叫大顶堆，否则叫小顶堆。

**优先队列的实现**：

数组实现，只要知道父节点的位置，那么就可以算出整棵树的元素位置

```
[0, 1, 2, 3, 4, 5, 6]  // 数组的0位置一般不用, 根节点的元素是1

    1    
  2   3
4  5 6  7 

如果知道父节点在数组中的位置，那么其左节点为2*i, 右节点为2*i+1

同理，如果知道左右子节点的位置，那么父节点位置为i/2
```

**优先队列的顺序维护**：

这里以大顶堆进行说明，如果从队尾添加了一个数据，如何对整个堆进行排序呢？

- 上浮swim
- 下沉sink

1. 如果当前节点比子节点小，那么该元素就要sink，直到大于所有子节点为止，但是有左右两个节点，应该怎么交换呢？选择比较大的那个节点进行交换, 实现需要while循环，并且sink的时候，需要比较左右节点的位置
2. 如果当前节点比父节点大，那么元素就要swim，直到比父节点小为止

**实现delMax, insert** :

```
实现delmax

根节点就是最大元素，首先将根节点元素与最后一个元素交换，然后将最后一个元素赋值为null，然后从根节点开始执行sink函数即可。(这样根节点左右两边的元素自然就代替根节点位置了)


实现insert
将最后一个位置赋值为val，然后从该位置执行swin函数即可
```
cpp中的优先队列：`priority_queue`, 参考：
- https://blog.csdn.net/weixin_36888577/article/details/79937886

可以使用的方法有：
- pop
- push
- top
- size
- empty

`priority_queue`第一个参数为要放入优先队列的数据类型，第二个参数为实现优先队列的数据结构，必须是vector类型的框架（可以vector里面装的是pair），第三个参数为比较方式, 默认为vector容器实现，比较方式默认为大顶堆

```
priority_queue<int, vector<int>> q;

// pair的比较, unordered_map 底层就是pair
priority_queue<pair<int, int>, vector<pair<int, int>> > q;
```

自定义数据的比较方式：自己构建仿函数, 放函数

```
// 小顶堆实现方式
class my_compare {
  public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    }
};

// 大顶堆实现方式
class my_compare {
  public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
      return a.second < b.second;
    }
};

// 使用, 在初始化的时候就定义好
priority_queue<pair<int, int>, vector<pair<int, int>>, my_compare> q;
```

注意：优先队列是不能遍历内部元素的, 即无法通过迭代器遍历元素，也不能下标获得元素

```
for (priority_queue<int>::iterator it = q.begin(); it != q.end(); it++) 

获取的方法为：

while (!q.empty()) {
  cout << q.top();
  q.pop();
}
```

[【↥ back to top】](#目录)
# 二叉树

二叉树的种类：[参考](https://github.com/youngyangyang04/leetcode-master/blob/master/problems/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.md#%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E7%A7%8D%E7%B1%BB) 
- 满二叉树: 节点的度要么为0(叶子节点)，要么为2
- 完全二叉树: 节点可以不满，但是一定要先填满左边的位置
- 二叉搜索树: 左子树的所有元素，都要比根节点小，右子树的所有元素，都要比根节点大
- 平衡二叉树: 左子树的深度与右子树的深度差，不大于1, 且左右子树本身，也是平衡二叉树

二叉树的实现:
- 数组
- 链表


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

二叉树的遍历方式:

- 深度优先遍历法
- 广度优先遍历法

深度优先遍历法包括：
- 前序遍历(中左右)
- 中续遍历(左中右)
- 后续遍历(左右中)

广度优先遍历包括：
- 层次遍历

前中后都是根据中间节点位置进行遍历的，前序遍历刚进入树就开始添加，中续遍历在遍历完左边节点后，才开始添加，后续遍历一样

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

1. 确定递归函数需要的参数, 递归的返回内容是什么
2. 确定递归的终止条件
3. 确定递归的内容，哪些逻辑需要重复处理

更准确一点:
1. 找整个递归的终止条件：递归应该在什么时候结束？
2. 找返回值：应该给上一级返回什么信息？
3. 本级递归应该做什么：在这一级递归中，应该完成什么任务？

参考: https://lyl0724.github.io/2020/01/25/1/


[【↥ back to top】](#目录)
# 树模型

## 平衡二叉树

平衡二叉树主要有个知识点：节点的高度，和节点的深度，如：

```
   1
 2   3
4 5 6 7
```

那么根节点的深度就是1，高度为3;第二层的深度为2， 高度为2;

平衡二叉树即：该树的任意节点的左右子树高度差不大于1

这个递归比较好处理：
1. 确定递归的返回值和传入的参数：返回当前节点的高度，参数即传入当前节点
2. 确定递归的终止条件：如果当前节点为为叶子节点，则返回0
3. 确定递归的逻辑: 计算该节点的左子树的高度，计算该节点右子树的高度，如果高度差大于1，则返回高度为-1，表示无效，如果高度差小于等于1，则传入左右子树的最大值，再加上1，最后返回当前节点的高度

## 遍历二叉树

要想遍历二叉树的所有路径，并打印出来，可以使用方法：
1. 前序遍历
2. 递归

前序遍历除了使用`stack<TreeNode*>`, 还应该使用辅助栈`stack<string> sts`, 来模拟回溯

## 构造二叉树

参考：https://labuladong.github.io/algo/2/20/37/

主要思想为：
- 寻找到根节点
- 递归构造左右子树

构造分成：
- 根据前序和中序构造二叉树
- 根据中序和后续构造二叉树

**构造整棵树 = 根节点 + 构造左子树 + 构造右子树**

题目的构造条件：
- 前序和后续的元素要一样
- 二叉树内的元素不出现重复

构造方法：
- 使用递归比较方便
- 确定递归的传入参数，首先是前序遍历数组preorder，中序遍历数组inorder，数组的起始位置终止位置pstart,
  pend, istart, iend
- 确定递归的终止条件，当数组为空的时候，则返回空节点，这里表示为pstart > pend
- 确定内部的逻辑
  - 前序遍历，pstart位置，为根节点
  - 找到inorder数组中，根节点出现的位置pos, 该位置的左右两边分别为左子树，和右子树，同时还可以确认，左子树的节点个数为pos - pstart
  - 然后开始递归构造左子树，右子树，这时候注意左右子树的前序遍历起始位置和终止位置
  - preorder数组的起始位置为pstart+1，因为最开始为根节点，要排除。终止位置为pstart+1+左子树的size，这个可以前面获得
  - preorder数组的起始位置同理

使用前序中序；中序后续可以确定唯一的二叉树，而使用前序后续，不能确定二叉树，因为不能确定是左子树还是右子树

构造的话, 思路如下：
- 先从前序第一个为根节点，第二个为左叶子节点(如果数组长度为1，那么这样会溢出)
- 因此递归的截止条件为，要么数组长度为0，则返回null，如果数组长度为1，那么返回该节点(这样就不会溢出，因为此时函数直接返回了)
- 在后续遍历数组中，找到左叶子节点位置
- 计算左子树的长度
- 递归构造左子树
- 递归构造右子树

## 二叉搜索树

参考：
- 二叉搜索树的特征: https://labuladong.github.io/algo/2/20/41/
- 二叉搜索树的方法: https://labuladong.github.io/algo/2/20/42/

特点：
1. 根节点的值，要比左子树的所有节点值要大，比右子树的所有节点小.
2. 所有子树都有1的特点.
3. 根据上面两个特点，搜索树的中序遍历，是从小到大排序的.

如果要返回某颗子树：leetcode 700题
```
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        if (root->val < val) return searchBST(root->right, val);
        return nullptr;
    }
};
```

如何在递归中记录前一个指针：pre和cur？ # leetcode 530

本题的模板还是中序遍历：

```
void traversal(TreeNode* root, vector<int>& res) {
    if (root == nullptr) return;
    traversal(root->left, res);
    res.push_back(root->val);
    traversal(root->right, res);
}
```
要想记录pre节点和cur节点，只用将`res.push_back(root->val);`替换成pre = root即可，因为我们要用cur->val - pre-val
我们只用初始化pre为null即可

## 二叉树的静态成员函数问题

leetcode 501 搜索二叉树中的众数

该题目的思路为：
- 中序遍历搜索二叉树，将遍历的元素存起来, 采用map的方式存
- 将map转换成数组，因为map是乱序的，并不能根据频率排序
- 使用sort方法进行排序，sort中第三个cmp谓词参数，只能传入静态成员函数的指针
- 在外部定义静态成员函数cmp，从大到小排序

说明：
- cpp的类中成员函数，都是非静态成员函数，cpp中的成员函数，每个都还包括了this指针，相当于python中的self
- 所以要用sort方法，外部应该定义 `bool static cmp()` 
