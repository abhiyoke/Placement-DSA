
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>level;
        if(root==nullptr) return level;
        q.push(root);

        while(!q.empty()){
            vector<int>te;
            int curr=q.size();
            for(int i=0;i<curr;i++){
            TreeNode* temp=q.front();

            q.pop();
            te.push_back(temp->val);
            
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            }
            level.push_back(te);
        }
        return level;
    }
};
