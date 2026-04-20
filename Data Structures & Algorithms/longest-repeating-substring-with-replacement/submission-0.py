import heapq

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        counts = [0] * 26
        i = 0
        res = 0

        for j in range(len(s)):
            counts[ord(s[j]) - ord('A')] += 1
            while sum(counts) - max(counts) > k:
                counts[ord(s[i]) - ord('A')] -= 1
                i += 1
            res = max(res, j - i + 1)
        return res
