#include <bits/stdc++.h>
using namespace std;

// Tree with Dist, LCA, and kth Ancestor. All are Log N queries.
struct Tree {
    int n, LOG;
    vector<vector<int>> adj;
    vector<vector<int>> up; // up[u][k] = 2^k-th ancestor of u
    vector<int> depth;

    Tree(int n) : n(n), adj(n), depth(n, 0) {
        LOG = __lg(n) + 1;
        up.assign(n, vector<int>(LOG, 0));
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Call this once after adding all edges. Depth[u] and up[u][k] gets built.
    void build(int root = 0) {
        up[root][0] = root;
        auto dfs = [&](int u, int p, int d, auto&& dfs) -> void {
            depth[u] = d;
            up[u][0] = p;
            for (int v : adj[u]) {
                if (v != p) dfs(v, u, d + 1, dfs);
            }
        };
        dfs(root, root, 0, dfs);

        for (int k = 1; k < LOG; k++) {
            for (int u = 0; u < n; u++) {
                up[u][k] = up[up[u][k - 1]][k - 1];
            }
        }
    }

    // Returns the k-th ancestor of u, or root if k exceeds depth
    int kth_ancestor(int u, int k) {
        for (int i = 0; i < LOG; i++) {
            if ((k >> i) & 1) {
                u = up[u][i];
            }
        }
        return u;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        u = kth_ancestor(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[u][k] != up[v][k]) {
                u = up[u][k];
                v = up[v][k];
            }
        }
        return up[u][0];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
};