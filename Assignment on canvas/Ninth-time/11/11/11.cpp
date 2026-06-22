// 11.cpp : Defines the entry point for the application.
//

#include <fstream>
#include <iostream>

void merge(const char* in1, const char* in2, const char* out) {
    std::ifstream fp1(in1), fp2(in2);  
    std::ofstream fpOut(out); 

    int a, b;
    bool hasA = static_cast<bool>(fp1 >> a), hasB = static_cast<bool>(fp2 >> b);

    while (hasA && hasB) {
        if (a <= b) { fpOut << a << " "; hasA = static_cast<bool>(fp1 >> a); }
        else { fpOut << b << " "; hasB = static_cast<bool>(fp2 >> b); }
    }
    while (hasA) { fpOut << a << " "; hasA = static_cast<bool>(fp1 >> a); }
    while (hasB) { fpOut << b << " "; hasB = static_cast<bool>(fp2 >> b); }
}

int main()
{
	std::cout << "Hello CMake." << std::endl;
	return 0;
}
