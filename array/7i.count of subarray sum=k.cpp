int subarraySum(vector<int>& a, int k) {
      int n = a.size();
      map<int,int>m;
      m[0]=1;
      int presum=0;
      int cnt=0;
      for(int i=0;i<n;i++){
          presum+=a[i];
          int remove=presum-k;
          cnt+=m[remove];
          m[presum]++;
      }
      return cnt;
    }
