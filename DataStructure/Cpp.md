# Cpp Version

## 参考教程

- 1. [github解法](https://github.com/pezy/LeetCode) 
- 2. [gihub](https://github.com/liuyubobobo/Play-Leetcode)
- 3. [用法说明，查看](https://en.cppreference.com/w/) 

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


