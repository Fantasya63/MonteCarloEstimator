#include "utils.h"

#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

double SamplingProbability(double x)
{
    // The domain is in the range [-1, 1] so each sample has a prob of 1/2
    // This function is also caled the Probability Density Function
    return 0.5;
}

double SemiCirle(double x)
{
    return sqrt(1.0 - (x * x));
}

static std::mt19937_64 randomGenerator{(uint32_t) std::chrono::high_resolution_clock::now().time_since_epoch().count()};
double GetRandomSample()
{
    std::uniform_real_distribution distribution(-1.0, 1.0);
    return distribution(randomGenerator);
}


int main ()
{
    for (uint64_t i = 1; i <= 1000000000; i *= 10)
    {
        std::cout << "Num of Samples: " << std::setfill('-') << std::setw(10) << i 
            << " - PI is approximately : " << MonteCarlo(i, SamplingProbability, SemiCirle, GetRandomSample) * 2.0 << "\n";
    }
    
}