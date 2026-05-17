#include<bits/stdc++.h>
using namespace std;

// from_string and from_ints initialize a PolyHash on that input.

long long powmod(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}

const long long PMOD = 1e9 + 9;
const pair<long long,long long> PS_STR = {31, 37};
const pair<long long,long long> PS_INT = {100237, 199777};

struct PolyHash {
    int n;
    array<vector<long long>, 2> pre, pw, pi;

    PolyHash(const vector<long long>& a, pair<long long,long long> ps) {
        n = a.size();
        for (int h = 0; h < 2; h++) {
            long long p = h == 0 ? ps.first : ps.second;
            long long p_inv = powmod(p, PMOD - 2, PMOD);
            pre[h].assign(n + 1, 0);
            pw[h].assign(n + 1, 1);
            pi[h].assign(n + 1, 1);
            for (int i = 0; i < n; i++) {
                pre[h][i + 1] = (pre[h][i] + a[i] % PMOD * pw[h][i]) % PMOD;
                pw[h][i + 1] = pw[h][i] * p % PMOD;
                pi[h][i + 1] = pi[h][i] * p_inv % PMOD;
            }
        }
    }

    pair<long long,long long> query(int i, int j) {
        auto get = [&](int h) {
            return (pre[h][j + 1] - pre[h][i] + PMOD) % PMOD * pi[h][i] % PMOD;
        };
        return {get(0), get(1)};
    }
};

PolyHash from_string(const string& s) {
    vector<long long> a(s.size());
    for (int i = 0; i < (int)s.size(); i++)
        a[i] = s[i] - 'a' + 1;
    return PolyHash(a, PS_STR);
}

PolyHash from_ints(const vector<int>& v) {
    vector<long long> a(v.size());
    for (int i = 0; i < (int)v.size(); i++)
        a[i] = v[i] + 1;
    return PolyHash(a, PS_INT);
}