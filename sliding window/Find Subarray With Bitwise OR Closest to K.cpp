//https://leetcode.com/problems/find-subarray-with-bitwise-or-closest-to-k/

class Solution {
public:
     int get_subarray_or(int l, int r, vector<vector<int>>& bitTable) {
        int or_sum = 0;
        for (int j = 0; j < 31; j++) {
            int count = bitTable[r+1][j] - bitTable[l][j];
            if (count > 0) {
                or_sum |= (1 << j);
            }
        }
        return or_sum;
    }
    
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Initialize the prefix bit table
        vector<vector<int>> bitTable(n + 1, vector<int>(31, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 31; j++) {
                if ((1 << j) & nums[i-1]) {
                    bitTable[i][j] = bitTable[i-1][j] + 1;
                } else {
                    bitTable[i][j] = bitTable[i-1][j];
                }
            }
        }
        
        int ans = INT_MAX;
        int i = 0;
        
        // Sliding window
        for (int j = 0; j < n; j++) {
            while (i < j && get_subarray_or(i, j, bitTable) > k) {
                ans = min(ans, abs(get_subarray_or(i, j, bitTable) - k));
                i++;
            }
            ans = min(ans, abs(get_subarray_or(i, j, bitTable) - k));
        }
        
        return ans;
    }
};
