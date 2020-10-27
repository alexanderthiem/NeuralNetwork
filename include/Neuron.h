#ifndef NEURON_H
#define NEURON_H
#include "Matrix.h"

class Neuron
{
    public:
        //the constructor(not used)
        Neuron();
        //the destructor (not used)
        virtual ~Neuron();
        
        //initializes the Neuron through giving him the number of Neurons in the previous layer
        void initialize(int n,Neuron* pbefore);
        
        //adds the pointers to the Neurons of the next Layer
        void addnext(Neuron *other,int n);
        
        //calculates the activations and stores them in activations
        void calc();

        //returns an pointer to the activations
        double* getactivations();
        
        //improves the weights
        void learn();
        
        //returns the wI
        double* getwI();

        //returns nT
        int getnT();

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

        //Pointer to the Neurons of the previous and next Layer
        Neuron *previous;
        Neuron *next;

        //stores the number of Neurons in the next Layer
        int nnext;

        //number of input for the next Layer
        int* pos;
        /*was ist das denn für ein komisches Englisch?
        ich würde auch nur eine einfach verkettete Liste machen*/

        //learnrate stores how fast the Neuron should learn
        double Learnrate;
};

#endif // NEURON_H
