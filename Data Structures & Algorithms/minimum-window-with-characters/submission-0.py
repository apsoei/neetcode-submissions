class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s):
            return ""

        cnt_s = defaultdict(int)
        cnt_t = Counter(t)
        
        matches = 52 - len(cnt_t)
        minLen = len(s) + 1
        res = (0, 0)
        j = 0
        for i in range(len(s)):
            val = s[i]
            cnt_s[val] += 1
            if cnt_s[val] == cnt_t[val]:
                matches += 1
            
            while matches == 52:
                if i - j + 1 < minLen:
                    minLen = i - j + 1
                    res = (j, i)
                    
                val = s[j]
                cnt_s[val] -= 1

                if cnt_s[val] + 1 == cnt_t[val]:
                    matches -= 1
                j += 1
                
        return s[res[0]: res[1] + 1] if minLen <= len(s) else ""
