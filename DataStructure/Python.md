# Python Version

参考：https://note.youdao.com/s/dqvKKchb

# 链表

## 单链表

链表每个节点我们称为 node, 每个节点存储着两个信息。

- 该节点的item
- 下个节点的地址

比如一个节点 11 0x12.在c语言中，地址直接使用指针即可，c中有专门的地址类型的数据, 在python中，一切皆为对象，并没有地址的概念。那么py中如何实现但链表呢

我们先看一个简单的例子：

```
a = 1
b = 2

b,a = a,b
```

```
a = 1
b = 2
print(id(a), id(b))

a, b = b, a
print(id(a), id(b))

4452793120 4452793152
4452793152 4452793120
```

这个例子是交换两个变量的数据。里面的原理是什么呢？

> 赋值语句的原理其实是。先分配一个小的内存给数值1，再给a变量分配一个小内存。=号表示让a内存存放1的地址。下次要直接使用a时，就是访问里面的地址。所以在a,b中表示先使用两个的地址。b,a 只是切换了他们指向的地址

所以，变量名字只是用来维护地址的，等号表示切换他们的指向的地址而已，所以在python中，节点之间相连，直接使用=即可

现在知道为什么要使用类对象了嘛？

> 其实列表也是一种类方法，这个类方法就是一个可变类型的容器。然后列表可以append，remove元素进去。总的来说，比如我们要定义人这一类。我们对这个工具人一类添加的方法越多，这个人会的东西就越多。工具人使用的就越方便。
> 为什么要使用类对象呢？直接使用def func不香吗？对的，不香。方法看起来更散乱。当我们要使用某方法的时候，如果能一下就想到这个方法在这个类中，那使用起来总比定义一个散乱的，孤零零的函数方法管用。

```
class A:
    def __init__(self):
        self.count = 1

a = A()
b = a
print(id(a),id(b))
a.count += 1
print(a.count)
b.count += 1
print(a.count)

140343767444496 140343767444496
2
3

del a
# 只是不让a指向class A，但b还是指向A的
```

在py中创建一个链表，我们需要用到两个类方法。链表包括两个部分，一个是节点Node类，另一个是链表类,最基本的结构如下：

```
class Node:
    def __init__(self, element):
        self.element = element
        self.next = None


class UnOrderList:
    def __init__(self):
        self.head = None
```

补全一些后如下：

> 为什么要添加head呢？主要是因为如果单独创建一个node。没有变量来存储第一个node的地址，所以我们先使用head指向第一个node节点的地址

```python
class Node:
    def __init__(self, element):
        self.element = element
        self.next = None


class UnOrderList:
    def __init__(self, node=None):
        self.head = node


node = Node(100) # 创建一个节点 节点是 100 None
link_list = UnOrderList(node) # 让头节点指向这个节点，传入的是对象
# 先给head分配一个小空间，让head指向这个节点对象的小空间
```

现在需要做的就是丰富这两个类的方法了，让他们能做的方法多一些。


1. 判断链表是否为空

```
def isEmpty(self):
    return self.head is None # 这里不使用==是因为==只是判断两个内容是不是一样，is是判断两个地址是否一样
```

2. 求链表的长度

```
def length(self):
    count = 0 # count 进行计数
    cur = self.head # cur进行定位节点的位置,由于head先是指向100。所以cur也是指向100
    # 采用循环遍历的方式求节点的长度，循环终止的条件是cur指向None
    while cur is not None:
        count += 1 # 指向了100，所以要先进行加一
        # 再让cur指向下一个节点
        # 注意这里cur其实也是一个实例了，可以调用这个实例的类方法
        cur = cur.next  # 相当于使用的是node.next
        print(cur is node.next)#判断两个数是不是地址是一样的
    return count
```

3. 遍历整个链表

也就是我们现在不需要计数功能了，直接打印当前节点的位置即可

```
def travel(self):
    cur = self.head # 其实相当于node实例 cur=node
    while cur is not None:
        print(cur.element)
        cur = cur.next
```

4. 插入节点

使用append函数在链表的末尾插入节点

```
def append(self, item):
    node = Node(item) # 这里封装好，我们不需要客户自己定义node类，只要填入数据即可
    if self.isEmpty():
        self.head = node
        return
    cur = self.head
    while cur.next is not None: # 必须循环到末尾再添加节点，循环结束条件是next指向None
        cur = cur.next
    cur.next = node # 让链表最后的next，指向新的节点
```

5. 在头节点插入元素

- 先用cur暂时存放第一个node节点
- 先打断头节点的位置，让头节点指向新node

```
def add(self, item):
    node = Node(item)
    cur, self.head = self.head, node
    node.next = cur
```

- 这样更简单，直接用node指向self.head
- 再让head指向node

```
def add(self, item):
    node = Node(item)
    node.next = self.head
    self.head = node
```

> 我的疑问，我们每次都是使用函数来处理链表，函数不是新开辟一个内存，然后使用完后会释放，垃圾回收嘛？为什么链表还存在在那边呢？

道理没错，关键就在init里面，我们使用self.head=node,其中node是实例化后Node对象，我们剩下的操作，都是对这两个变量进行的，所以函数虽然被释放了，但操作保留在里面，从下面可以看出其实每个内存都是被指向的

```
print(link_list.head.next.next.next.element)
print(link_list.head.element)
```

6. 在任意位置插入元素

```
def insert(self, position, item):
    if position >= self.length():
        raise IndexError
    if position <= 0:
        return self.add(item)
    node = Node(item)
    cur = self.head
    for i in range(position-1):
        cur = cur.next
    node.next = cur.next
    cur.next = node
```

这里有个小插曲

```
print(link_list.travel())

# 输出  0 123 234 100 2 3 None
```

> 不是travel不会输出None嘛，怎么还是输出了None，原来是因为我又print了一下，travel函数无返回，默认是None，所以最后打印了None

7. 链表的反转

假如现在有个链表，如下：

```
1 -> 2 -> 3 -> None
```
思路：先创建一个None, 然后循环遍历每个节点，从1开始，next是None，然后2的next是
1和None这个链表，其余的如法炮制.

```
def reverse(self):
    cur = self.head
    pre = None
    while cur:
        # cur, pre, cur.next= cur.next, cur, pre
        cur.next, pre, cur = pre, cur, cur.next
    self.head = pre
```

另一种比较好理解的写法：

```
    def reverse(self):
        cur = self.head
        pre = None
        while cur is not None:
            temp = cur
            cur = cur.next
            temp.next = pre
            pre = temp
        self.head = pre
```

8. 查找节点

调试的代码，不用每次都自己写链表，具备最基本的几个函数

```
class Node:
    def __init__(self, item):
        self.val = item
        self.next = None


class Linklist:
    def __init__(self, node):
        self.head = node

    def append(self, item):
        cur = self.head
        node = Node(item)
        while cur.next:
            cur = cur.next
        cur.next = node

    def travel(self):
        cur = self.head
        while cur:
            print(cur.val, end=' ')
            cur = cur.next
```

```
def search(self, item):
    cur = self.head
    while cur:
        if cur.val == item:
            return True
        cur = cur.next
    return False
```

