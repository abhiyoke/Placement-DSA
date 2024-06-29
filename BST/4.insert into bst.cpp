  TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr=root;
        if(root==nullptr) {
            curr=new TreeNode(val);
            return curr;
        }
        while(curr){
            if(curr->val>val){
                if(curr->left==nullptr) {
                    curr->left = new TreeNode(val);
                    break;
                }
                else curr=curr->left;
            }
            else if(curr->val<val){
                if(curr->right==nullptr){
                    curr->right=new TreeNode(val);;
                    break;
                }
                else curr=curr->right;
            }
        }
        return root;
    }
