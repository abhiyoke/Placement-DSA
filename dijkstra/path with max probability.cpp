/*
  You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected
  edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
  */
/*
esme nikalna max h toh hm dist mai INT_MIN dalenge aur if cond mai less than ki jagah greater than check krenge.
  */

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
             adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        vector<double>dist(n,INT_MIN);
        dist[start]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double dis=it.first;
            int node=it.second;
            for(auto itr:adj[node]){
                int adjnode=itr.first;
                double edw=itr.second;
                if(dis*edw>dist[adjnode]){
                    dist[adjnode]=dis*edw;
                    pq.push({dis*edw,adjnode});
                }
            }
        }
        if(dist[end]==INT_MIN) return 0.00000;
        return dist[end];
    }
};
