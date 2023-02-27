#pragma once

#include "Parameters.h"

class Compressor {
public:
    Compressor(const Parameters& parameters);

    void reset();
    double computeRelativeOutput(double input, double& gainReduction);
private:
    const Parameters& parameters;

    double gainK = 0.0;
    double drive = 0.0;
    double mix = 0.0;
    double makeup = 0.0;
    double highPassD = 0.0;
    double logSpeed = 0.0;
    double env = 0.0;
};
