class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        cols = len(matrix[0])
        self.prefixSum = [[0] * cols for _ in range(rows)]

        for r in range(rows):
            run = 0
            for c in range(cols):
                self.prefixSum[r][c] = run + matrix[r][c]
                run += matrix[r][c]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        res = 0

        for r in range(row1, row2 + 1):
            res += self.prefixSum[r][col2]
            if col1 > 0:
                res -= self.prefixSum[r][col1 - 1]

        return res


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)