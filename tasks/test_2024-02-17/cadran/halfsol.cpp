#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (y > 0) {
        if (x > 0) cout << "I";
        // else cout << "II";
    } else {
        if (x < 0) cout << "III";
        // else cout << "IV";
    }
    return 0;
}