/*
Base Case:

DP[0][0] = True: With zero elements, we can achieve the sum of 0 (by selecting no elements).
Transition:

If we exclude the i-th element: DP[i][j] = DP[i-1][j]
If we include the i-th element (assuming arr[i-1] is the i-th element in 1-based index): DP[i][j] = DP[i-1][j - arr[i-1]] if j >= arr[i-1]
  */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Declare the dp array
bool dp[5005][5005];

int main() {
    // Number of items
    ll n;
    cin >> n;

    // Array to store weights of the items
    ll b[n + 5] = {0};

    // Desired sum
    ll k;
    cin >> k;

    // Variable to store the total sum of weights
    ll sum = 0;

    // Read the weights of the items and calculate the total sum
    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
        sum += b[i];
    }

    // Initialize dp array for the base case (no items, zero sum)
    dp[0][0] = true;

    // Fill the dp table
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= sum; j++) {
            if (dp[i - 1][j] == true) {
                dp[i][j] = true; // If the sum j can be achieved without the current item
            } else if (j - b[i] >= 0 && dp[i - 1][j - b[i]] == true) {
                dp[i][j] = true; // If the sum j can be achieved by including the current item
            }
        }
    }

    // Output the result
    if (dp[n][k] != true) {
        cout << "nop" << endl; // If the desired sum k cannot be achieved
    } else {
        cout << "yup" << endl; // If the desired sum k can be achieved
    }

    return 0;
}
