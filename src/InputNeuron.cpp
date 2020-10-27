#include "InputNeuron.h"

InputNeuron::InputNeuron()
{
}

InputNeuron::~InputNeuron()
{
}

void InputNeuron::initialize(int pnT,double* inputs)
{
    nT=pnT;
    for(int i=0;i<nT;i++)
    {
        activations[i]=inputs[i];
    }
}

void InputNeuron::addnext(Neuron *pNext,int n)
{
    nnext=n;
    for(int i=0;i<nnext;i++)
    {
        next[i]=pNext[i];
    }
}