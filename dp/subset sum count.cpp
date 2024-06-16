 // Base case: There's one way to make sum 0 with 0 items (by picking nothing)
    dp[0][0] = 1;
    
    // Loop through all items
    for(int i = 1; i <= n; i++) {
        // Loop through all sums from 0 to k
        for(int j = 0; j <= k; j++) {
            // If current item can be included in the current sum
            if(j - b[i] >= 0) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - b[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
