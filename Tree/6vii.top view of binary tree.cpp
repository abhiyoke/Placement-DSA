 vector<int> topView(Node *root) {
    vector<int> res;
    if (root == NULL)
        return res;
    
    queue<pair<Node*, int>> q; // Queue for level order traversal with horizontal distance
    map<int, int> m; // Map to store nodes at each vertical distance
    
    q.push({root, 0}); // Push the root node with horizontal distance 0
    
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        
        Node* node = it.first;
        int vertical = it.second;
        
        // If the current vertical distance is not present in the map,
        // add the node's data to the map for that vertical distance
        if (m.find(vertical) == m.end()) {
            m[vertical] = node->data;
        }
        
        // Process the left child if it exists, with a reduced vertical distance
        if (node->left != NULL) {
            q.push({node->left, vertical - 1});
        }
        
        // Process the right child if it exists, with an increased vertical distance
        if (node->right != NULL) {
            q.push({node->right, vertical + 1});
        }
    }
    
    // Append the values from the map to the result vector in sorted order
    for (auto it : m) {
        res.push_back(it.second);
    }
    
    return res;
}
