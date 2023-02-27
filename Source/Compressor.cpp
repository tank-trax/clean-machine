#include "Compressor.h"

Compressor::Compressor(const Parameters& parameters)
: parameters(parameters) {}

void Compressor::reset() {
    drive = parameters.driveTarget;
    mix = parameters.mixTarget;
    makeup = parameters.makeupTarget;
    logSpeed = (parameters.logAttack + parameters.logRelease) * 0.5;
    env = 0.0;
    highPassD = 0.0;
}

double Compressor::computeRelativeOutput(double input, double& gainReduction) {
    drive += parameters.gainK * (parameters.driveTarget - drive);
    mix += parameters.gainK * (parameters.mixTarget - mix);
    makeup += parameters.gainK * (parameters.makeupTarget - makeup);

    highPassD += parameters.highPassK * (input - highPassD);
    input -= highPassD;
    double abs = std::abs(input);

    double logTarget = abs > env ? parameters.logAttack : parameters.logRelease;
    logSpeed += parameters.transition * (logTarget - logSpeed);
    double speed = std::exp2(logSpeed);
    env += speed * (abs - env);

    double satInput = env * drive;
    double relative = 1.0 / std::sqrt(satInput * satInput + 1.0);

    double mixed = 1.0 - mix + mix * relative;
    if (mixed < gainReduction) gainReduction = mixed;
    return mixed * makeup;
}
