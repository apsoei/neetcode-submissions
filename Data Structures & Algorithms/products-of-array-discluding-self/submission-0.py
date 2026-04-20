class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        leftProducts = [1] * n
        rightProducts = [1] * n
        for i in range(1, n):
            leftProducts[i] *= nums[i - 1] * leftProducts[i - 1]
        for i in range(n - 2, -1, -1):
            rightProducts[i] *= nums[i + 1] * rightProducts[i + 1]

        res = [0] * n
        for i in range(n):
            res[i] = leftProducts[i] * rightProducts[i]
        return res