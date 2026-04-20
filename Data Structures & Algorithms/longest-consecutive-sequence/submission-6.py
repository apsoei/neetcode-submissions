class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # s = set(nums)

        # res = 0
        # for k in s:
        #     if (k + 1) in s:
        #         continue
        #     # this k is the largest among distinct ranges of numbers (it does not have immediate value above)
        #     length = 1
        #     while (k - length) in s:
        #         length += 1
        #     res = max(res, length)
        # return res

        mp = defaultdict(int)
        res = 0
        for num in nums:
            if not mp[num]:
                mp[num] = mp[num - 1] + mp[num + 1] + 1
                mp[num - mp[num - 1]] = mp[num]
                mp[num + mp[num + 1]] = mp[num]
            res = max(res, mp[num])

        return res
