/*
In the case where left height and right height differ, we can employ a recursive approach. We recursively calculate the number of nodes in the left subtree 
and in the right subtree , and then return the total count as 1 + leftNodes + rightNodes. If the height of the left subtree is equal to the height of the right 
subtree, we can directly calculate using the 2^h-1 formula.
  */
int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        else{
            return countNodes(root->left)+countNodes(root->right)+1;
        }
    }
    int leftheight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    int rightheight(TreeNode* root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
