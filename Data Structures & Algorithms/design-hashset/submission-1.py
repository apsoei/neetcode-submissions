class ListNode:
    def __init__(self, key: int):
        self.key = key
        self.next = None

class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
    
class BST:
    def __init__(self):
        self.root = None

    def search(self, root, key):
        if not root:
            return False
        if key == root.key:
            return True
        if key < root.key:
            return self.search(root.left, key)
        return self.search(root.right, key)
    
    def insert(self, root, key):
        if not root:
            return TreeNode(key)
        if key < root.key:
            root.left = self.insert(root.left, key)
        elif key > root.key:
            root.right = self.insert(root.right, key)
        return root
    
    def delete(self, root, key):
        if not root:
            return None
        if key < root.key:
            root.left = self.delete(root.left, key)
        elif key > root.key:
            root.right = self.delete(root.right, key)
        else:
            # deleting current node
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            temp = self.minValueNode(root.right)
            root.key = temp.key
            root.right = self.delete(root.right, temp.key)
        
    def minValueNode(self, root):
        while root.left:
            root = root.left
        return root
    
    def add(self, key):
        self.root = self.insert(self.root, key)
    
    def remove(self, key):
        self.root = self.delete(self.root, key)
    
    def contains(self, key):
        return self.search(self.root, key)


class MyHashSet:

    def __init__(self):
        self.size = 10000
        self.buckets = [BST() for _ in range(self.size)]

    def _hash(self, key):
        return key % self.size

    def add(self, key: int) -> None:
        idx = self._hash(key)
        self.buckets[idx].add(key)

    def remove(self, key: int) -> None:
        idx = self._hash(key)
        self.buckets[idx].remove(key)

    def contains(self, key: int) -> bool:
        idx = self._hash(key)
        return self.buckets[idx].contains(key)

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)