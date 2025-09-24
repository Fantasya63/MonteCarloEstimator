#pragma once
#include <cstdint>

double MonteCarlo(uint64_t numSamples, double(*probabilityDensityFunction)(double), double(*functionToIntegrate)(double), double(*sampler)());
