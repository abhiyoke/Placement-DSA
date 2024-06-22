/*
You are given an integer array nums and two integers cost1 and cost2. You are allowed to perform either of the following operations any number of times:
Choose an index i from nums and increase nums[i] by 1 for a cost of cost1.
Choose two different indices i, j, from nums and increase nums[i] and nums[j] by 1 for a cost of cost2.
Return the minimum cost required to make all elements in the array equal.
Since the answer may be very large, return it modulo 109 + 7.
*/

#define ll long long
class Solution {
public:
    int mod = 1e9 + 7;
    ll sum = 0;
    ll mini = 1e8;

    ll solve(vector<int> &nums, ll cost1, ll cost2, ll maxii){
        ll maxi = maxii - mini;
        ll n = nums.size();

        ll total = maxii*n - sum;
        if( 2*cost1 <= cost2 ) return total * cost1;
        
        ll last = total - maxi;
        if( last < maxi ) return ( maxi - last ) * cost1 + last * cost2;
        
        if( total % 2 == 0 ) return (total/2) * cost2;
        else return  (total/2) * cost2  + cost1 ;
    }
    
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        
        ll maxi = 0;
        
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,1LL*nums[i]);
            mini = min(mini,1LL*nums[i]);
            sum += nums[i];
        }
        
        ll ans =  1e18;

        for(int i=maxi;i<=2*maxi;i++){
            ll d = solve(nums, cost1, cost2, i);
            ans = min(ans,d);
        }
                
        return ans%mod;
    }
};
