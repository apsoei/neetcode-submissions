class Solution 
{
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& edges) 
    {
        vector<int> res;

        unordered_map<int, vector<int>> mp;
        vector<int> indegrees(n, 0);
        for (auto& e : edges)
        {
            mp[e[0]].push_back(e[1]);
            indegrees[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; ++i)
        {
            if (indegrees[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty() && res.size() < n)
        {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for (int& nei : mp[node])
            {
                if (--indegrees[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        return res.size() == n ? res : vector<int>();
    }
};
