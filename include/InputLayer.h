#include "Layer.h"
#ifndef INPUTLayer_H
#define INPUTLayer_H
#include "Neuron.h"
#include "InputNeuron.h"

class InputLayer : Layer
{
    public:
        InputLayer();
        virtual ~InputLayer();
        //initializes the Layer with the Number of Neurons in this Layer
        void initialize(int nN);
        //returns the number of Neurons
        int getnneurons();
        //returns an pointer to the Neurons
        Neuron* getNeurons(); 
        //makes all Neurons Learn
        void learn();
        //returns an pointer to the wIs
        double** getwIs();

    protected:

    private:
        //the Neurons of this Layer
        Neuron *neurons;
        //the number of those
        int nneurons;
};

#endif // Layer_H
