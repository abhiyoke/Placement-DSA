/*
You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
*/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // Min-heap to keep projects by their capital requirements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // Max-heap to keep projects by their profits
        priority_queue<int> maxHeap;

        int n = profits.size();
        for (int i = 0; i < n; ++i) {
            minHeap.push({capital[i], profits[i]});
        }

        while (k > 0) {
            // Push all projects that can be started with the current capital into the max-heap
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            // If no projects can be started, break
            if (maxHeap.empty()) {
                break;
            }

            // Select the project with the maximum profit
            w += maxHeap.top();
            maxHeap.pop();
            --k;
        }

        return w;
    }
};
