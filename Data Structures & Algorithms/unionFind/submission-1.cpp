class UnionFind {
public:
    vector<int> rank;
    vector<int> par;
    int n;
    UnionFind(int n) {
        this->n = n;
        rank.resize(n);
        par.resize(n);
        for (int i = 0; i < n; ++i) {
            rank[i] = 1;
            par[i] = i;
        }
    }

    int find(int x) {
        if (x != par[x]) {
            par[x] = find(par[x]);
        }

        return par[x];
    }

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        int px = find(x), py = find(y);

        if (px == py) return false;

        if (rank[px] > rank[py]) {
            rank[px] += rank[py];
            par[py] = px;
        } else {
            rank[py] += rank[px];
            par[px] = py;
        }

        n--;

        return true;
    }

    int getNumComponents() {
        return n;
    }
};
