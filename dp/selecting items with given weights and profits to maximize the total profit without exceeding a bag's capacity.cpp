/*
The knapsack problem involves selecting items with given weights and profits to maximize the total profit without exceeding a bag's capacity.
*/

/*
Let us say we have two bags having capacity c1 anc c2.
Then formula is: dp[i][j][k]=max(dp[i-1][j][k],dp[i-1][j-w[i]][k],dp[i-1][j][k-w[i]])
THen run 3 loops for it.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Declare the dp array
ll dp[5000][5000];

int main() {
    // Number of items
    ll n = 3;
    cin >> n;

    // Capacity of the knapsack
    ll c;
    cin >> c;

    // Arrays to store profits and weights of the items
    ll p[n + 1] = {0};
    ll b[n + 1] = {0};

    // Read the weights of the items
    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
    }

    // Read the profits of the items
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // Initialize dp array for the case when there are no items
    for (ll i = 0; i <= c; i++) {
        dp[0][i] = 0;
    }

    // Initialize dp array for the case when the capacity is zero
    for (ll i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }

    // Fill the dp table
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= c; j++) {
            ll v1 = dp[i - 1][j]; // Value when the current item is not included
            ll v2 = 0;
            // Value when the current item is included
            if (j - b[i] >= 0) {
                v2 = p[i] + dp[i - 1][j - b[i]];
            }
            // Store the maximum of the two values in the dp table
            dp[i][j] = max(v1, v2);
        }
    }

    // Output the maximum profit that can be obtained with the given capacity
    cout << dp[n][c] << endl;

    return 0;
}

/*
Dynamic Programming Solution:

Define the DP array.
Create a nested loop to fill the DP table based on item inclusion and exclusion.
Use the formula: dp[i][j] = max(dp[i-1][j], profit[i] + dp[i-1][j-weight[i]]) where j >= weight[i].
Handling Subsets:

Solve for subsets of items separately.
Use two options: ignore or include the current item.
Formula: max(dp[i-1][C], profit[i] + dp[i-1][C - weight[i]]).
*/
