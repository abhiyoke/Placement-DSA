/*
sort the preorder and we get inroder and now we have both and just make a tree.
  */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
    vector<int> in = pre; // Make a copy of pre, we'll sort it later
    int n = pre.size();
    sort(in.begin(), in.end());
    int preindex = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[in[i]] = i;
    }
    return bst(pre, in, m, preindex, 0, n - 1);
}

TreeNode* bst(vector<int>& pre, vector<int>& in, map<int, int>& m, int& preindex, int st, int en) {
    if (st > en) return nullptr;
    int root_val = pre[preindex];
    TreeNode* root = new TreeNode(root_val);
    int index = m[root_val];
    preindex++;
    root->left = bst(pre, in, m, preindex, st, index - 1);
    root->right = bst(pre, in, m, preindex, index + 1, en);
    return root;
}
};
