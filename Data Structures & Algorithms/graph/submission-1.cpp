class Graph 
{
public:
    unordered_map<int, unordered_set<int>> mp;
    Graph() {}

    void addEdge(int src, int dst) 
    {
        mp[src].insert(dst);
    }

    bool removeEdge(int src, int dst) 
    {
        if (!mp.count(src)) return false;
        if (!mp[src].count(dst)) return false;

        mp[src].erase(dst);

        return true;
    }

    bool hasPath(int src, int dst) 
    {
        if (src == dst) return true;

        unordered_set<int> visited;
        return dfs(src, dst, visited);
    }

    bool dfs(int& curr, int& dst, unordered_set<int>& visited)
    {
        if (visited.count(curr))
        {
            return false;
        }

        if (curr == dst)
        {
            return true;
        }

        visited.insert(curr);
        for (int nei : mp[curr])
        {
            if (dfs(nei, dst, visited))
            {
                return true;
            }
        }
        // visited.erase(curr);

        return false;
    }
};
