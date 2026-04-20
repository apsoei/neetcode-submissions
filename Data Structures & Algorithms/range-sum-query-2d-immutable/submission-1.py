class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        rows = len(matrix)
        cols = len(matrix[0])
        self.prefixSum = [[0] * (cols + 1) for _ in range(rows + 1)]

        for r in range(rows):
            run = 0
            for c in range(cols):
                run += matrix[r][c]
                above = self.prefixSum[r][c + 1]
                self.prefixSum[r + 1][c + 1] = run + above

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        res = 0

        bottomRight = self.prefixSum[row2 + 1][col2 + 1]
        above = self.prefixSum[row1][col2 + 1]
        left = self.prefixSum[row2 + 1][col1]
        topLeft = self.prefixSum[row1][col1]

        return bottomRight - above - left + topLeft


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)