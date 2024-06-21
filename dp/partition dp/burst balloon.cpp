/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the 
balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as 
if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.
  */

class Solution {
public:
    int func(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost=nums[k]*nums[i-1]*nums[j+1]+func(i,k-1,nums,dp)+func(k+1,j,nums,dp);
            mini=max(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return func(1,n,nums,dp);
    }
};
