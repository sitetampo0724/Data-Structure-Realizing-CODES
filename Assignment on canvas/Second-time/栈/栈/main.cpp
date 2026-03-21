#include "seqStack.h"
#include "linkStack.h"
#include <iostream>
#include <cstring>
using namespace std;
bool isReverse_seq(char* c)
{
    size_t len = strlen(c);
    seqStack<char> passage(static_cast<int>(len));
    for (size_t i = 0; i < len; i++)
    {
        passage.push(c[i]);
    }
    for (size_t i = len; i > 0; i--)
    {
        if (passage.pop() != c[i - 1])
            return false;
    }
    return true;
}
bool isReverse_link(char* c)
{
    linkStack<char> passage;
    for (int i = 0; c[i] != 0; i++)
    {
        passage.push(c[i]);
    }
    int len = strlen(c);
    for (int i = len - 1; i >= 0; i--)
    {
        if (passage.pop() != c[i])
            return false;
    }
    return true;
}

int main()
{
    char testCases[][100] = {
        "aba",
        "abcba",
        "hello",
        "racecar",
        "12321",
        "12345",
        "a",
        "",
        "ab"
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    cout << "========== Test SeqStack Version ==========" << endl;
    for (int i = 0; i < numTests; i++)
    {
        cout << "Test \"" << testCases[i] << "\": ";
        if (isReverse_seq(testCases[i]))
            cout << "Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;
    }
    cout << "\n========== Test LinkStack Version ==========" << endl;
    for (int i = 0; i < numTests; i++)
    {
        cout << "Test \"" << testCases[i] << "\": ";
        if (isReverse_link(testCases[i]))
            cout << "Palindrome" << endl;
        else
            cout << "Not Palindrome" << endl;
    }
    return 0;
}