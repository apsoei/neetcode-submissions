class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False
        cnt1 = Counter(s1)

        counts = defaultdict(int)
        j = 0
        for i in range(len(s2)):
            if s2[i] not in cnt1:
                counts.clear()
                j = i + 1
                continue
            counts[s2[i]] += 1

            if i - j + 1 == len(s1):
                if len(cnt1) == len(counts):
                    valid = True
                    for k, v in cnt1.items():
                        if counts[k] != v:
                            valid = False
                    if valid:
                        return True
                counts[s2[j]] -= 1
                j += 1

        return False
            