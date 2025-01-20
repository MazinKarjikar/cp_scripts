#include <vector>
#include <cmath>
#include <functional>
#include <iostream>

template <typename T>
struct SparseTable {
    std::vector<std::vector<T>> table;
    int n;
    T default_value;
    std::function<T(T,T)> combine;

    SparseTable(const std::vector<T>& input, std::function<T(T,T)> f, T d) {
        n = input.size();
        combine = f;
        default_value = d;
        int max_log = log2(n) + 1;
        table.assign(max_log, std::vector<T>(n));

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
    std::vector<int> input = {1, 2, 4, 0, 6, 3, 2};
    SparseTable<int> st(input, std::plus<int>(), 0);
    std::cout << st.query(2,4) << std::endl;
}