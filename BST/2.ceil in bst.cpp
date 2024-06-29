int findCeil(TreeNode* root, int key){
        // Initialize the variable
        // to store the ceiling value
        int ceil = -1; 
        
        // Traverse the BST until reaching
        // the end or finding the key
        while(root){
             // If the key is found, assign it
             // as the ceiling and return
            if(root->val == key){
                ceil = root->val;
                return ceil;
            } 
            
             // If the key is greater,
             // move to the right subtree
            if(key > root->val){
                root = root->right;
            }
            else{ 
                // If the key is smaller, update ceil
                // and move to the left subtree
                ceil = root->val;
                root = root->left;
            }
        }
         // Return the computed ceiling value
        return ceil;
    }
