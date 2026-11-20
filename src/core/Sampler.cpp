#include "Sampler.h"
#include <iostream>
using namespace std;

Sampler::Sampler() : samplerID(""), sampleData("") {
}

Sampler::~Sampler() {
}

string Sampler::getSamplerID() {
    return samplerID;
}

void Sampler::setSamplerID(string id) {
    samplerID = id;
}

string Sampler::getSampleData() {
    return sampleData;
}

void Sampler::setSampleData(string data) {
    sampleData = data;
}

void Sampler::takeSample() {
}
