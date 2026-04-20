import heapq

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        maxHeap = []
        res = []
        i = 0
        for j in range(len(nums)):
            heapq.heappush(maxHeap, (-nums[j], j))
            if j - i + 1 == k:
                res.append(-maxHeap[0][0])
                while maxHeap and maxHeap[0][1] <= i:
                    heapq.heappop(maxHeap)
                i += 1
        return res