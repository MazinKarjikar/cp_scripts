#include<bits/stdc++.h>
using namespace std;


/**
 * This template provides a 2D prefix sum builder, and provides a query function.
 * Copy the lambdas into your solution to use them, and feel free to modify them to fit your needs.
 * I find that sometimes I don't want to rebuild a 2D prefix sum, but rather update.
 */

int main() {

// ----------------------------------------------------------------------------------------
    auto build_pref = [&](vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + grid[i-1][j-1];
            }
        }

        return pref;
    };

    auto query_2d_pref = [&](vector<vector<int>>& pref, int a, int b, int A, int B) {
        a++; b++; A++; B++;
        return pref[A][B] - pref[a-1][B] - pref[A][b-1] + pref[a-1][b-1];
    };
// ----------------------------------------------------------------------------------------


    // usage
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}
    };

    vector<vector<int>> pref = build_pref(grid);

    int answer = query_2d_pref(pref, 0, 0, 2, 3);
    cout << answer << endl;


}