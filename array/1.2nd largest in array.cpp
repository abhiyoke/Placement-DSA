  int print2largest(vector<int> &arr) {
        // Code Here
        int lar=INT_MIN;
        int sec_lar=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>lar){
                sec_lar=lar;
                lar=arr[i];
            }
            else if(arr[i]>sec_lar && arr[i]!=lar){
                sec_lar=arr[i];
            }
        }
        if(sec_lar==INT_MIN) return -1;
        return sec_lar;
    }
