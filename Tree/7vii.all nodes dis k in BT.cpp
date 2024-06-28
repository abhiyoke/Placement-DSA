/*
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance
k from the target node.
You can return the answer in any order.
*/

 vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;

    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front(); q.pop();
        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }

    q.push(target);
    visited[target] = true;
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        if (level++ == K) break;
        for (int i = 0; i < size; ++i) {
            TreeNode* curr = q.front(); q.pop();
            if (curr->left && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if (parent[curr] && !visited[parent[curr]]) {
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
    }

    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
    }
    return result;
    }
