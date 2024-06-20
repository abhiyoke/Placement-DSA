/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
*/

class Solution {
public:
    
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1),hash(n,0);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int pre=0;pre<i;pre++){
                if(nums[i]%nums[pre]==0 && (1+dp[pre]>dp[i])){
                    dp[i]=1+dp[pre];
                    hash[i]=pre;
                }
            }
        }
        int last=-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                last=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[last]);
        while(hash[last]!=last){
            last=hash[last];
            ans.push_back(nums[last]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
