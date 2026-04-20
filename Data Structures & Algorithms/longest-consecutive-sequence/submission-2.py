class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        nums.sort()
        streak = 0
        res = 0
        prev = nums[0] - 1
        i = 0
        while i < len(nums):
            if prev != nums[i] - 1:
                res = max(streak, res)
                streak = 1
            else:
                streak += 1
            prev = nums[i]
            while i + 1 < len(nums) and nums[i + 1] == prev:
                i += 1
            
            i += 1
        res = max(streak, res)
        
        return res