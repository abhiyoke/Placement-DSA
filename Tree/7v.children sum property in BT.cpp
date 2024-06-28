/*
Step 1: Base CaseStart by checking if we've reached the end of a branch in the tree. If the current node is null, simply return.
Step 2: Calculate Children Sum: For each non-null node, calculate the sum of the values of its left and right children, if they exist.
Add up the values of the left and right children (if they are not null) and store this sum in a variable called child.
Step 3: Comparison and Value Update: Compare the sum of the children (child) with the current node's value.
If the sum of children is greater than or equal to the current node's value, we update the value of the parent to the sum of the children.
If the sum of children is smaller than the current node's value, we need to make an adjustment to ensure the property holds. However, remember that
we cannot decrease the value of any node. So, instead, we update one of the children's values to match the current node's value.
Step 4: Recursive Calls: For each node in the current level: After handling the current node, we recursively call the function on the left and right 
children of the current node.
Step 5: Update Current Node's Value: Once both children have been processed, we recalculate the total sum of the values of the left and right children 
and update the current node’s value to match the total sum of its children.
*/
 void changeTree(TreeNode* root) {
        // Base case: If the current node
        // is NULL, return and do nothing.
        if (root == NULL) {
            return;
        }

        // Calculate the sum of the values of
        // the left and right children, if they exist.
        int child = 0;
        if (root->left) {
            child += root->left->val;
        }
        if (root->right) {
            child += root->right->val;
        }

        // Compare the sum of children with
        // the current node's value and update
        if (child >= root->val) {
            root->val = child;
        } else {
            // If the sum is smaller, update the
            // child with the current node's value.
            if (root->left) {
                root->left->val = root->val;
            } else if (root->right) {
                root->right->val = root->val;
            }
        }

        // Recursively call the function
        // on the left and right children.
        changeTree(root->left);
        changeTree(root->right);

        // Calculate the total sum of the
        // values of the left and right
        // children, if they exist.
        int tot = 0;
        if (root->left) {
            tot += root->left->val;
        }
        if (root->right) {
            tot += root->right->val;
        }

        // If either left or right child
        // exists, update the current node's
        // value with the total sum.
        if (root->left or root->right) {
            root->val = tot;
        }
    }
