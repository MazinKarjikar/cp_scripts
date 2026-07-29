#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
public:
    function<T(T,T)> combine;
    T identity;
    vector<vector<T>> levels, lazy;
    int n;
    bool is_sum, add_ok;

    SegmentTree(const vector<T>& a, string op) : n(a.size()) {
        assert(n);

        is_sum = op == "SUM";
        add_ok = is_sum || op == "MIN" || op == "MAX";

        if (op == "SUM")
            combine = [](T a, T b) { return a + b; },
            identity = T{};
        else if (op == "MIN")
            combine = [](T a, T b) { return min(a, b); },
            identity = numeric_limits<T>::max();
        else if (op == "MAX")
            combine = [](T a, T b) { return max(a, b); },
            identity = numeric_limits<T>::lowest();
        else if (op == "GCD")
            combine = [](T a, T b) { return gcd(a, b); },
            identity = T{};
        else if (op == "XOR")
            combine = [](T a, T b) { return a ^ b; },
            identity = T{};
        else
            assert(false);

        levels.push_back(a);

        while (levels.back().size() > 1) {
            auto& cur = levels.back();
            vector<T> next((cur.size() + 1) / 2);

            for (int i = 0; i < next.size(); i++)
                next[i] = 2 * i + 1 < cur.size()
                    ? combine(cur[2 * i], cur[2 * i + 1])
                    : cur[2 * i];

            levels.push_back(move(next));
        }

        lazy.resize(levels.size());
        for (int d = 0; d < levels.size(); d++)
            lazy[d].assign(levels[d].size(), T{});
    }

    void apply(int d, int i, T x) {
        long long l = 1LL * i << d;
        long long r = min<long long>(n, 1LL * (i + 1) << d);

        levels[d][i] += is_sum ? x * (r - l) : x;
        lazy[d][i] += x;
    }

    void push(int d, int i) {
        if (!d || lazy[d][i] == T{}) return;

        apply(d - 1, 2 * i, lazy[d][i]);

        if (2 * i + 1 < levels[d - 1].size())
            apply(d - 1, 2 * i + 1, lazy[d][i]);

        lazy[d][i] = T{};
    }

    void pull(int d, int i) {
        levels[d][i] = levels[d - 1][2 * i];

        if (2 * i + 1 < levels[d - 1].size())
            levels[d][i] = combine(
                levels[d][i],
                levels[d - 1][2 * i + 1]
            );
    }

    // inclusive [ql, qr]
    T query(int ql, int qr, int d = -1, int i = 0) {
        if (d == -1) {
            assert(0 <= ql && ql <= qr && qr < n);
            d = levels.size() - 1;
        }

        long long l = 1LL * i << d;
        long long r = min<long long>(n, 1LL * (i + 1) << d) - 1;

        if (qr < l || r < ql) return identity;
        if (ql <= l && r <= qr) return levels[d][i];

        push(d, i);

        T ans = query(ql, qr, d - 1, 2 * i);

        if (2 * i + 1 < levels[d - 1].size())
            ans = combine(
                ans,
                query(ql, qr, d - 1, 2 * i + 1)
            );

        return ans;
    }

    void range_add(int ql, int qr, T x, int d = -1, int i = 0) {
        if (d == -1) {
            assert(add_ok && 0 <= ql && ql <= qr && qr < n);
            d = levels.size() - 1;
        }

        long long l = 1LL * i << d;
        long long r = min<long long>(n, 1LL * (i + 1) << d) - 1;

        if (qr < l || r < ql) return;

        if (ql <= l && r <= qr) {
            apply(d, i, x);
            return;
        }

        push(d, i);

        range_add(ql, qr, x, d - 1, 2 * i);

        if (2 * i + 1 < levels[d - 1].size())
            range_add(ql, qr, x, d - 1, 2 * i + 1);

        pull(d, i);
    }

    void set(int p, T x, int d = -1, int i = 0) {
        if (d == -1) {
            assert(0 <= p && p < n);
            d = levels.size() - 1;
        }

        if (!d) {
            levels[0][i] = x;
            lazy[0][i] = T{};
            return;
        }

        push(d, i);

        int child = 2 * i + ((p >> (d - 1)) & 1);
        set(p, x, d - 1, child);

        pull(d, i);
    }
};