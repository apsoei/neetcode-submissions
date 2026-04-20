class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        c1, c2 = [0] * 26, [0] * 26
        for i in range(len(s1)):
            c1[ord(s1[i]) - ord('a')] += 1
            c2[ord(s2[i]) - ord('a')] += 1
        
        matches = 0
        for i in range(26):
            matches += (1 if c1[i] == c2[i] else 0)
        
        L = 0
        for R in range(len(s1), len(s2)):
            if matches == 26:
                return True

            index = ord(s2[R]) - ord('a')
            c2[index] += 1
            if c1[index] == c2[index]:
                matches += 1
            elif c2[index] - 1 == c1[index]:
                matches -= 1
            
            index = ord(s2[L]) - ord('a')
            c2[index] -= 1
            if c1[index] == c2[index]:
                matches += 1
            elif c2[index] + 1 == c1[index]:
                matches -= 1
            L += 1

        return matches == 26
