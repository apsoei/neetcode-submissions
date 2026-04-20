class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0 

        s = set(nums)

        for num in nums:
            if num - 1 in s:
                continue
            val = num
            curr = 0
            while val in s:
                curr += 1
                val += 1
            res = max(res, curr)
        
        return res
