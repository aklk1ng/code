class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


class Tree:
    def __init__(self):
        self.root = None

    def RecursBST(self, node, val):
        if node is None:
            node = Node(val)
        elif self.root.data > val:
            node.left = self.RecursBST(node.left, val)
        elif self.root.data < val:
            node.right = self.RecursBST(node.right, val)

        return node

    def Insert(self, root, val):
        self.root = self.RecursBST(self.root, val)

    def InOrderTree(self, root):
        if root is None:
            print("None", end=" ")
        else:
            self.InOrderTree(root.left)
            print(root.data)
            self.InOrderTree(root.right)

    def Find(self, root, val):
        if root is None:
            print("the tree is empty!")
        elif root.data > val:
            return self.Find(root.left, val)
        elif root.data < val:
            return self.Find(root.right, val)
        else:
            return root

    def Find_Max(self, root):
        if root is None:
            print("this tree is empty!")
        elif root.right:
            return self.Find_Max(root.right)
        else:
            return root

    def Find_Min(self, root):
        if root is None:
            print("the tree is empty!")
        elif root.left:
            return self.Find_Min(root.left)
        else:
            return root

    def Delete(self, root, val):
        if root is None:
            print("the tree is empty!")
        if root.data > val:
            root.left = self.Delete(root.left, val)
        elif root.data < val:
            root.right = self.Delete(root.right, val)
        elif root.data == val:
            if root.left and root.right:
                tmp = self.Find_Min(root.right)
                root.data = tmp.data
                root.right = self.Delete(root, val)
            else:
                tmp = root
                if root.left is None:
                    root = root.right
                else:
                    root = root.left
        else:
            print("no this value")


if __name__ == "__main__":
    t = Tree()
    t.Insert(t.root, 1)
    t.Insert(t.root, 2)
    t.Insert(t.root, -1)
    t.Insert(t.root, 3)
    t.Insert(t.root, 5)
    t.InOrderTree(t.root)
    print("\n--------------------------------")
    t.Delete(t.root, 5)
    t.InOrderTree(t.root)
    print("\n--------------------------------")

    Max = t.Find_Max(t.root)
    print("Max:", Max.data)

    Min = t.Find_Min(t.root)
    print("Min:", Min.data)
