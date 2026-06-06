#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insert(Node*& root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return;
    }
    if (val < root->val) {
        insert(root->left, val);
    }
    else if (val > root->val) {
        insert(root->right, val);
    }
}

bool search(Node* root, int k, bool& found) {
    if (root == nullptr) {
        return false;
    }
    cout << root->val << " ";
    if (root->val == k) {
        found = true;
        return true;
    }
    else if (k < root->val) {
        return search(root->left, k, found);
    }
    else {
        return search(root->right, k, found);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    bool found = false;
    search(root, k, found);

    if (!found) {
        cout << -1;
    }

    return 0;
}