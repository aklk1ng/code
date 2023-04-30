class Queue:
    def __init__(self):
        self.data = []
        self.size = 0

    def push(self, val):
        self.data.append(val)
        self.size += 1

    def pop(self):
        self.data = self.data[1:]
        self.size -= 1

    def print(self):
        for i in range(self.size):
            print(self.data[i], end=" ")
        print("\n")

    def get(self, index):
        return self.data[index]

    def empty(self):
        return self.data.__len__() == 0


if __name__ == "__main__":
    q = Queue()
    q.push(0)
    q.push(1)
    q.push(2)
    q.push(3)
    q.push(4)
    q.pop()
    q.print()
    print(q.empty())
