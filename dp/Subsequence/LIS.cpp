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
       vector<int>dp(n,1);
    int maxi=0;
    for(int i=0;i<n;i++){
      for(int prev=0;prev<i;prev++){
        if(nums[prev]<nums[i]){
          dp[i]=max(dp[i],1+dp[prev]);
        }
      }
      maxi=max(maxi,dp[i]);
    }
    return maxi;
    }
};
