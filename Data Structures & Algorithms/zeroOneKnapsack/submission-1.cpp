class Solution 
{
public:
    // int dp(vector<int>& profit, vector<int>& weight, vector<vector<int>>& memo, int& capacity, int& count, int i)
    // {
    //     if (i == profit.size())
    //     {
    //         return 0;
    //     }

    //     if (memo[i][count] != -1)
    //     {
    //         return memo[i][count];
    //     }

    //     // take or skip
    //     int take = 0;
    //     if (capacity >= weight[i])
    //     {
    //         capacity -= weight[i];
    //         count++;
    //         take = profit[i] + dp(profit, weight, memo, capacity, count, i + 1);
    //         capacity += weight[i];
    //         count--;
    //     }

    //     int skip = dp(profit, weight, memo, capacity, count, i + 1);

    //     memo[i][count] = max(take, skip);

    //     return memo[i][count];
    // }
    int dp(vector<int>& profit, vector<int>& weight, vector<vector<int>>& memo, int& capacity, int i)
    {
        if (i == profit.size())
        {
            return 0;
        }

        if (memo[i][capacity] != -1)
        {
            return memo[i][capacity];
        }

        // take or skip
        int take = 0;
        if (capacity >= weight[i])
        {
            capacity -= weight[i];
            take = profit[i] + dp(profit, weight, memo, capacity, i + 1);
            capacity += weight[i];
        }

        int skip = dp(profit, weight, memo, capacity, i + 1);

        memo[i][capacity] = max(take, skip);

        return memo[i][capacity];
    }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) 
    {
        int n = profit.size();
        vector<vector<int>> memo(profit.size(), vector<int>(capacity + 1, -1));
        // int count = 0;

        return dp(profit, weight, memo, capacity, 0);
    }
};
