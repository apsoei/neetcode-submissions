class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        counts = [0] * 3

        for num in nums:
            counts[num] += 1
        
        idx = 0
        for i in range(3):
            while counts[i]:
                nums[idx] = i
                idx += 1
                counts[i] -= 1
