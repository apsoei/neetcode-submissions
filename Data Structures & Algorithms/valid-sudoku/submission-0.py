class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # check horizontals
        for row in board:
            seen = set()
            for col in row:
                if col == '.':
                    continue
                if col in seen:
                    return False
                seen.add(col)
        print(1)
        # check verticals
        for col in range(9):
            seen = set()
            for row in range(9):
                if board[row][col] == '.':
                    continue
                if board[row][col] in seen:
                    return False
                seen.add(board[row][col])
        
        # check 3x3's
        for quad in range(9):
            r, c = 3 * (quad // 3), 3 * (quad % 3)
            seen = set()
            for nr in range(r, r + 3):
                for nc in range(c, c + 3):
                    if board[nr][nc] == '.':
                        continue
                    if board[nr][nc] in seen:
                        return False
                    seen.add(board[nr][nc])
        return True