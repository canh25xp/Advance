#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio> 

using namespace std;


int main() {
    FILE* input;
    errno_t error = freopen_s(&input, "input.txt", "r", stdin);
    if (error)
        exit(EXIT_FAILURE);

    fclose(input);

    return 0;
}
