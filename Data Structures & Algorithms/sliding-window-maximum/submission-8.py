class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        dq = deque()
        res = []
        for j in range(len(nums)):
            while dq and nums[dq[-1]] <= nums[j]:
                dq.pop()
            dq.append(j)
            if j >= k - 1:
                res.append(nums[dq[0]])
                i = j - k + 1
                if dq[0] <= i:
                    dq.popleft()
        return res