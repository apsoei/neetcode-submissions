class UnionFind 
{
public:
    vector<int> ranks;
    vector<int> parents;
    int numComponents;
    UnionFind(int n) 
    {
        ranks = vector<int> (n, 1);
        parents = vector<int> (n);

        for (int i = 0; i < n; ++i)
        {
            parents[i] = i;
        }
        numComponents = n;
    }

    int find(int x) 
    {
        while (x != parents[x])
        {
            parents[x] = parents[parents[x]];
            x = parents[x];
        }

        return x;
    }

    bool isSameComponent(int x, int y) 
    {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) 
    {
        int px = find(x), py = find(y);

        if (px == py) return false;

        if (ranks[px] > ranks[py])
        {
            parents[py] = px;
            ranks[px] += ranks[py];
        }
        else
        {
            parents[px] = py;
            ranks[py] += ranks[px];
        }
        numComponents--;

        return true;
    }

    int getNumComponents() 
    {
        return numComponents;
    }
};
