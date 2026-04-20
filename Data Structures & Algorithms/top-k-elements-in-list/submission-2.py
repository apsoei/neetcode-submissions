import heapq as hq
from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)

        h = []
        for key, val in counts.items():
            hq.heappush(h, (val, key))

            if len(h) > k:
                hq.heappop(h)
        
        res = []
        while h:
            val, key = hq.heappop(h)
            res.append(key)
        
        return res
        