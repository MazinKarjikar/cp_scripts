#include <bits/stdc++.h>
using namespace std;

// -------------------- CENTROID DECOMP ---------------------
vector<vector<int>> adj;
vector<int> removed;
vector<int> subtreeSize;
vector<vector<int>> cdadj; // centroid decomp adj

int getSubtreeSize(int u, int p = -1) {
    subtreeSize[u] = 1;
    for(auto v: adj[u]) {
        if (v == p || removed[v]) continue;
        subtreeSize[u] += getSubtreeSize(v, u);
    }
    return subtreeSize[u];
}

int getCentroid(int u, int p, int treeSize) {
    for (auto v: adj[u]) {
        if (v == p || removed[v]) continue;
        if (2 * subtreeSize[v] > treeSize) return getCentroid(v, u, treeSize);
    }
    return u;
}

int buildCentroidDecomp(int u) {
    int centroid = getCentroid(u, -1, getSubtreeSize(u));
    removed[centroid] = 1;

    // do O(sz) computation for this tree (rooted at this centroid)
    // removed makes sure the centroid's component is self contained

    for(auto v: adj[centroid]) {
        if (removed[v]) continue;
        int child = buildCentroidDecomp(v);
        cdadj[centroid].push_back(child);
        cdadj[child].push_back(centroid);
    }

    return centroid;
}
// -------------------- CENTROID DECOMP ---------------------

int main(){

    // --------------USAGE---------------
    int n; cin >> n;
    adj = vector<vector<int>>(n);
    for(int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        adj[u-1].push_back(v-1); adj[v-1].push_back(u-1);
    }

    // construct centroid decompostion
    removed = vector<int>(n);
    subtreeSize = vector<int>(n);
    cdadj = vector<vector<int>>(n);
    int cdroot = buildCentroidDecomp(0); // root of centroid decomp tree

    // have centroidDecomp tree and its root.

    // --------------USAGE---------------

}