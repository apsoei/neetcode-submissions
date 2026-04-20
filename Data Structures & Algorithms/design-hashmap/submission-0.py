class Node:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, root, key, val):
        if not root:
            return Node(key, val)
        
        if root.key == key:
            root.val = val
        elif root.key < key:
            root.right = self.insert(root.right, key, val)
        else:
            root.left = self.insert(root.left, key, val)
        
        return root
    
    def get(self, root, key):
        if not root:
            return None
        
        if root.key < key:
            return self.get(root.right, key)
        if root.key > key:
            return self.get(root.left, key)
        
        return root

    def remove(self, root, key):
        if not root:
            return None
        
        if root.key < key:
            root.left = self.remove(root.left, key)
        elif root.key > key:
            root.right = self.remove(root.left, key)
        else:
            if not root.right:
                return root.left
            if not root.left:
                return root.right
            temp = self.minValueNode(root.right)
            root.key = temp.key
            root.val = temp.val
            root.right = self.delete(root.right, temp.key)
        return root
    
    def minValueNode(self, root):
        while root.left:
            root = root.left
        return root
            

class MyHashMap:

    def __init__(self):
        self.size = 10000
        self.buckets = [BST() for _ in range(self.size)]
    
    def _hash(self, key):
        return key % self.size

    def put(self, key: int, value: int) -> None:
        idx = self._hash(key)
        bst = self.buckets[idx]
        bst.root = bst.insert(bst.root, key, value)

    def get(self, key: int) -> int:
        idx = self._hash(key)
        bst = self.buckets[idx]
        found = bst.get(bst.root, key)
        if not found:
            return -1

        return found.val

    def remove(self, key: int) -> None:
        idx = self._hash(key)
        bst = self.buckets[idx]
        bst.root = bst.remove(bst.root, key)


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)