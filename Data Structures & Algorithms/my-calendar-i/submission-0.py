class SegmentTree:
    def __init__(self, L, R):
        self.L = L
        self.R = R
        self.val = 0
        self.left = None
        self.right = None
    
    def update(self, qL, qR):
        if qR < self.L or self.R < qL:
            return

        if self.L == self.R:
            self.val += 1
            return

        mid = (self.L + self.R) // 2
        
        if not self.left:
            self.left = SegmentTree(self.L, mid)
        if not self.right:
            self.right = SegmentTree(mid + 1, self.R)
        
        self.left.update(qL, qR)
        self.right.update(qL, qR)

        self.val = max(self.left.val, self.right.val)
    
    def query(self, qL, qR):
        if qR < self.L or self.R < qL:
            return 0
        
        if qL <= self.L and qR >= self.R:
            return self.val
        
        leftVal = self.left.query(qL, qR) if self.left else 0
        rightVal = self.right.query(qL, qR) if self.right else 0
    
        return max(leftVal, rightVal)
        

class MyCalendar:
    
    def __init__(self):
        self.tree = SegmentTree(0, 1000000000)

    def book(self, startTime: int, endTime: int) -> bool:
        if not self.tree.query(startTime, endTime - 1):
            self.tree.update(startTime, endTime - 1)
            return True
        
        return False


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(startTime,endTime)