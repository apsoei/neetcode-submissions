class Solution 
{
public:
    // int dp(vector<int>& profit, vector<int>& weight, vector<vector<int>>& memo, int& capacity, int i)
    // {
    //     if (i == profit.size())
    //     {
    //         return 0;
    //     }

    //     if (memo[i][capacity] != -1)
    //     {
    //         return memo[i][capacity];
    //     }

    //     // take or skip
    //     int take = 0;
    //     if (capacity >= weight[i])
    //     {
    //         capacity -= weight[i];
    //         take = profit[i] + dp(profit, weight, memo, capacity, i + 1);
    //         capacity += weight[i];
    //     }

    //     int skip = dp(profit, weight, memo, capacity, i + 1);

    //     memo[i][capacity] = max(take, skip);

    //     return memo[i][capacity];
    // }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) 
    {
        // TOP-DOWN DP
        // Time: O(n * capacity)
        // Space: O(n * capacity)

        // int n = profit.size();
        // vector<vector<int>> memo(profit.size(), vector<int>(capacity + 1, -1));
        // // int count = 0;

        // return dp(profit, weight, memo, capacity, 0);

        // BOTTOM-UP DP
        // Time: O(n * capacity)
        // Space: O(n * capacity)

        // int n = profit.size();
        // vector<vector<int>> cache(n, vector<int>(capacity + 1, 0));

        // for (int c = 0; c <= capacity; ++c)
        // {
        //     if (weight[0] <= c)
        //     {
        //         cache[0][c] = profit[0];
        //     }
        // }

        // for (int i = 1; i < n; ++i)
        // {
        //     for (int c = 0; c <= capacity; ++c)
        //     {
        //         int skip = cache[i - 1][c];
        //         int include = 0;
        //         if (weight[i] <= c)
        //         {
        //             include = profit[i] + cache[i - 1][c - weight[i]];
        //         }

        //         cache[i][c] = max(skip, include);
        //     }
        // }

        // return cache[n - 1][capacity];

        // BOTTOM-UP DP
        // Time: O(n * capacity)
        // Space: O(capacity)

        int n = profit.size();
        vector<int> cache(capacity + 1, 0);
        for (int c = 0; c <= capacity; ++c)
        {
            if (weight[0] <= c)
            {
                cache[c] = profit[0];
            }
        }

        for (int i = 1; i < n; ++i)
        {
            vector<int> temp(capacity + 1, 0);
            for (int c = 0; c <= capacity; ++c)
            {
                int skip = cache[c];
                int take = 0;
                if (weight[i] <= c)
                {
                    take = profit[i] + cache[c - weight[i]];
                }

                temp[c] = max(skip, take);
            }

            cache = temp;
        }

        return cache[capacity];
    }
};
