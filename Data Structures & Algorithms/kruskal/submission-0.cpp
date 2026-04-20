class Solution 
{
public:
    int _find(int node, vector<int>& parents)
    {
        while (node != parents[node])
        {
            parents[node] = parents[parents[node]];
            node = parents[node];
        }

        return node;
    }

    bool _union(int n1, int n2, vector<int>& parents, vector<int>& ranks)
    {
        int p1 = _find(n1, parents);
        int p2 = _find(n2, parents);

        if (p1 == p2) return false;

        if (ranks[p1] > ranks[p2])
        {
            parents[p2] = p1;
            ranks[p1] += ranks[p2];
        }
        else
        {
            parents[p1] = p2;
            ranks[p2] += ranks[p1];
        }

        return true;
    }

    int minimumSpanningTree(vector<vector<int>>& edges, int n) 
    {
        vector<int> ranks(n, 1);
        vector<int> parents(n);
        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }

        auto compare = [](vector<int>& a, vector<int>& b)
        {
            return a[2] < b[2];
        };

        sort(edges.begin(), edges.end(), compare);

        int res = 0;
        int numComponents = n;
        for (auto& e : edges)
        {
            if (_union(e[0], e[1], parents, ranks))
            {
                res += e[2];
                numComponents--;
            }
        }
        

        return numComponents == 1 ? res : -1;
    }
};
