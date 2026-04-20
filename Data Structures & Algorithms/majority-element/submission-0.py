class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        cnts = defaultdict(int)

        for num in nums:
            cnts[num] += 1
            if cnts[num] > len(nums) / 2:
                return num
        
        return -1

