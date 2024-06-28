/*
Given a binary tree having n nodes. Check whether all of its nodes have the value equal to the sum of their child nodes. Return 1 if all the nodes in the 
tree satisfy the given properties, else it return 0.
For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child. 
Also, leaves are considered to follow the property.
  */

int isSumProperty(Node *root)
    {
     // Add your code here
        if(root==nullptr) return 1;
         if (root->left == nullptr && root->right == nullptr) return 1;
        int sum=0;
        if(root->left) sum+=root->left->data;
        if(root->right) sum+=root->right->data;
        if(sum!=root->data) return 0;
        if(isSumProperty(root->left)!=1) return 0;
        if(isSumProperty(root->right)!=1) return 0;
        return 1;
    }
