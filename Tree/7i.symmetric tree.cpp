bool isMirror(TreeNode* root1,TreeNode* root2)
	  {
	      if(root1==nullptr and root2==nullptr) return true;
	       if(root1==nullptr or root2==nullptr) return false;
	       if (root1->val!=root2->val) return false;
	       return isMirror(root1->left,root2->right) && isMirror(root1->right,          root2->left);
	       }
    bool isSymmetric(TreeNode* root) {
      if(root==nullptr) return true;
	  return isMirror(root->left,root->right);
    }
