#include <iostream>
#include <cmath>

int is_prime(int k)
{
    if (k <= 1) {
        std::cout << "This is not a prime number" << std::endl;
        return 0;
    }
    else if (k == 2)
    {
        std::cout << "This is a prime number" << std::endl;
        return 1;
    }
    else if (k % 2 == 0)
    {
        std::cout << "This is not a prime number" << std::endl;
        return 0;
    }
    for (int i = 3; i <= sqrt(k); i += 2)
    {
        if (k % i == 0)
        {
            std::cout << "This is not a prime number" << std::endl;
            return 0;
        }
    }
    std::cout << "This is a prime number" << std::endl;
    return 1;
}

int main()
{
    int k;
    std::cout << "Enter a number: ";
    std::cin >> k;
    is_prime(k);//an O(sqrt(n)) algorithm
    return 0;
}