#include "utils.h"

double MonteCarlo(uint64_t numSamples, double(*probabilityDensityFunction)(double), double(*functionToIntegrate)(double), double(*sampler)())
{
    // Get the expected value of 1/n (summation of (f(x)/p(x)))
    double sum = 0.0;
    double one_over_n = 1.0 / numSamples;

    for (int i = 0; i < numSamples; i++)
    {
        double rand = sampler();
        sum += functionToIntegrate(rand) / probabilityDensityFunction(rand);
    }

    return one_over_n * sum;
}