//recursive
class Solution {
public:
    int maxDepth(TreeNode* node) {
                if(node==NULL) return 0;
       
        int l=maxDepth(node->left);
             int r=maxDepth(node->right);
        return max(l,r)+1;
    }
};

//level order:
int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
