class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = defaultdict(int)
        i = 0
        res = 0
        for j in range(len(s)):
            mp[ord(s[j]) - ord('a')] += 1
            if mp[ord(s[j]) - ord('a')] > 1:
                while i < j and s[i] != s[j]:
                    mp[ord(s[i]) - ord('a')] -= 1
                    i += 1
                mp[ord(s[i]) - ord('a')] -= 1
                i += 1
            res = max(res, j - i + 1)
        return res
                