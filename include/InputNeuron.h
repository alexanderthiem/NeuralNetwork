#include "Neuron.h"
#ifndef INPUTNEURON_H
#define INPUTNEURON_H

class InputNeuron : Neuron
{
    public:
        //the constructor(not used)
        InputNeuron();
        //the destructor (not used)
        virtual ~InputNeuron();
        
        //initializes the Neuron through giving him the number of Neurons in the previous layer
        void initialize(int nI,double* inputs);
        
        //adds the pointers to the Neurons of the next Layer
        void addnext(Neuron *other,int n);

        //returns an pointer to the activations
        double* getactivations();

        //returns nT
        int getnT();
        
    protected:

    private:
        //Number of Training examples
        int nT;
        
        //The activations from this Neuron
        //First Dimension is for the nth Trainingsexample
        double* activations;

        //Pointer to the Neurons of the next Layer
        Neuron *next;

        //stores the number of Neurons in the next Layer
        int nnext;

        //number of input for the next Layer
        int* pos;
};



#endif // INPUTNEURON_H