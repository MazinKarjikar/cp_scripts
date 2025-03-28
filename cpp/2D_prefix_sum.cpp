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

        for(int i = 0; i < n; i++) {
            int rsum = 0;
            for(int j = 0; j < m; j++) {
                rsum += grid[i][j];
                pref[i+1][j+1] = rsum;
                if (i > 0) pref[i+1][j+1] += pref[i][j+1];
            }
        }

        return pref;
    };

    auto query_2d_pref = [&](vector<vector<int>>& pref, int x1, int y1, int x2, int y2) {
        int tot = pref[x2+1][y2+1];
        tot -= pref[x1][y2+1];
        tot -= pref[x2+1][y1];
        tot += pref[x1][y1];
        return tot;
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