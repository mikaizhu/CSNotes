# 树的实现


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


    def breadth_travel(self):
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

    def preorder(self, node):
        # 根左右
        if node is None:
            return
        print(node.ele, end=' ')
        self.preorder(node.lchild)
        self.preorder(node.rchild)

    def inorder(self, node):
        if node is None:
            return
        self.inorder(node.lchild)
        print(node.ele, end=' ')
        self.inorder(node.rchild)

    def postorder(self, node):
        if node is None:
            return
        self.postorder(node.lchild)
        self.postorder(node.rchild)
        print(node.ele, end=' ')


t = Tree()
t.breadth_travel()
t.add(1)
t.add(2)
t.add(3)
t.add(4)
t.add(5)
t.add(6)
t.breadth_travel()
t.preorder(t.root)
print()
t.inorder(t.root)
print()
t.postorder(t.root)
print()
