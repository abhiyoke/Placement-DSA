//level order:
vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(root==nullptr) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(i==n-1) res.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return res;
    }

//recursive:
vector<int> rightSideView(TreeNode* root) {
       vector<int> res;
        
        // Call the recursive function
        // to populate the right-side view
        rightview(root, 0, res);
        
        return res;
    }
    void rightview(TreeNode* root,int level,vector<int>res){
       if(root == NULL){
            return;
        }
        
        // Check if the size of the result vector
        // is equal to the current level
        if(res.size() == level){
            // If equal, add the value of the
            // current node to the result vector
            res.push_back(root->val);
            
            // Recursively call the function for the
            // right child with an increased level
            rightview(root->right, level + 1, res);
            
            // Recursively call the function for the
            // left child with an increased level
            rightview(root->left, level + 1, res);
        }
    }
