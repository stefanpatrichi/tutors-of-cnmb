#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const int NUMTESTS = 20;

int main() {
    std::random_device rd;                            // obtain a random number from hardware
    std::mt19937 gen(rd());                           // seed the generator
    std::uniform_int_distribution<> distr(-1e9, 1e9); // define the range
    int m = 0, n = 0, p = 0;
    for (int i = 0; i < NUMTESTS; ++i) {
        std::string infilename = "input/input" + std::to_string(i) + ".txt";
        std::ofstream inf(infilename);

        std::string outfilename = "output/output" + std::to_string(i) + ".txt";
        std::ofstream outf(outfilename);

        std::vector<int> testcase(5);
        for (auto &x : testcase) x = distr(gen);
        std::sort(testcase.begin(), testcase.begin() + 4);
        for (auto x : testcase) inf << x << ' ';
        int a = testcase[0], b = testcase[1], c = testcase[2], d = testcase[3], x = testcase[4];
        if (a <= x && x < b) outf << 1, ++m;
        else if (c < x && x <= d) outf << 2, ++n;
        else outf << 0, ++p;
    }
    std::cout << m << ' ' << n << ' ' << p << '\n';
    return 0;
}