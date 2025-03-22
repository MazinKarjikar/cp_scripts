#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define sz(x) (int)(x).size()

// n log n
int count_inv(vector<int>& v) {
    int inv = 0;
    ordered_set<int> os;
    for(int i = 0; i < sz(v); i++) {
        if (sz(os)) inv += sz(os) - os.order_of_key(v[i]);
        os.insert(v[i]);
    }
    return inv;
}