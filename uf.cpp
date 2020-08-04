class DisjointSet {
public:
    VI rank, p;

    DisjointSet() {}
    DisjointSet(int size) {
        rank.resize(size, 0);
        p.resize(size, 0);
        REP(i, size) p[i] = i;
    }

    void makeSet(int x) {
        p[x] = x;
        rank[x] = 0;
    }

    bool same(int x, int y) { return _findSet(x) == _findSet(y); }

    void unite(int x, int y) { _link(_findSet(x), _findSet(y)); }

private:
    void _link(int x, int y) {
        if (rank[x] > rank[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }

    int _findSet(int x) {
        if (x != p[x]) {
            p[x] = _findSet(p[x]);
        }
        return p[x];
    }
};
