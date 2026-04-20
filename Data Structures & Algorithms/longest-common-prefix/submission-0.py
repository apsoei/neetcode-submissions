class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        i = 0
        while True:
            for j in range(len(strs)):
                if i == len(strs[j]) or (j > 0 and strs[j - 1][i] != strs[j][i]):
                    return strs[j][:i]
            i += 1
        return ""
        