#include<bits/stdc++.h>
using namespace std;
/** A data structure that can answer point update & range min queries. */

template <class T> class SegmentTree {

    private:

        const T DEFAULT = std::numeric_limits<T>().max();
        int len;
        vector<T> segtree;  // index 0 is not in use

        T combine(const T &a, const T &b) { return std::min(a, b); }

        void build(const vector<T> &arr, int at, int at_left, int at_right) {
            if (at_left == at_right) {
                segtree[at] = arr[at_left];
                return;
            }

            int mid = (at_left + at_right) / 2;

            build(arr, 2 * at, at_left, mid);
            build(arr, 2 * at + 1, mid + 1, at_right);

            segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
        }

        void set(int ind, T val, int at, int at_left, int at_right) {

            if (at_left == at_right) {
                segtree[at] = val;
                return;
            }

            int mid = (at_left + at_right) / 2;

            if (ind <= mid) {
                set(ind, val, 2 * at, at_left, mid);
            } else {
                set(ind, val, 2 * at + 1, mid + 1, at_right);
            }

            segtree[at] = combine(segtree[2 * at], segtree[2 * at + 1]);
        }


        T range_query(int start, int end, int at, int at_left, int at_right) {

            if (at_right < start || end < at_left) { return DEFAULT; }
            if (start <= at_left && at_right <= end) { return segtree[at]; }

            int mid = (at_left + at_right) / 2;

            T left_res = range_query(start, end, 2 * at, at_left, mid);
            T right_res = range_query(start, end, 2 * at + 1, mid + 1, at_right);

            return combine(left_res, right_res);
        }

    public:

        SegmentTree(const vector<T> &arr, const T def) : len(arr.size()), DEFAULT(def) {
            segtree = vector<T>(len * 4, DEFAULT);
            build(arr, 1, 0, len - 1);
        }

        /** Sets the value at ind to val. */
        void set(int ind, T val) { set(ind, val, 1, 0, len - 1); }

        /** @return the minimum element in the range [start, end] */
        T range_query(int start, int end) { return range_query(start, end, 1, 0, len - 1); }
};

int main() {

    vector<int> a = {3,3,3,4,1};

    SegmentTree<int> st(a, 100);

    int ans = st.range_query(3, 4);
    cout << ans << endl;

};