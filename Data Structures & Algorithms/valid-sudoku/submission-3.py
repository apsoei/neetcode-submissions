class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        h = [0] * 9
        v = [0] * 9
        s = [0] * 9

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == '.':
                    continue

                bit = 1 << int(val)

                if h[c] & bit != 0:
                    return False
                if v[r] & bit != 0:
                    return False
                if s[3 * (r // 3) + c // 3] & bit != 0:
                    return False
                h[c] |= bit
                v[r] |= bit
                s[3 * (r // 3) + c // 3] |= bit
        return True
        