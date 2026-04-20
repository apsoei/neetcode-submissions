class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        lefts = [0] * n
        rights = [0] * n

        for i in range(1, n):
            lefts[i] = max(lefts[i - 1], height[i - 1])
        for i in range(n - 2, -1, -1):
            rights[i] = max(rights[i + 1], height[i + 1])
        
        res = 0

        for i in range(1, n - 1):
            res += max(0, min(lefts[i], rights[i]) - height[i])
        return res