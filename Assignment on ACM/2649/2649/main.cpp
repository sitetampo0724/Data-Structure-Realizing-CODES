#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<int> parent(N + 1, 0);  
    for (int node = 1; node <= N; node++) {
        int left, right;
        cin >> left >> right;
        if (left != 0) {
            parent[left] = node;
        }
        if (right != 0) {
            parent[right] = node;
        }
    }

    vector<int> pathX;
    int cur = X;
    while (cur != 0) {
        pathX.push_back(cur);
        cur = parent[cur];
    }

    vector<int> pathY;
    cur = Y;
    while (cur != 0) {
        pathY.push_back(cur);
        cur = parent[cur];
    }

    int i = pathX.size() - 1;
    int j = pathY.size() - 1;
    int lca = pathX[i]; 

    while (i >= 0 && j >= 0 && pathX[i] == pathY[j]) {
        lca = pathX[i];
        i--;
        j--;
    }

    cout << lca << endl;

    return 0;
}