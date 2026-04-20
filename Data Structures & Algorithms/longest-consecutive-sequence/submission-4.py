class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
            
        s = set(nums)

        res = 1
        for k in s:
            if (k + 1) in s:
                continue
            # this k is the largest among distinct ranges of numbers (it does not have immediate value above)
            length = 1
            while (k - length) in s:
                length += 1
            res = max(res, length)
        return res
