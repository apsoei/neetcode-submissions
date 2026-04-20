class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums.sort()
        # store longest sequence ending with i
        record = defaultdict(int)
        res = 0
        for num in nums:
            res = max(res, 1 + record[num - 1])
            record[num] = record[num - 1] + 1
        return res