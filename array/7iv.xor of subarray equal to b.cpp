int Solution::solve(vector<int> &A, int B) {
    int temp=0;
    int cnt=0;
    int n=A.size();
    map<int,int>m;
    m[0]=1;
    for(int i=0;i<n;i++){
        temp=temp^A[i];
        int target=temp^B;
        cnt+=m[target];
        m[temp]++;
    }
    return cnt;
}
