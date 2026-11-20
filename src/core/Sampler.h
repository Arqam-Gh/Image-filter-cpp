#ifndef SAMPLER_H
#define SAMPLER_H

#include <string>
using namespace std;

class Sampler {
private:
    string samplerID;
    string sampleData;

public:
    Sampler();
    ~Sampler();
    
    string getSamplerID();
    void setSamplerID(string id);
    string getSampleData();
    void setSampleData(string data);
    void takeSample();
};

#endif
