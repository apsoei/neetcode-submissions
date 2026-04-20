class Solution 
{
public:
    // int dp(vector<int>& profit, vector<int>& weight, int& capacity, int i, vector<vector<int>>& cache)
    // {
    //     if (i == profit.size())
    //     {
    //         return 0;
    //     }

    //     if (cache[i][capacity] != -1)
    //     {
    //         return cache[i][capacity];
    //     }

    //     // skip or take
    //     int skip = dp(profit, weight, capacity, i + 1, cache);
    //     int take = 0;
    //     if (capacity >= weight[i])
    //     {
    //         capacity -= weight[i];
    //         take = profit[i] + dp(profit, weight, capacity, i, cache);
    //         capacity += weight[i];
    //     }

    //     cache[i][capacity] = max(skip, take);

    //     return cache[i][capacity];
    // }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) 
    {
        // Top-down dp (n: profit size, m = capacity)
        // Time: O(n * m)
        // Space: O(n * m)
        // int n = profit.size();
        // vector<vector<int>> cache(n, vector<int>(capacity + 1, -1));

        // return dp(profit, weight, capacity, 0, cache);

        // Bottom-up dp (n: profit size, m = capacity)
        // Time: O(n * m)
        // Space: O(n * m)

        int n = profit.size();
        vector<vector<int>> cache(n, vector<int>(capacity + 1, 0));
        for (int c = 0; c <= capacity; ++c)
        {
            cache[0][c] = (c / weight[0]) * profit[0];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int c = 1; c <= capacity; ++c)
            {
                int skip = cache[i - 1][c];
                int take = 0;
                if (c >= weight[i])
                {
                    // take = profit[i] + cache[i - 1][c - weight[i]];
                    take = profit[i] + cache[i][c - weight[i]];
                }

                cache[i][c] = max(skip, take);
            }
        }

        return cache[n - 1][capacity];
    }
};
