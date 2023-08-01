#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> dp(h, vector<int>(w, 0));

    dp[0][0] = 1; // Starting point

    // Fill the first row (top to bottom)
    for (int j = 1; j < w; j++) {
        if (grid[0][j] == 'c') {
            dp[0][j] = 0; // Cannot have a transformer in the first row
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the first column (left to right)
    for (int i = 1; i < h; i++) {
        if (grid[i][0] == 'c') {
            dp[i][0] = 0; // Cannot have a transformer in the first column
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }

    // Fill the rest of the DP array
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (grid[i][j] == 'c') {
                dp[i][j] = 0; // Cannot have a transformer at this cell
            } else if (grid[i][j] == 'a') {
                // A relay can be placed here, and the number of ways is the sum of ways from the top and left cells.
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            } else {
                // An empty cell can have either a relay or a transformer, so the number of ways is twice the sum of ways from the top and left cells.
                dp[i][j] = (2 * (dp[i - 1][j] + dp[i][j - 1])) % MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl; // Number of ways to reach (h, w) from (1, 1)

  
}
