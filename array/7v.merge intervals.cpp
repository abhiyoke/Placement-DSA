 vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>>ans;
        int n=v.size();
        ans.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(ans[ans.size()-1][1]>=v[i][0]){
                ans[ans.size()-1][1]=max(v[i][1],ans[ans.size()-1][1]);
            }
            else{
                ans.push_back(v[i]);

            }
        }
        return ans;
    }
