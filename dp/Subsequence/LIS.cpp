class Solution {
public:
    int lis(int ind,int prev,int n,vector<int>&nums,vector<vector<int>>&dp){ 
        
       if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
       
            int len=0+lis(ind+1,prev,n,nums,dp);
            if (nums[ind] > nums[prev] || prev==-1) {
              len = max(len, 1 + lis(ind + 1, ind, n, nums, dp));
            }

            return dp[ind][prev+1]=len;
            
        }

    int lengthOfLIS(vector<int>& nums) {
      int n=nums.size();
      vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || nums[ind] > nums[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];     //ind+1 is due to +1 state as pre is starting from -1 and there is nothing for it in dp and that's why +1 is there.
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];
    }
};


/*
int longestIncreasingSubsequence(int arr[], int n){
    
    vector<int> dp(n,1);
    
    for(int i=0; i<=n-1; i++){
        for(int prev_index = 0; prev_index <=i-1; prev_index ++){
            
            if(arr[prev_index]<arr[i]){
                dp[i] = max(dp[i], 1 + dp[prev_index]);
            }
        }
    }
    
    int ans = -1;
    
    for(int i=0; i<=n-1; i++){
        ans = max(ans, dp[i]);
    }
    
    return ans;
}


*/
