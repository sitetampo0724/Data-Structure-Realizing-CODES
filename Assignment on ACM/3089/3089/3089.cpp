#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findKth(const vector<int>& a, const vector<int>& b, int k) {
    int n = a.size(), m = b.size();
    int left = max(0, k - m), right = min(k, n);

    while (left <= right) {
        int i = (left + right) / 2;  
        int j = k - i;              

        int aLeft = (i == 0) ? INT_MIN : a[i - 1];
        int aRight = (i == n) ? INT_MAX : a[i];
        int bLeft = (j == 0) ? INT_MIN : b[j - 1];
        int bRight = (j == m) ? INT_MAX : b[j];

        if (aLeft <= bRight && bLeft <= aRight) {
            return max(aLeft, bLeft);
        }
        else if (aLeft > bRight) {
            right = i - 1;
        }
        else {
            left = i + 1;
        }
    }

    return -1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    while (q--) {
        int k;
        cin >> k;
        cout << findKth(a, b, k) << '\n';
    }

    return 0;
}