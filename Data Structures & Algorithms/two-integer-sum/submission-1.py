from collections import defaultdict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = defaultdict(int)

        for i, n in enumerate(nums):
            if target - n in seen:
                return [seen[target - n], i]
            if n not in seen:
                seen[n] = i
        
        return []