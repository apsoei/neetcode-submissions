class Solution 
{
public:
    void dfs(unordered_map<int, vector<pair<int, int>>>& mp, 
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>& minHeap,
            unordered_map<int, int>& res,
            int& n)
    {
        if (minHeap.empty())
        {
            return;
        }

        if (res.size() == n)
        {
            return;
        }

        auto p = minHeap.top();
        int curr = p.second;
        int w = p.first;
        minHeap.pop();
        if (!res.count(curr))
        {
            res[curr] = w;
            
            for (auto next : mp[curr])
            {
                int nei = next.first;
                int cost = next.second;
                if (!res.count(nei))
                {
                    minHeap.push({w + cost, nei});
                }
            }
        }

        dfs(mp, minHeap, res, n);
    }
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) 
    {
        // from -> {to, w}
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& e : edges)
        {
            mp[e[0]].push_back({e[1], e[2]});
        }

        unordered_map<int, int> res;

        // {w, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, src});

        dfs(mp, minHeap, res, n);

        if (res.size() < n)
        {
            for (int i = 0; i < n; ++i)
            {
                if (!res.count(i))
                {
                    res[i] = -1;
                }
            }
        }

        return res;
    }
};
