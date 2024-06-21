/*
Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number 
of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).
  */
//Time Complexity: O(N*N*N)
//Space Complexity: O(N*N) + O(N)

class Solution{
public:
    int func(int i,int j,int arr[],vector<vector<int>>&dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+func(i,k,arr,dp)+func(k+1,j,arr,dp);
            if(mini>steps) mini =steps;
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return func(1,N-1,arr,dp);
        
    }
};
