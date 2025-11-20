#include<bits/stdc++.h>
using namespace std;

// ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define fastio         ios_base::sync_with_stdio(0); cin.tie(0);
#define int            long long
#define pb             push_back
#define eb             emplace_back
#define f               first
#define s              second
#define vi             vector<int>
#define vvi            vector<vector<int>>
#define pii            pair<int,int>
#define vpii           vector<pair<int,int>>
#define sz(x)          (int)(x).size()
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define sor(x)         sort(all(x))
#define rsor(x)        sort(rall(x))
#define mp(x, y)       make_pair((x), (y))
#define INF            (1LL<<61)

#define getunique(v)   {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define popcount(x)    __builtin_popcountll(x)
#define lcm(a, b)      (a * (b / __gcd(a,b)) )
#define gcd(a, b)      __gcd(a,b)
#define maxz(a, b)     (a = max(a, b))
#define minz(a, b)     (a = min(a, b))
#define vmin(a)        (*min_element(a.begin(), a.end()))
#define vmax(a)        (*max_element(a.begin(), a.end()))
#define vsum(a)        accumulate(a.begin(), a.end(), 0LL)

int    strtoint(string s)     {istringstream ss(s);int n;ss>>n;return n;}
string inttostr(int x)         {string s;while(x){s+=(char)(x%10)+'0';x/=10;}reverse(all(s));return s;}


int mod = 1e9+7;
using ll = long long;

namespace modop {
    template<typename T>
    void add(T &a, ll b) {
        a += b;
        if (a >= mod) a -= mod;
    }
    template<typename T>
    void sub(T &a, ll b) {
        a -= b;
        if (a < 0) a += mod;
    }
    ll fastpow(ll base, ll exp) {
        base %= mod;
        ll res = 1;
        while (exp) {
            if (exp % 2 == 1){
                res = (res * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return res;
    }
    ll minv(ll base) {
        return fastpow(base, mod - 2);
    }
    inline ll mul(ll x) {
        return x;
    }
    template<typename... Args>
    inline ll mul(ll x, Args... rest) {
        return x * mul(rest...) % mod;
    }

    const ll FACTORIAL_SIZE = 2.1e6;
    ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
    bool __factorials_generated__ = 0;
    void gen_factorial(ll n) {
        __factorials_generated__ = 1;
        fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

        for (ll i = 2; i <= n; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        ifact[n] = minv(fact[n]);
        for (ll i = n - 1; i >= 2; i--) {
            ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
        }
    }
    ll nck(ll n, ll k) {
        if (!__factorials_generated__) {
            cerr << "Call gen_factorial you dope" << endl;
            exit(1);
        }
        if (k < 0 || n < k) return 0;
        ll den = (ifact[k] * ifact[n - k]) % mod;
        return (den * fact[n]) % mod;
    }
}
using namespace modop;

template <typename T>
void print(const T& v) { for(auto x: v) cout << x << " "; cout << endl; }
void YES() { cout << "YES" << endl; }
void NO() { cout << "NO" << endl; }
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }
void readv(auto& v) { for(auto& x: v) cin >> x; }
void readtree(auto& adj) {
    for(int i = 0; i < sz(adj)-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
// bool isIn(int r, int c, int R, int C) {
//     return r >= 0 and r < R and c >= 0 and c < C;
// }
// vector<pair<int,int>> dirs4 = {{1, 0},{0,1},{-1,0},{0,-1}};
// vector<pair<int,int>> dirs8 = {{1, 0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

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