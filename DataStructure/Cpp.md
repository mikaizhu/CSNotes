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


