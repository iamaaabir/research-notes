#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double percentageFlip(int);

int main()
{
    unsigned int seed = time(0);
    srand(seed);

    int N;

    const int SIZE = 6;
    int sizes[SIZE] = {10, 100, 1000, 10000, 100000, 1000000};

    for (int i = 0; i < SIZE; i++)
    {
        N = sizes[i];
        cout << "N = " << N << endl;

        for (int run = 0; run < 10; run++)
        {
            double percentHeads = percentageFlip(N);
            cout << "Run " << run + 1 << ": " << percentHeads << "% heads" << endl;
        }
    }

    return 0;
}

double percentageFlip(int N)
{
    int headsCount = 0;

    for (int i = 0; i < N; i++)
    {
        int flip = rand() % 2; // 0 for tails, 1 for heads
        if (flip == 1)
        {
            headsCount++;
        }
    }

    return (static_cast<double>(headsCount) / N) * 100.0;   

}