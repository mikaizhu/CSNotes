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

## 队列

队列指的是deque，先进先出，并且内存结构不是连续的。

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


## 堆

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


