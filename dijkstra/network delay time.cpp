/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where 
ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is 
impossible for all the n nodes to receive the signal, return -1.
  */

/*
esme 0 time aur k node ko queue mai bejho 
  */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
        q.push({0, k});
        
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        
       
        
        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int time = it.first;
            int node = it.second;
           
          
            
            for (auto it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                
                if (wt + time < dist[adjnode]) {
                    dist[adjnode] = wt + time;
                    q.push({wt + time, adjnode});
                }
            }
        }
        
        int maxDelay = *max_element(dist.begin()+1, dist.end());
        
        if (maxDelay != 1e9)
            return maxDelay;
        else
            return -1;
    }
};
