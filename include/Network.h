#ifndef NETWORK_H
#define NETWORK_H
#include "LAYER.H"

class Network
{
    public:
        Network(int nL, int nN, int nXi);
        virtual ~Network();
        void calc(double inputs[]);
        void learn(double *outputs, double inputs[]);
        double *getoutput();
        void status();

    protected:

    private:
        Layer *layers;
        int nLayer;
        int nNeurons;
        double *activations[];
};

#endif // NETWORK_H
