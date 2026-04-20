class Solution 
{
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& m, int& n, int& res)
    {
        if (r == m - 1 && c == n - 1)
        {
            res++;
            return;
        }

        if (r >= m || c >= n || r < 0 || c < 0 || grid[r][c] == 1)
        {
            return;
        }

        grid[r][c] = 1;
        dfs(grid, r + 1, c, m, n, res);
        dfs(grid, r - 1, c, m, n, res);
        dfs(grid, r, c + 1, m, n, res);
        dfs(grid, r, c - 1, m, n, res);
        grid[r][c] = 0;
    }
    int countPaths(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid.front().size();
        if (grid[m - 1][n - 1] == 1) return 0;
        int res = 0;

        dfs(grid, 0, 0, m, n, res);

        return res;
    }
};
