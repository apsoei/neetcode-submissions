class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        count = 0

        i, j = 0, len(nums) - 1

        while i < j:
            while j >= 0 and nums[j] == val:
                j -= 1
            if i >= j:
                break
            
            if nums[i] == val:
                nums[i], nums[j] = nums[j], nums[i]
                j -= 1
            
            i += 1


        while nums and nums[-1] == val:
            nums.pop()
        
        return len(nums)