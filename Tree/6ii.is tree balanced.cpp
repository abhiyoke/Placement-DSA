bool isBalanced(TreeNode* root) {
    // Check if the height of the tree is not -1 (indicating it is balanced)
    return height(root) != -1;
}

// Function to calculate the height of the binary tree
int height(TreeNode* root) {
    // Base case: If the root is NULL, the height is 0
    if (root == NULL) {
        return 0;
    }
    
    // Recursive calls to calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // Check if the left or right subtree is unbalanced
    if (leftHeight == -1 || rightHeight == -1) {
        return -1; // Return -1 to indicate unbalanced tree
    }
    
    // Check if the absolute difference between the heights of the left and right subtrees is greater than 1
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Return -1 to indicate unbalanced tree
    }
    
    // Return the maximum height between the left and right subtrees, plus 1 for the current node
    return max(leftHeight, rightHeight) + 1;
}
