class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        freq = [[] for _ in range(n + 1)]
        counts = Counter(nums)

        for v, cnt in counts.items():
            freq[cnt].append(v)
        res = []
        
        for i in range(n, -1, -1):
            for v in freq[i]:
                res.append(v)
                if len(res) == k:
                    return res
        return res
        