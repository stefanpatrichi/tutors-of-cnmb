#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int mini = a;

    if (b < mini) mini = b;
    if (c < mini) mini = c;
    if (d < mini) mini = d;
    if (e < mini) mini = e;

    cout << mini;
    return 0;
}