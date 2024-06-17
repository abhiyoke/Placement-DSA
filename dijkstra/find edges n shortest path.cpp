
/*
    Leetcode Link               : https://leetcode.com/problems/find-edges-in-shortest-paths/
    You are given an undirected weighted graph of n nodes numbered from 0 to n - 1. The graph consists of m edges represented by a 2D array edges, 
    where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.
Consider all the shortest paths from node 0 to node n - 1 in the graph. You need to find a boolean array answer where answer[i] 
is true if the edge edges[i] is part of at least one shortest path. Otherwise, answer[i] is false.
Return the array answer.
*/
/*
  esme mainly hme agar check krna edges a-->b ka then hm o-->a , a->b , b->n-1 dekenge jisme hme 1st and 3rd pata hoga dijkstra lagake for 0 and n-1 taken
  as src.
  */
class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> P;
    
    vector<int> dijkstra(unordered_map<int, vector<P>>& adj, int src, int n) {
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[src] = 0;

        pq.push({0, src});

        while(!pq.empty()) {

            ll  currWt   = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
        
                        
            if(visited[currNode] == true) {
                continue;
            }


            for(auto adj: adj[currNode]) {
                int nextNode = adj.first;
                ll nextWt = adj.second;

                if(dist[nextNode] > currWt + nextWt) {
                    dist[nextNode] = currWt + nextWt;
                    pq.push({currWt + nextWt, nextNode});
                }
            }
            
            visited[currNode] = true;


        }

        return dist;
    }
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int E = edges.size();
        
        unordered_map<int, vector<P>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> fromSrc  = dijkstra(adj, 0, n);
        vector<int> fromDest = dijkstra(adj, n-1, n);
        
        vector<bool> result(E, false);
        
        for(int i = 0; i < E; i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            ll distFromSrc  = fromSrc[u]; //x
            ll distFromDest = fromDest[v]; //y
            
            if(distFromSrc + w + distFromDest == fromSrc[n-1]) {
                result[i] = true;
            }
            
            
            distFromSrc  = fromSrc[v]; //x
            distFromDest = fromDest[u]; //y
            if(distFromSrc + w + distFromDest == fromSrc[n-1]) {
                result[i] = true;
            }
            
        }
        
        return result;
    }
};
