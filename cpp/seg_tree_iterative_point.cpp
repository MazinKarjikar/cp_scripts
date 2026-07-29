#include<bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
public:
    function<T(T,T)> combine;
    T identity;
    vector<vector<T>> levels;

    SegmentTree(const vector<T>& vec, string op) {
        assert(!vec.empty());

        if (op == "MAX") {
            combine = [](T a, T b) { return max(a,b); };
            identity = numeric_limits<T>::lowest();
        } else if (op == "MIN") {
            combine = [](T a, T b) { return min(a,b); };
            identity = numeric_limits<T>::max();
        } else if (op == "SUM") {
            combine = [](T a, T b) { return a+b; };
            identity = T{};
        } else if (op == "GCD") {
            combine = [](T a, T b) { return gcd(a,b); };
            identity = T{};
        } else if (op == "XOR") {
            combine = [](T a, T b) { return a^b; };
            identity = T{};
        } else {
            assert(false);
        }

        // build tree
        levels.push_back(vec);

        while (levels.back().size() > 1) {
            auto& cur = levels.back();
            vector<T> next((cur.size() + 1) / 2, identity);

            for (int i = 0; i < next.size(); i++) {
                if (2 * i + 1 < cur.size())
                    next[i] = combine(cur[2 * i], cur[2 * i + 1]);
                else
                    next[i] = cur[2 * i];
            }

            levels.push_back(move(next));
        }
    }

    // inclusive [l, r]
    T query(int l, int r) {
        assert(0 <= l && l <= r && r < levels[0].size());

        T left = identity; // left and right for noncommutative operations
        T right = identity;
        int level = 0;

        while (true) {
            if (l & 1) // l is right child
                left = combine(left, levels[level][l++]);
            if (!(r & 1)) // r is left child
                right = combine(levels[level][r--], right);

            if (l > r) break;

            l /= 2; // go up to parents
            r /= 2;
            level++; // go up a level
        }

        return combine(left, right);
    };

    void set(int index, T value) {
        assert(0 <= index && index < levels[0].size());

        levels[0][index] = value; // set it

        for (int level = 1; level < levels.size(); level++) { // recombine
            index /= 2; // go up to parent

            int left  = 2 * index; // left child
            int right = 2 * index + 1; // right child

            if (right < levels[level-1].size()) // if right child exists, combine
                levels[level][index] = combine(
                    levels[level-1][left],
                    levels[level-1][right]
                );
            else
                levels[level][index] = levels[level-1][left]; // otherwise, take left child only
        }
    };

};
