class Node:
    def __init__(self, ele):
        self.ele = ele
        self.next = None

class List:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head is None

    def __len__(self):
        count = 0
        cur = self.head
        while cur is not None:
            count += 1
            cur = cur.next
        return count

    def travel(self):
        cur = self.head
        while cur is not None:
            print(cur.ele, end=' ')
            cur = cur.next

    def append(self, num):
        node = Node(num)
        if self.head is None:
            self.head = node
            return
        cur = self.head
        while cur.next is not None:
            cur = cur.next
        cur.next = node

    def add(self, num):
        node = Node(num)
        if self.head is None:
            self.head = node
            return
        node.next = self.head
        self.head = node

    def insert(self, pos, num):
        assert len(self) - 1 >= pos
        node = Node(num)
        if pos == 0 or self.isEmpty():
            self.add(num)
        else:
            cur = self.head
            for _ in range(pos-1):
                cur = cur.next
            node.next = cur.next
            cur.next = node

    def reverse(self):
        cur = self.head
        pre = None
        while cur is not None:
            temp = cur
            cur = cur.next
            temp.next = pre
            pre = temp
        self.head = pre




if __name__ == '__main__':
    node = Node(10)
    l = List()
    print(l.isEmpty())
    print(len(l))
    l.append(1)
    l.append(2)
    l.append(3)
    l.append(4)
    l.add(0)
    l.add(-1)
    l.travel()
    print()
    print(len(l))
    l.insert(1, 10)
    l.travel()
    l.reverse()
    print()
    l.travel()
