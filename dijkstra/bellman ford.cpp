/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5yTkgeTqKK0
    Company Tags                : Amazon, Microsoft (Generally asked as a follow up qn of Dijkstra's Algorithm)
    GfG Link                    : https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
*/

/*
  relax edges v-1 times menans use if condition if there is any update in dist array.If after that there is updatation in dist array then there is
  negative cycle.
  It works with -ve edges and cycle.
  */
class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> result(V, 1e8);
        result[S] = 0;
        
        for(int c = 1; c<=V-1; c++) {
            
            for(auto &edge : edges) {
                
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    result[v] = result[u] + w;
                }
                
            }
            
        }
        
        //Now detect negative cycle
        for(auto &edge : edges) {
            
            int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(result[u] != 1e8 && result[u] + w < result[v]) {
                    return {-1};
                }
        }
        
        return result;
    }
};
