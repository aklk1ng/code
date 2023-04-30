class Stack:
    def __init__(self):
        self.data = []
        self.size = 0

    def push(self, val):
        self.data.append(val)
        self.size += 1

    def pop(self):
        self.size -= 1

    def print(self):
        for i in range(self.size):
            print(f"{self.data[i]}", end=" ")
        print("\n")

    def get(self, index):
        return self.data[index]

    def capacity(self):
        return self.size


if __name__ == "__main__":
    s = Stack()
    s.push(0)
    s.push(1)
    s.push(2)
    s.push(3)
    s.push(4)
    s.pop()
    s.print()
    print(s.capacity())
