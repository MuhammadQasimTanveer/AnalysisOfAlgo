#include <iostream>
#include <iomanip>

using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 10;
    cout << "Fibonacci number at index " << n << " is " << fibonacci(n) << endl;
    return 0;
}

