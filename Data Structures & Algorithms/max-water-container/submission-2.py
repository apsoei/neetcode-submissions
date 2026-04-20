class Solution:
    def maxArea(self, heights: List[int]) -> int:
        L = 0
        R = len(heights) - 1
        res = 0
        while L < R:
            res = max(res, (R - L) * min(heights[R], heights[L]))
            if heights[R] >= heights[L]:
                L += 1
            else:
                R -= 1

        return res