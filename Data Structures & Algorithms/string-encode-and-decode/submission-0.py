class Solution:

    def encode(self, strs: List[str]) -> str:
        encoded = []
        for s in strs:
            encoded.append(str(len(s)) + "#" + s)
        return "".join(encoded)

    def decode(self, s: str) -> List[str]:
        decoded = []
        i = 0
        n = len(s)
        while i < n:
            j = i
            while j < n and s[i: j + 1].isdigit():
                j += 1
            cnt = int(s[i:j])
            j += 1
            decoded.append(s[j : j + cnt])
            i = j + cnt
        return decoded
