class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        cols = [0] * 9
        rows = [0] * 9
        quads = [0] * 9

        for r in range(9):
            for c in range(9):
                val = board[r][c]
                if val == '.':
                    continue
                bit = 1 << int(val)
                if (bit & rows[r] or
                    bit & cols[c] or
                    bit & quads[3 * (r // 3) + c // 3]):
                    return False
                rows[r] |= bit
                cols[c] |= bit
                quads[3 * (r // 3) + c // 3] |= bit
        return True