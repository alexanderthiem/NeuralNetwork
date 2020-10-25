#include "Network.h"
#include "Layer.h"
#include <iostream>

Network::Network(int nL, int nN, int nXi)
{
    nNeurons=nN;
    nLayer=nL;
    layers= new Layer[nL];
    for(int i=0; i<nL;i++)
    {
        layers[i].initialize(nN,nXi);
        activations[i] = new double[3*nN];
        activations[i] = &activations[i][2*nN];
    }
}

Network::~Network()
{
    //dtor
}

void Network::calc(double *inputs)
{
    layers[0].calc(inputs);
    activations[0]=layers[0].getactivations();
    for(int i=1;i<nLayer;i++)
    {
        layers[i].calc(activations[i-1]);
        activations[i]=layers[i].getactivations();
    }
}



void Network::learn(double *outputs,double inputs[])
{
    double *Fehler=new double[nNeurons];
    //std::cout << outputs[0] <<"-"<< activations[nLayer-1][0];
    for(int i=0;i<nNeurons;i++)
        Fehler[i]=double(outputs[i])-double(activations[nLayer-1][i]);
    double *Fehler2=new double[nNeurons];
    for(int i=nLayer-1;i>0;i--)
    {
        layers[i].learn(Fehler,activations[i-1]);
        for(int j=0;j<nNeurons;j++)
        {
            Fehler2[j]=Fehler[j];
            Fehler[j]=0;
        }
        for(int j=0;j<nNeurons;j++)
        {
            for(int k=0;k<nNeurons;k++)
                Fehler[j]+=0.1*(Fehler2[k]*layers[i].getwIs()[k][j])/double(nNeurons);
        }
    }
    layers[0].learn(Fehler,inputs);
}

double* Network::getoutput()
{
    return activations[nLayer-1];
}

void Network::status()
{
    for(int i=0;i<nLayer;i++)
    {
        for(int j=0;j<nNeurons;j++)
        {
            for(int k=0;k<nNeurons;k++)
                std::cout<< layers[i].getwIs()[j][k] << "  ";
            std::cout << "\n";
        }
        std::cout << "\n"<< "\n"<< "\n";
    }
}
