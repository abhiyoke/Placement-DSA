// recursive:
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return root;
        int curr=root->val;
        if(curr<p->val && curr<q->val) return lowestCommonAncestor(root->right,p,q);  //jb p,q right mai hoga toh hm right mai jaenge.
        if(curr>p->val && curr>q->val) return lowestCommonAncestor(root->left,p,q);
        return root;   //yeh jb p right mai h and q left mai toh root ko return kr denge.
    }
};

//iterative
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val) {
                cur = cur -> left;
            } else if (p -> val > cur -> val && q -> val > cur -> val) {
                cur = cur -> right;
            } else {
                break;
            }
        }
        return cur;
    }
};
