/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
  */

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    calculateHeight(root, diameter);
    return diameter;
}

// Helper function to calculate the height of a binary tree
int calculateHeight(TreeNode* root, int& diameter) {
    // Base case: if the current node is null, return 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursively calculate the height of the left and right subtrees
    int leftHeight = calculateHeight(root->left, diameter);
    int rightHeight = calculateHeight(root->right, diameter);
    
    // Update the diameter if the sum of the heights of the left and right subtrees is greater
    diameter = max(diameter, leftHeight + rightHeight);
    
    // Return the maximum height between the left and right subtrees, plus 1 for the current node
    return max(leftHeight, rightHeight) + 1;
}
