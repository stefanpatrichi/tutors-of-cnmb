#include <fstream>
#include <random>
#include <string>

const int NUMTESTS = 10;

int main() {
    std::random_device rd;                            // obtain a random number from hardware
    std::mt19937 gen(rd());                           // seed the generator
    std::uniform_int_distribution<> distr(0, 100000); // define the range

    for (int i = 0; i < NUMTESTS; ++i) {
        std::string infilename = "input/input" + std::to_string(i) + ".txt";
        std::ofstream inf(infilename);

        std::string outfilename = "output/output" + std::to_string(i) + ".txt";
        std::ofstream outf(outfilename);

        int a = distr(gen), b = distr(gen);
        inf << a << ' ' << b;
        outf << a + b;
    }
    return 0;
}