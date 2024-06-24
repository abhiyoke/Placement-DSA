//Approach 1:Two stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>s1,s2;
        vector<int>postorder;
        TreeNode* node=root;
        if(node==NULL) return postorder;
        s1.push(root);
        while(!s1.empty()){
            root=s1.top();
            s1.pop();
            s2.push(root);
            if(root->left!=NULL){
                s1.push(root->left);
            }
            if(root->right!=NULL){
                s1.push(root->right);
            }
        }
        while(!s2.empty()){
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};

//Approach 2:1 stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if (root == NULL)
            return postOrder;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* curr = stack.top();
            stack.pop();
            postOrder.insert(postOrder.begin(), curr->val);
            if (curr->left != NULL)
                stack.push(curr->left);
            if (curr->right != NULL)
                stack.push(curr->right);
        }
        return postOrder;
    }
};
