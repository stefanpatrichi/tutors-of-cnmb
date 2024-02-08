#include <fstream>
#include <random>
#include <string>

const int NUMTESTS = 40;

int main() {
    std::random_device rd;                            // obtain a random number from hardware
    std::mt19937 gen(rd());                           // seed the generator
    std::uniform_int_distribution<> distr(-1e9, 1e9); // define the range

    for (int i = 0; i < NUMTESTS; ++i) {
        std::string infilename = "input/input" + std::to_string(i) + ".txt";
        std::ofstream inf(infilename);

        std::string outfilename = "output/output" + std::to_string(i) + ".txt";
        std::ofstream outf(outfilename);

        int x, y;
        do x = distr(gen);
        while (x == 0);
        do y = distr(gen);
        while (y == 0);
        inf << x << ' ' << y;

        if (x > 0 && y > 0) outf << "I";
        else if (x < 0 && y > 0) outf << "II";
        else if (x < 0 && y < 0) outf << "III";
        else if (x > 0 && y < 0) outf << "IV";
    }
    return 0;
}