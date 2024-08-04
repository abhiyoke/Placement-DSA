#include <bits/stdc++.h>
using namespace std;

// Node structure
struct node {
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Insert function to insert values into the binary search tree
void insert(node* root, int val) {
    while (true) {
        if (root->data > val) {
            if (root->left == nullptr) {
                root->left = new node(val);
                break;
            }
            root = root->left;
        } else {
            if (root->right == nullptr) {
                root->right = new node(val);
                break;
            }
            root = root->right;
        }
    }
}

// Solve function to find if there is a path with sum equal to k
bool solve(node* root, int k, int& sum) {
    if (root == nullptr) return false;
    sum += root->data;
    if (sum == k) return true;
    if (solve(root->left, k, sum) || solve(root->right, k, sum)) return true;
    sum -= root->data; // backtrack
    return false;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> v;
    string temp="";
    for (int i = 0; i < s.size(); i++) {
        if(s[i]==','){
            v.push_back(stoi(temp));
            temp="";
        }
        else temp+=s[i];
    }
    v.push_back(stoi(temp));
    int n = s.size();
    node* root = new node(v[0]);
    for (int i = 1; i < n; i++) {
        insert(root, v[i]);
    }
    int sum = 0;
    if (solve(root, k, sum)) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
