class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False

        chars = [0] * 26

        for a, b in zip(s, t):
            chars[ord(a) - ord('a')] += 1
            chars[ord(b) - ord('a')] -= 1
        for i in range(26):
            if chars[i] != 0:
                return False
        return True