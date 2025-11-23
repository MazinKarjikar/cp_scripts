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

using ll = long long;
const ll MOD = 1'000'000'007;

ll norm(ll x) {
    if (x < 0) x += MOD;
    if (x >= MOD) x -= MOD;
    return x;
}

template<class T>
T power(T a, long long b) {
    T res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

template<class T>
T inv(T a) { return power(a, MOD - 2); }

struct Z {
    ll x;
    Z(ll v = 0) {
        v %= MOD;
        if (v < 0) v += MOD;
        x = v;
    }

    ll val() const { return x; }

    Z operator-() const { return Z( MOD - x ); }

    Z inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }

    Z& operator*=(const Z &rhs) {
        x = (x * rhs.x) % MOD;
        return *this;
    }
    Z& operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z& operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z& operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }

    friend Z operator*(Z lhs, const Z &rhs) { return lhs *= rhs; }
    friend Z operator+(Z lhs, const Z &rhs) { return lhs += rhs; }
    friend Z operator-(Z lhs, const Z &rhs) { return lhs -= rhs; }
    friend Z operator/(Z lhs, const Z &rhs) { return lhs /= rhs; }
};

struct Fact {
    std::vector<Z> fact, ifact;
    bool built = false;

    void init(int n) {
        if (built && (int)fact.size() > n) return;
        built = true;

        fact.assign(n + 1, 1);
        ifact.assign(n + 1, 1);

        for (int i = 1; i <= n; i++)
            fact[i] = fact[i-1] * Z(i);

        ifact[n] = fact[n].inv();
        for (int i = n; i > 0; i--)
            ifact[i-1] = ifact[i] * Z(i);
    }

    Z nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        assert(built);
        return fact[n] * ifact[r] * ifact[n-r];
    }
};

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


// READ CAREFULLY
// LOOK TESTCASES
// REARRANGE EQUATIONS
signed main() {
    fastio
    int T = 1;
    cin >> T;
    while(T--) SOLVE();
}