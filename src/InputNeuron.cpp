#include "InputNeuron.h"

InputNeuron::InputNeuron()
{

}

InputNeuron::~InputNeuron()
{

}

void InputNeuron::initialize(int nI,double* inputs)
{
    nT=nI;
    for(int i=0;i<nT;i++)
    {
        activations[i]=inputs[i];
    }
}

void InputNeuron::addnext(Neuron *other,int n)
{
    nnext=n;
    for(int i=0;i<nnext;i++)
    {
        next[i]=other[i];
    }
}