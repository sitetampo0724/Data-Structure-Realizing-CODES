// 3094.cpp : Defines the entry point for the application.
//

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int* a = new int[number];
    int* b = new int[number];

    for (int i = 0; i < number; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }


    for (int i = 0; i < number - 1; i++)
    {
        for (int j = 0; j < number - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // 去重查找
    for (int i = 0; i < number; i++)
    {
        int rank = 1;  
        for (int j = 0; j < number; j++)
        {
            if (j > 0 && a[j] != a[j - 1])
            {
                rank++;
            }

            if (b[i] == a[j])
            {
                cout << rank;
                if (i < number - 1) cout << " ";
                break;
            }
        }
    }

    delete[] a;
    delete[] b;

    return 0;
}