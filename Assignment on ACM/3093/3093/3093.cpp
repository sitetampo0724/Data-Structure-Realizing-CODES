#include <iostream>
using namespace std;

struct Data {
    int level, time, index;
};

int main() {
    int n;
    cin >> n;
    Data* data = new Data[n];

    for (int i = 0; i < n; i++) {
        cin >> data[i].level >> data[i].time;
        data[i].index = i + 1;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            bool needSwap = false;
            if (data[j].level < data[j + 1].level) {
                needSwap = true;
            }
            else if (data[j].level == data[j + 1].level) {
                if (data[j].time > data[j + 1].time) {
                    needSwap = true;
                }
            }
            if (needSwap) {
                Data temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << data[i].index << endl;
    }

    delete[] data;
    return 0;
}