/*
 Given a binary tree, Find the Lowest Common Ancestor for two given Nodes (x,y).
Lowest Common Ancestor(LCA): The lowest common ancestor is defined between two nodes x and y as the lowest node in T that has both x and y as 
descendants (where we allow a node to be a descendant of itself.
        */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || p==root || q==root) return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==nullptr) return right;
        else if(right==nullptr) return left;
        else return root;
    }
