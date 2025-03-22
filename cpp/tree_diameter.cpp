#include <vector>
using namespace std;

pair<int,int> diameter(auto adj, int root) {

    pair<int,int> ans = {-1, -1};
    int max_dist = -1;
    int max_node = -1;

    auto dfs = [&](int u, int par, int d, auto&& dfs) -> void { // find furthest node from node 0
        if (d > max_dist) {max_dist = d; max_node = u;}
        for(auto v: adj[u]) if(v != par) dfs(v, u, d+1, dfs);
    };

    dfs(root, -1, 0, dfs);
    ans.first = max_node;
    root = max_node;

    max_node = -1;
    max_dist = -1;
    dfs(root, -1, 0, dfs);
    ans.second = max_node;

    return ans;

}