#include<bits/stdc++.h>
using namespace std;

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define sz(x) (int)(x).size()
#define mp(x, y) make_pair((x), (y))
#define pb push_back
#define eb emplace_back
#define INF (1LL<<61)

void print(auto v) { for(auto x: v) cout << x << " "; cout << endl; }
void NO() { cout << "NO" << endl; }
void YES() { cout << "YES" << endl; }
void readv(auto& v) { for(auto& x: v) cin >> x; }
void readadj(auto& adj) {
    for(int i = 0; i < sz(adj)-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

void SOLVE(){
    int n; cin >> n;
    vi a(n); readv(a);

}

signed main() {
    fastio
    int T = 1;
    cin >> T;
    while(T--) SOLVE();
}
