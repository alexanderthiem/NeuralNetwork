#include "Neuron.h"
#ifndef OUTPUTNEURON_H
#define OUTPUTNEURON_H

class OutputNeuron :Neuron
{
    public:
        //the constructor(empty)
        OutputNeuron();
        //the destructor 
        ~OutputNeuron();
        
        //initializes the Neuron through giving him the number of Neurons in the previous layer
        void initialize(int n,Neuron* pPrevious);
        
        //adds the suggested output of the Network
        void addnext(double *psuggested,int n);

        //calculates the activations and stores them in activations
        void calc();

        //returns an pointer to the activations
        double* getactivations();

        //improves the weights
        void learn();
        
        //returns the wheights
        double* getwI();

        //returns Fehler
        double* getFehler();

        //finds out the pos and returns it
        int getPos(Neuron* other);

        //setlearnrate
        void setlearnrate(double plearnrate);
        
    protected:

    private:
        //Number of Training examples
        int nT;
        
        //The Inputs from the previous layer
        //First Dimension is for the nth Trainingsexample and second for the nth Neuron
        double** inputs;

        //The activations from this Neuron
        //First Dimension is for the nth Trainingsexample
        double* activations;

        //The mistakes this Neuron did
        //First Dimesnion is for the Nth Trainingsexample
        double* Fehler;

        //The weights from this Neuron
        //The first Dimension is for the nth Neuron
        double *wI;

        //The Number of Inputs from the last layer
        int nI;

        //Pointer to the Neurons of the previous Layer
        Neuron *previous;

        //The suggested output
        double* suggested;
        int nsuggested;

        //learnrate stores how fast the Neuron should learn
        double Learnrate;
};

#endif // NEURON_H
