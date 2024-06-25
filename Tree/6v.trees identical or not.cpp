bool isSameTree(TreeNode* p, TreeNode* q) {
    // Base case: if both nodes are NULL, they are the same
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // Base case: if one node is NULL and the other is not, they are not the same
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // Check if the values of the current nodes are the same
    bool isValuesEqual = (p->val == q->val);
    
    // Recursively check if the left subtrees and right subtrees are the same
    bool isLeftSubtreeEqual = isSameTree(p->left, q->left);
    bool isRightSubtreeEqual = isSameTree(p->right, q->right);
    
    // Return true if the values and both subtrees are the same, otherwise return false
    return isValuesEqual && isLeftSubtreeEqual && isRightSubtreeEqual;
}
