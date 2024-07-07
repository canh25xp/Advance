#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define DEFAULT_TEST_CASE 10

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TEST_CASE = DEFAULT_TEST_CASE;
    //cin >> TEST_CASE;
    for (int case_index = 0; case_index < TEST_CASE; case_index++) {

        cout << "Case #" << case_index + 1 << endl;
    }

    return 0;
}