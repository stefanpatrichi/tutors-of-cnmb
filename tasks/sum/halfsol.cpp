#include <fstream>

int main() {
    std::ifstream fin("sum.in");
    std::ofstream fout("sum.out");
    int a, b;
    fin >> a >> b;
    fout << a + b + (a + b) % 2;
}