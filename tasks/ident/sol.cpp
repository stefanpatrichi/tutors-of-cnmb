#include <iostream>
using namespace std;

int main() {
    int a, aux;
    cin >> a;
    aux = a % 100;
    a /= 1000;
    a = a * 100 + aux;
    cout << a;
    return 0;
}