class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        n = len(nums)

        res = []
        for i in range(n):
            if i > 0 and nums[i - 1] == nums[i]:
                continue
            lo = i + 1
            hi = n - 1
            while lo < hi:
                currSum = nums[i] + nums[lo] + nums[hi]
                if currSum == 0:
                    res.append([nums[i], nums[lo], nums[hi]])
                    while lo + 1 < hi and nums[lo] == nums[lo + 1]:
                        lo += 1
                    while lo < hi - 1 and nums[hi] == nums[hi - 1]:
                        hi -= 1
                    lo += 1
                    hi -= 1
                elif currSum > 0:
                    hi -= 1
                else:
                    lo += 1
            
        return res
