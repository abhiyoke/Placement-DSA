int lenOfLongSubarr(int a[],  int n, int k) 
    { 
    int sum = 0;
    int len = 0;
    map<int,int>m;
   for(int i=0;i<n;i++) {
        sum+=a[i];
        if(sum==k){
            len=max(len,i+1);
        }
        int rem=sum-k;
         if(m.find(rem)!=m.end()){
            len=max(len,i-m[rem]);
        }
        if(m.find(sum)==m.end()){
            m[sum]=i;
        }
   }
   return len;
    } 
