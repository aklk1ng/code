class Node:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None


class ListNode:
    def __init__(self, val):
        self.plist = Node(val)
        self.size = 1

    def insert(self, index, val):
        if index < 0 or index > self.size:
            return
        newnode = Node(val)
        cur = self.plist
        if index == 0:
            newnode.next = cur
            cur.prev = newnode
            newnode.prev = cur
            cur.next = newnode
            self.plist = newnode
        else:
            while index:
                cur = cur.next
                index -= 1
            pre = cur.prev
            pre.next = newnode
            newnode.prev = pre
            newnode.next = cur
            cur.prev = newnode
        self.size += 1

    def erase(self, index):
        if index < 0 or index > self.size:
            return
        elif index == 0:
            last = self.plist.prev
            next = self.plist.next
            next.prev = last
            last.next = next
            self.plist = next
        elif index == (self.size - 1):
            cur = self.plist.prev
            last = cur.prev
            last.next = self.plist
            self.plist.prev = last
        self.size -= 1

    def insert_head(self, val):
        self.insert(0, val)

    def insert_tail(self, val):
        self.insert(self.size, val)

    def erase_head(self):
        self.erase(0)

    def erase_tail(self):
        self.erase(self.size)

    def get(self, index):
        if index < 0 or index > self.size:
            return
        cur = self.plist
        while index:
            cur = cur.next
            index -= 1
        return cur.data

    def print(self):
        cur = self.plist
        for i in range(self.size):
            print(cur.data, end="->")
            cur = cur.next
        print("None")


if __name__ == "__main__":
    pl = ListNode(0)
    pl.insert_head(1)
    pl.insert_tail(2)
    pl.insert(3, 3)
    pl.print()
    pl.erase_tail()
    pl.print()
    pl.erase_head()
    pl.print()
    print(pl.get(3))
