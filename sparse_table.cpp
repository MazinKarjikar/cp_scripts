#include <vector>
#include <cmath>
#include <functional>
#include <iostream>
using namespace std;

template <typename T>
struct SparseTable {
    vector<vector<T>> table;
    int n;
    T default_value;
    function<T(T,T)> combine;

    SparseTable(const vector<T>& input, function<T(T,T)> f, T d) {
        n = input.size();
        combine = f;
        default_value = d;
        int max_log = log2(n) + 1;
        table.assign(max_log, vector<T>(n));

        for(int i = 0; i < n; i++) {
            table[0][i] = static_cast<T>(input[i]);
        }

        for(int j = 1; j < max_log; j++) {
            for(int i = 0; i + (1 << j) - 1 < n; i++) {
                table[j][i] = combine(table[j-1][i], table[j-1][i + (1 << (j-1))]);
            }
        }
    }

    T query(int L, int R) {
        T result = default_value;
        for(int i = log2(n); i >= 0; i--) {
            if((1 << i) <= (R - L + 1)) {
                result = combine(result, table[i][L]);
                L += 1 << i;
            }
        }
        return result;
    }

};

// usage
int main() {
    vector<int> input = {1, 2, 4, 0, 6, 3, 2};
    SparseTable<int> st(input, plus<int>(), 0);
    cout << st.query(2,4) << endl;
}