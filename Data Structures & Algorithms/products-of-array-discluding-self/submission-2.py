class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        left = [1] * n
        right = [1] * n

        for i in range(n - 1):
            left[i + 1] = left[i] * nums[i]
        
        for i in range(n - 1, 0, -1):
            right[i - 1] = right[i] * nums[i]
        
        res = []

        for i in range(n):
            res.append(left[i] * right[i])
        
        return res
