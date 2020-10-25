#include "Layer.h"
#include <iostream>


Layer::Layer()
{

}

Layer::~Layer()
{
    //dtor
}

//initializes the Layer and its Neurons
void Layer::initialize(int nN,Layer previous) 
{
    //saves the number of the Neurons
    nneurons=nN;
    //constructs the Neurons
    neurons=new Neuron[nN];
    //i goes through all Neurons
    for(int i=0;i<nN;i++)
        //each Neuron is initialized
        neurons[i].initialize(previous.getnneurons(),previous.getNeurons());
}

//makes all Neurons calc
void Layer::calc()
{
    //i goes through every Neuron
    for (int i=0;i<nneurons;i++)
    {
        neurons[i].calc();
    }
}

//returns the number of Neurons in this layer
int Layer::getnneurons()
{
    return nneurons;
}

//lets all Neuron learn
void Layer::learn()
{
    //i goes through all Neurons
    for(int i=0;i<nneurons;i++)
        //and makes them learn
        neurons[i].learn();
}

double** Layer::getwIs()
{
    double** res =new double*[nneurons];
    for(int i=0;i<nneurons;i++)
        res[i]=neurons[i].getwI();
    return res;
}
