#include <fstream>
#include <random>
#include <string>

const int NUMTESTS = 10;

int solve(int x) {
    int aux = x % 100;
    x /= 1000;
    return x * 100 + aux;
}

int main() {
    std::random_device rd;                            // obtain a random number from hardware
    std::mt19937 gen(rd());                           // seed the generator
    std::uniform_int_distribution<> distr(1000, 1e9); // define the range

    for (int i = 0; i < NUMTESTS; ++i) {
        std::string infilename = "input/input" + std::to_string(i) + ".txt";
        std::ofstream inf(infilename);

        std::string outfilename = "output/output" + std::to_string(i) + ".txt";
        std::ofstream outf(outfilename);

        int a = distr(gen);
        inf << a;
        outf << solve(a);
    }
    return 0;
}