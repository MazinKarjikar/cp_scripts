#include<bits/stdc++.h>
using namespace std;

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
    ll mpow(ll base, ll exp) {
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
      return mpow(base, mod - 2);
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