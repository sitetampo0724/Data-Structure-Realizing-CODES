#include <iostream>
#include <random>
#include <chrono>
#include "11、15、17.h"
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


int nextPrime(int n) {
    while (!isPrime(n)) n++;
    return n;
}

int main() {
    const int N = 10000;           
    const int TABLE_SIZE = nextPrime(25000);  


    hashSearchTable<int, int> table(TABLE_SIZE);


    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);

    int totalProbes = 0;

    for (int i = 0; i < N; i++) {
        int num = dis(gen);
        int probes = table.insert(Set<int, int>(num, num));
        totalProbes += probes;
    }

    // 计算平均探测数
    double avgProbes = (double)totalProbes / N;

    cout << "=== 线性探测哈希表统计 ===" << endl;
    cout << "表长度: " << TABLE_SIZE << endl;
    cout << "插入元素数: " << N << endl;
    cout << "装载因子: " << (double)N / TABLE_SIZE << endl;
    cout << "总探测次数: " << totalProbes << endl;
    cout << "平均探测数: " << avgProbes << endl;
    cout << "理论值 1/(1-α): " << 1.0 / (1 - (double)N / TABLE_SIZE) << endl;

    return 0;
}