class Solution {
public:
vector<int> parent;
    vector<int> rank;

    int find (int x) {
        if (x == parent[x]) 
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) 
            return;

        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
         parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        for(int i=0;i<edges.size();i++){
            int x=find(edges[i][0]);
            int y=find(edges[i][1]);
            
                Union(edges[i][0],edges[i][1]);
            
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int papa=find(i);
            m[papa]++;
        }
        long long c=0;
        long long left=n;
        for(auto it:m){
            c+=it.second*(left-it.second);
            left=left-it.second;
        }
        return c;
    }
};
