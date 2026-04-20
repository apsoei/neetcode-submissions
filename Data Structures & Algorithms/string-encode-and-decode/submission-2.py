class Solution:

    def encode(self, strs: List[str]) -> str:
        res = []
        for s in strs:
            res.append(s)
            res.append('ㅇ')
        
        return "".join(res)

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0

        while i < len(s):
            j = i
            while s[j] != 'ㅇ':
                j += 1
            res.append(s[i : j])
            i = j + 1
        
        return res
