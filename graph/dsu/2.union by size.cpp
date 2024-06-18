#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> size;

void initialize(int n) {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) 
        return;

    if (size[x_parent] > size[y_parent]) {
        parent[y_parent] = x_parent;
        size[x_parent] += size[y_parent];
    } else if (size[x_parent] < size[y_parent]) {
        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];
    } else {
        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];
    }
}

int main() {
    initialize(6);
    Union(0, 1);
    Union(0, 2);

    // if 0 and 3 are not in the same Component yet
    if (find(0) == find(3)) {
        cout << "In same component" << endl;
    } else {
        cout << "Not in same component" << endl;
    }

    // Now we will Union 0 and 3
    Union(0, 3);
    if (find(0) == find(3)) {
        cout << "In same component" << endl;
    } else {
        cout << "Not in same component" << endl;
    }
}
