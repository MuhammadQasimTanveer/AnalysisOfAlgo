#include <iostream>
#include <iomanip>

using namespace std;

void nestedLoops(int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n ; j++) {
            cout << " * ";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    cout<<endl<<endl;
	nestedLoops(n);
    return 0;
}

