#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, x;
    cin >> a >> b >> c >> d >> x;
    if (a <= x && x < b) cout << 1;
    // else if (c < x && x <= d) cout << 2;
    else cout << 0;
    return 0;
}