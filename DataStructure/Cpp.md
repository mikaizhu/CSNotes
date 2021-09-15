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
