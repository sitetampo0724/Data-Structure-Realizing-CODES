#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int theoScore;
    int pracScore;
    Student(int a = 0, int b = 0, int c = 0) : id(a), theoScore(b), pracScore(c) {}
};

bool cmp(const Student& x, const Student& y) {
    int tx = x.theoScore + x.pracScore;
    int ty = y.theoScore + y.pracScore;
    if (tx != ty) return tx > ty;
    if (x.pracScore != y.pracScore) return x.pracScore > y.pracScore;
    return x.id < y.id;
}

int main() {
    int number;
    cin >> number;

    Student* a = new Student[number];
    for (int i = 0; i < number; i++) {
        cin >> a[i].id >> a[i].theoScore >> a[i].pracScore;
    }

    sort(a, a + number, cmp);

    for (int i = 0; i < number; i++) {
        cout << a[i].id << " " << a[i].theoScore + a[i].pracScore << "\n";
    }

    delete[] a;
    return 0;
}