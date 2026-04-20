class Solution 
{
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) 
    {
        unordered_set<int> visited;

        // node -> {other, w}
        unordered_map<int, vector<pair<int, int>>> mp;
        for (auto& e : edges)
        {
            mp[e[0]].push_back({e[1], e[2]});
            mp[e[1]].push_back({e[0], e[2]});
        }


        // {w, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> frontier;

        frontier.push({0, edges[0][0]});

        int res = 0;
        while (!frontier.empty() && visited.size() < n)
        {
            auto p = frontier.top();
            frontier.pop();
            int w = p.first;
            int node = p.second;

            if (visited.count(node))
            {
                continue;
            }

            visited.insert(node);
            res += w;
            // cout << w << endl;
            for (pair<int, int>& nei : mp[node])
            {
                int other = nei.first;
                int cost = nei.second;
                if (visited.count(other))
                {
                    continue;
                }

                frontier.push({cost, other});
            }
        }
        
        return visited.size() == n ? res : -1;
    }
};

