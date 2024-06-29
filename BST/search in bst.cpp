 TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr) return nullptr;
        while(root!=nullptr){
            if(root->val==val) return root;
            else if(root->val>val){
                root=root->left;
            }
            else root=root->right;
        }
        return nullptr;
    }
