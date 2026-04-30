#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, rank;

    DSU(int n) : p(n), rank(n, 0) { iota(p.begin(), p.end(), 0); }

    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        p[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};