class Solution 
{
public:
    int shortestPath(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        queue<pair<int, int>> q;
        q.push({0, 0});

        int steps = 0;
        while (!q.empty())
        {
            int len = q.size();
            while (len)
            {
                pair<int, int> p = q.front();
                int r = p.first;
                int c = p.second;
                q.pop();
                if (r == m - 1 && c == n - 1)
                {
                    return steps;
                }

                for (pair<int, int> d : dir)
                {
                    int dr = d.first;
                    int dc = d.second;
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }

                len--;
            }
            steps++;
        }


        return -1;
    }
};
