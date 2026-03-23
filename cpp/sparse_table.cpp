#include <vector>
#include <cmath>
#include <functional>
#include <iostream>
using namespace std;

// O(1) Max Queries
template <typename T>
struct SparseTableMax {
    vector<vector<T>> t;
    int n;

    SparseTableMax(const vector<T>& a) : n(a.size()) {
        int k = __lg(n) + 1;
        t.assign(k, vector<T>(n));
        t[0] = a;
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                t[j][i] = max(t[j-1][i], t[j-1][i + (1 << (j-1))]);
    }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        return max(t[k][l], t[k][r - (1 << k) + 1]);
    }
};

// O(1) Min Queries
template <typename T>
struct SparseTableMin {
    vector<vector<T>> t;
    int n;

    SparseTableMin(const vector<T>& a) : n(a.size()) {
        int k = __lg(n) + 1;
        t.assign(k, vector<T>(n));
        t[0] = a;
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                t[j][i] = min(t[j-1][i], t[j-1][i + (1 << (j-1))]);
    }

    T query(int l, int r) {
        int k = __lg(r - l + 1);
        return min(t[k][l], t[k][r - (1 << k) + 1]);
    }
};

// O(log n) Sum Queries
template <typename T>
struct SparseTableSum {
    vector<vector<T>> t;
    int n;

    SparseTableSum(const vector<T>& a) : n(a.size()) {
        int k = __lg(n) + 1;
        t.assign(k, vector<T>(n));
        t[0] = a;
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                t[j][i] = t[j-1][i] + t[j-1][i + (1 << (j-1))];
    }

    T query(int l, int r) {
        T res = 0;
        for (int j = __lg(r - l + 1); j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                res += t[j][l];
                l += 1 << j;
            }
        }
        return res;
    }
};

int main() {
    vector<int> a{1, 2, 3, 4, 5};
    SparseTableMax<int> st(a);

    cout << st.query(0, 1) << endl;
}