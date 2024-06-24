/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in 
the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
  */

class Solution {
public:
    int maxSum=0;
    int maxPathSum(TreeNode* root) {
        if(root==nullptr) return 0;
        maxSum=INT_MIN;
     solve(root);
     return maxSum;
    }
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int l=solve(root->left);
        int r=solve(root->right);
        int dono_acha=l+r+root->val;
        int ek_acha=max(l,r)+root->val;
        int root_acha=root->val;
        maxSum=max({maxSum,dono_acha,ek_acha,root_acha});
        return max(ek_acha,root_acha);
    }
};
