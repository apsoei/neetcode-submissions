class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        buckets = defaultdict(list)

        for s in strs:
            copy = "".join(sorted(s))
            buckets[copy].append(s)
        
        res = []
        for k, v in buckets.items():
            res.append(v)
        return res