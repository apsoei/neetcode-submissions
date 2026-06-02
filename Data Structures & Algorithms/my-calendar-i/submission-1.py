class Tree:
    def __init__(self, L, R):
        self.L = L
        self.R = R
        self.val = 0
        self.lazy = 0
        self.left = None
        self.right = None
    
    def getLeft(self):
        if not self.left:
            mid = (self.L + self.R) // 2
            self.left = Tree(self.L, mid)
        return self.left
    
    def getRight(self):
        if not self.right:
            mid = (self.L + self.R) // 2
            self.right = Tree(mid + 1, self.R)
        return self.right
    
    def push(self):
        if self.lazy == 0:
            return
        left = self.getLeft()
        right = self.getRight()

        left.val += self.lazy
        left.lazy += self.lazy
        right.val += self.lazy
        right.lazy += self.lazy

        self.lazy = 0
    
    def query(self, qL, qR):
        if qR < self.L or self.R < qL:
            return 0
        
        if qL <= self.L and qR >= self.R:
            return self.val
        
        self.push()

        leftVal = self.getLeft().query(qL, qR)
        rightVal = self.getRight().query(qL, qR)

        return max(leftVal, rightVal)
    
    def update(self, qL, qR, delta):
        if qR < self.L or qL > self.R:
            return
        
        if qL <= self.L and qR >= self.R:
            self.lazy += delta
            self.val += delta
            return
        
        self.push()

        self.getLeft().update(qL, qR, delta)
        self.getRight().update(qL, qR, delta)

        self.val = max(self.left.val, self.right.val)

class MyCalendar:
    
    def __init__(self):
        self.tree = Tree(0, 1000000000)

    def book(self, startTime: int, endTime: int) -> bool:
        if self.tree.query(startTime, endTime - 1):
            return False
        
        self.tree.update(startTime, endTime - 1, 1)
        return True
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)