#include <iostream>
#include <queue>
using namespace std;

int main() {
    int targetID;
    char setmeal;
    int n;

    cin >> targetID;
    cin >> setmeal;
    cin >> n;

    int maxQPS;
    switch (setmeal) {
    case 'a': maxQPS = 3; break;
    case 'b': maxQPS = 6; break;
    case 'c': maxQPS = 9; break;
    default: maxQPS = 0;
    }

    // 存储目标用户的请求时间戳（索引）
    queue<int> timeWindow;

    for (int i = 0; i < n; i++) {
        int userID;
        cin >> userID;

        if (userID != targetID) {
            cout << "0 ";
        }
        else {
            while (!timeWindow.empty() && i - timeWindow.front() >= 10) {
                timeWindow.pop();
            }
            if (timeWindow.size() < maxQPS) {
                cout << "1 ";
                timeWindow.push(i);
            }
            else {
                cout << "-1 ";
            }
        }
    }

    return 0;
}