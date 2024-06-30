class Solution {
public:
    // Function to delete a node with a specific value in a binary search tree
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        // If the current node has the same value as the key
        if (root->val == key) {
            return helper(root); // Delete the node using the helper function
        }
        // If the current node's value is greater than the key, search in the left subtree
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            // If the current node's value is less than the key, search in the right subtree
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    // Helper function to delete a node
    TreeNode* helper(TreeNode* root) {
        // If the node doesn't have a left child, return its right child
        if (root->left == NULL) {
            return root->right;
        }
        // If the node doesn't have a right child, return its left child
        if (root->right == NULL) {
            return root->left;
        }
        // If the node has both left and right children
        TreeNode* right_c = root->right;
        TreeNode* left_last = findlast(root->left); // Find the rightmost node in the left subtree
        left_last->right = right_c; // Attach the right subtree to the rightmost node in the left subtree
        return root->left; // Return the modified left subtree as the new subtree rooted at the current node
    }

    // Function to find the rightmost node in a subtree
    TreeNode* findlast(TreeNode* root) {
        if (root->right == NULL) {
            return root;
        }
        return findlast(root->right);
    }
};
