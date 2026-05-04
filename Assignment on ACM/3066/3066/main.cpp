#include <iostream>
using namespace std;

struct Node {
    int left;
    long long int weight;
    int right;
    bool used; 
    Node() : left(0), weight(0), right(0), used(false) {}
};

long long int cal(int index, long long int depth, Node* tree) {
    if (index == 0) return 0;


    if (tree[index].left == 0 && tree[index].right == 0) {
        return tree[index].weight * depth;
    }

    return cal(tree[index].left, depth + 1, tree) +
        cal(tree[index].right, depth + 1, tree);
}

int main() {
    int n;
    cin >> n;


    Node* tree = new Node[n + 1];


    for (int i = 1; i <= n; i++) {
        int left, right;
        long long int weight;
        cin >> left >> weight >> right;
        tree[i].left = left;
        tree[i].weight = weight;
        tree[i].right = right;

        if (left != 0) tree[left].used = true;
        if (right != 0) tree[right].used = true;
    }



    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (!tree[i].used) {
            root = i;
            break;
        }
    }
    long long int ans = cal(root, 0, tree);
    cout << ans << endl;

    delete[] tree;
    return 0;
}