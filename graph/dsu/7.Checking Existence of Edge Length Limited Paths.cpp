/*
An undirected graph of n nodes is defined by edgeList, where edgeList[i] = [ui, vi, disi] denotes an edge between nodes ui and vi with distance disi. 
Note that there may be multiple edges between two nodes.
Given an array queries, where queries[j] = [pj, qj, limitj], your task is to determine for each queries[j] whether there is a path between pj and qj such that
each edge on the path has a distance strictly less than limitj .
Return a boolean array answer, where answer.length == queries.length and the jth value of answer is true if there is a path for queries[j] is true, 
and false otherwise.
  */

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) 
            parent[i] = i;

        // Add index to queries for result mapping
        for (int i = 0; i < q.size(); i++) {
            q[i].push_back(i);
        }

        // Lambda function for sorting
        auto lambda = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };

        // Sort queries and edges based on the threshold
        sort(q.begin(), q.end(), lambda);
        sort(e.begin(), e.end(), lambda);

        vector<bool> result(q.size());
        int j = 0; // Initialize edge index

        // Process each query
        for (int i = 0; i < q.size(); i++) {
            int u = q[i][0];
            int v = q[i][1];
            int t = q[i][2];
            int idx = q[i][3];

            // Union components based on the current threshold
            while (j < e.size() && e[j][2] < t) {
                Union(e[j][0], e[j][1]);
                j++;
            }

            // Check if the vertices are connected
            if (find(u) == find(v)) {
                result[idx] = true;
            } else {
                result[idx] = false;
            }
        }

        return result;
    }
};
