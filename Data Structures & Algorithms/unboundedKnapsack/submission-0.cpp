class Solution 
{
public:
    int dp(vector<int>& profit, vector<int>& weight, int& capacity, int i, vector<vector<int>>& cache)
    {
        if (i == profit.size())
        {
            return 0;
        }

        if (cache[i][capacity] != -1)
        {
            return cache[i][capacity];
        }

        // skip or take
        int skip = dp(profit, weight, capacity, i + 1, cache);
        int take = 0;
        if (capacity >= weight[i])
        {
            capacity -= weight[i];
            take = profit[i] + dp(profit, weight, capacity, i, cache);
            capacity += weight[i];
        }

        cache[i][capacity] = max(skip, take);

        return cache[i][capacity];
    }

    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) 
    {
        int n = profit.size();
        vector<vector<int>> cache(n, vector<int>(capacity + 1, -1));

        return dp(profit, weight, capacity, 0, cache);
    }
};
