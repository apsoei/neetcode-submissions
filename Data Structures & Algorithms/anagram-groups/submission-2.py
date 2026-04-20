from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)
        for st in strs:
            mp["".join(sorted(st))].append(st)
        
        return [v for v in mp.values()]
