class Solution:
    def isValid(self, s: str) -> bool:
        mp = {'(' : ')', '[' : ']', '{' : '}'}
        st = []
        for c in s:
            if c in mp:
                st.append(c)
            elif not st or mp[st[-1]] != c:
                return False
            else:
                st.pop()
        return not st