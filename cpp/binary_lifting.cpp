#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p = {0, 0, 1, 2, 0};
    int n = p.size();

// -----------------BINARY LIFTING------------------
    int max_bit = 31;
    vector<vector<int>> bl(n, vector<int>(max_bit));

    for(int i = 0; i < n; i++) bl[i][0] = p[i];

    for(int k = 1; k < max_bit; k++) {
        for(int i = 0; i < n; i++) {
            bl[i][k] = bl[bl[i][k-1]][k-1];
        }
    }
// -----------------BINARY LIFTING------------------


}