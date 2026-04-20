class Solution:
    def trap(self, height: List[int]) -> int:
        lh = height[0]
        rh = height[-1]
        L = 0
        R = len(height) - 1
        res = 0
        while L <= R:
            if lh < rh:
                lh = max(lh, height[L])
                res += lh - height[L]
                L += 1
            else:
                rh = max(rh, height[R])
                res += rh - height[R]
                R -= 1
        return res
