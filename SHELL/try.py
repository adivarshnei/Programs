pages=[1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6]
class circularQueue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.queue = [None]*capacity
        self.tail = -1
        self.head = 0
        self.size = 0
    def Enqueue(self, item):
        if self.size == self.capacity:
            print("Error : Queue is Full")
        else:
            self.tail = (self.tail + 1) % self.capacity
            self.queue[self.tail] = item
            self.size = self.size + 1
    def Dequeue(self):
        if self.size == 0:
            print("Error : Queue is Empty")
            return
        else:
            tmp = self.queue[self.head]
            self.head = (self.head + 1) % self.capacity
        self.size = self.size - 1
        return tmp
    def display(self):
        print("----*----")
        if self.size == 0:
            print("Queue is Empty")
        else:
            index = self.head
            for index in range(self.size):
                print(self.queue[index])
                index = (index + 1) % self.capacity
        print("----*----")
    def isFull(self):
        if self.size == self.capacity:
            return True
        else:
            return False
    def exists(self, x):
        for i in range(self.size):
            if x == self.queue[i]:
                return True
        else:
            return False
fault = 0
q = circularQueue(3)
for i in pages:
    if not q.exists(i):
        fault = fault + 1
        if not q.isFull():
            q.Enqueue(i)
        elif q.isFull():
            q.Dequeue()
            q.Enqueue(i)
        q.display()
print("\n\n", fault)
