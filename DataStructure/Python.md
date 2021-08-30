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

# 树

参考视频：https://www.bilibili.com/video/BV1NZ4y1M7wo

## 树的基本概念

树是由一个根节点和多个子节点组成， 每个子节点只能有一个父节点，常用术语如下：

- 节点的度：一个节点含有的子数的个数，叫做该节点的度
- 树的度：一棵树中，最大的节点的度称做树的度
- 叶子节点：度为0的节点
- 父节点：如果一个节点含有子节点，那么这个节点叫子节点的父节点
- 子节点
- 兄弟节点
- 节点的层次：从根节点开始，根为第一层，根的子节点为第二层
- 树的高度或者深度，也就是最大的层数
- 堂兄弟节点：父节点再同一层的节点互为堂兄弟
- 节点的祖先：从根到该节点，经过的所有节点，都是该节点的祖先

树的种类有：

- 无序树：树中任意节点的子节点之间没有顺序关系
- 有序树：树中的任意节点的子节点之间有顺序关系，这种称为有序树(从左到右读取数
  据，子节点，父节点，子节点的顺序)
  - 二叉树：每个节点最多含有两个子树的树称为二叉树，注意是最多含有两个子树
  - 完全二叉树：除了最底层，其他层的度都应该是2
  - 满二叉树：全部层，包括底层的节点的度，都应该是2
  - 平衡二叉树：每个节点的子树的层，最大不能超过1
  - 排序二叉树：凡是在根左边的树，都比根节点小。就像二分法一样

还有其他类型的树，如霍夫曼树，B树等.

树的代码实现：使用链表的方式实现

## 二叉树的实现

1. 广度优先遍历(按层次，从左到右依次读取数据)

首先是添加元素到树中，思想就是一层一层从左到右遍历，先判断当前节点的左节点有没
有值，有值就添加到队列中，没有就将节点链接到当前位置, 不断寻找，找到就退出

```
class Node: # 二叉树的节点
    def __init__(self, ele):
        self.ele = ele
        self.lchild = None
        self.rchild = None

class Tree:
    def __init__(self):
        self.root = None

    def add(self, item):
        node = Node(item)
        # 首先直接判断根节点有没有元素, 没有就直接添加进去
        if self.root is None:
            self.root = node
            return

        # 如果有，就一直寻找，先把不是空的节点添加到队列中
        # 找到了就退出循环
        queue = [self.root] # 存放待寻找的对象
        while queue:
            cur_node = queue.pop(0)
            if cur_node.lchild is None:
                cur_node.lchild = node
                return # 直接return 是因为add方法直接添加进去就好了
            queue.append(cur_node.lchild)
            if cur_node.rchild is None:
                cur_node.rchild = node
                return
            queue.append(cur_node.rchild)


    def breadth_travel(self): # 广度遍历
        res = []
        queue = [self.root]
        if self.root is None:
            return
        while queue:
            cur_node = queue.pop(0)
            res.append(cur_node.ele)
            if cur_node.lchild is not None:
                queue.append(cur_node.lchild)
            if cur_node.rchild is not None:
                queue.append(cur_node.rchild)
        print(res)


t = Tree()
t.breadth_travel()
t.add(1)
t.add(2)
t.add(3)
t.breadth_travel()
```
(假设现在有1 2 3 4 5 6, 可以先在图纸上画出这棵树)

广度遍历：什么是树的广度遍历？ 我们知道树是一层一层组成的，如果我们使用从左往右，按一层一层打印出东西来，那么这就是广度遍历

1, 2 , 3, 4, 5, 6

深度遍历：

- 先序遍历
- 中序遍历
- 后序遍历

1. 先序遍历

> 根，左，右


画出树，按根左右顺序来看，首先整体是一颗树，根是1， 所以先输出1, 处理完根后，处理左边， 然后左边是2为根的子树，再输出2，然后输出左边4，右边5，回过头发现以1为根的树处理完，只要处理右边即可，如法炮制，可以打印出3，6，7那么先序遍历打印出来的结果就是

1, 2, 4, 5, 3, 6

2. 中序遍历

> 左，根，右

树同上面一样，按左根右的顺序打印，1为根，左边是2为根的子树，左节点是4，所以先
打印4，然后是2，最后是5，到此左树处理完了，然后打印1为根的，最后处理右边，那么以根节点在中间，所以打印顺序如下：

4, 2, 5, 1, 6, 3

3. 后序遍历

同上，按左右根的顺序打印，处理到4，然后输出5， 最后输出2， 然后处理右树， 6， 7， 3， 1根节点最后打印

4, 5, 2, 6, 3, 1

总结：所以看根打印的顺序分为先中后这三个顺序
