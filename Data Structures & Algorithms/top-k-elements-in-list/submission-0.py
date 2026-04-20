class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = Counter(nums)

        heap = []
        for v, cnt in counts.items():
            heapq.heappush(heap, (cnt, v))
            if len(heap) > k:
                heapq.heappop(heap)
        
        return [heapq.heappop(heap)[1] for _ in range(k)]