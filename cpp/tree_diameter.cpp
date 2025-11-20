#include <vector>
#include <array>
using namespace std;

vector<vector<int>> adj;

auto diameter_center = [&](int root) -> pair<array<int,3>, pair<int,int>> {
    // returns the two leaf nodes representing the diameter of the tree
    array<int,3> ans = {-1, -1, -1};
    int max_dist = -1;
    int max_node = -1;

    vector<int> p(adj.size(), -1);

    auto dfs = [&](int u, int par, int d, auto&& dfs, bool findCenter = false) -> void { // find furthest node from node 0
        if (findCenter) p[u] = par;
        if (d > max_dist) {max_dist = d; max_node = u;}
        for(auto v: adj[u]) if(v != par) dfs(v, u, d+1, dfs, findCenter);
    };

    for(int i = 0; i < 2; i++) {
        dfs(root, -1, 0, dfs, i);
        ans[i] = max_node;
        ans[2] = max_dist;
        root = max_node;
        max_node = -1;
        max_dist = -1;
    }

    pair<int,int> center = {-1, -1};

    int curr = max_node;
    for(int i = 0; i < max_dist / 2; i++) curr = p[curr];
    center.first = curr;
    if (max_dist % 2 == 1) center.second = p[curr];


    return {ans, center};
};