int floorInBST(TreeNode* root, int key){
        // Initialize the floor variable
        // to store the floor value
        int floor = -1;
        
        // Traverse the BST until reaching
        // the endor finding the key
        while(root){
            // If the key is found, assign it 
            // as the floor value and return
            if(root->val == key){
                floor = root->val;
                return floor;
            }
            
            // If the key is greater than the current
            // node's value, move to the right subtree
            if(key > root->val){
                // Update the floor with the current node's
                // value and move to the right subtree
                floor = root->val;
                root = root->right;
            }
            else{
                // If the key is smaller than the current
                // node's value, move to the left subtree
                root = root->left;
            }
        }
        // Return the computed floor value
        return floor;
    }
