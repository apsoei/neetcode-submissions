import heapq as hq
from collections import Counter

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # counts = Counter(nums)

        # h = []
        # for key, val in counts.items():
        #     hq.heappush(h, (val, key))

        #     if len(h) > k:
        #         hq.heappop(h)
        
        # res = []
        # while h:
        #     val, key = hq.heappop(h)
        #     res.append(key)
        
        # return res
        
        counts = Counter(nums)
        freq = [[] for i in range(len(nums) + 1)]

        for key, val in counts.items():
            freq[val].append(key)
        
        res = []

        for i in range(len(freq) - 1, 0, -1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res