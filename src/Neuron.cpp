#include "Neuron.h"
#include "stdlib.h"
#include <iostream>
#include <math.h>


Neuron::Neuron()
{}

Neuron::~Neuron()
{
    delete[] wI;
}

//This Funktion Initializes the Neuron with the Number of Neurons from the next Layer and Pointers to all this Neurons
void Neuron::initialize(int n,Neuron *pPrevious)
{
    //Number of Neurons of the last Layer=Number of inputs
    nI=n;

    //There is one wheight for every Input and one Bias
    wI=new double[n+1];
    
    previous=new Neuron[n];
    //goes through all weights
    for(int i=0;i<n+1;i++)
    {
        if(i<n)
            //Stores the pointers
            previous[i]=pPrevious[i];
        
        //initalizes the Neurons wheights to random
        wI[i]=double(rand()%10)/10.0;
    }

    //sets Leanrate to 0.01
    Learnrate=0.01;
}

//Stores pointers to the Neurons of the next Layer
void Neuron::addnext(Neuron *pNext,int n)
{
    nnext=n;
    next=new Neuron[n];
    //i goes through all Neurons of next Layer
    for(int i=0;i<n;i++)
    {
        next[i]=pNext[i];
        pos[i]=next[i].getPos(this);
    }
}

//The Neuron takes the Inputs (from the Last Layer) and calculates the Outputs
void Neuron::calc()
{
    nT=previous[0].getnT();
    //sum stores the sum of all Trainingsexamples
    double* sum=new double[nT];

    //i goes through all Neurons of the previous Layer
    for(int i=0;i<nI;i++)
    {
        double* ptr=previous[i].getactivations();
        //j goes through all Trainingsexampels
        for(int j=0;j<nT;j++)
        {
            //and stores all of their activations in Inputs
            inputs[j][i]=ptr[j];
        }
    }
    //i goes through all Trainingexamples
    for(int i=0;i<nT;i++)
    {
        sum[i]=0;
        //j goes through all Inputs
        for(int j=0;j<nI;j++)
        {
            //sums up all inputs multiplied with their wheight
            sum[i]+=inputs[i][j]*wI[j];
        }
        //adds the Bias
        sum[i]+=wI[nI];
    }

    //i goes through all Training Examples
    for(int i=0;i<nT;i++)
    //and calculates the activations
    activations[i]=1/(1+pow( 2.718281828459,(-sum[i])));
}

double* Neuron::getactivations()  //returns the activation from the Neuron
{
    return activations;
}

//improves the wheights
void Neuron::learn()
{
    //i goes through all Training examples
    Fehler=new double[nT];
    for(int i=0;i<nT;i++)
    {
        //Fehler is set to 0
        Fehler[i]=0;
    }
    //i goes through all Neurons from the next Layer
    for(int i=0;i<nnext;i++)
    {
        double* ptr1=next[i].getFehler();
        double* ptr2=next[i].getwI();
        //j goes through all Training examples
        for(int j=0;j<nT;j++)
        {
            Fehler[j]+=0.1*ptr1[j]*ptr2[pos[i]];
        }
    }
    //j goes through all Trainingexamples
    for(int j=0;j<nT;j++)
    {
        //i goes through all wheights
        for(int i=0;i<nI;i++)
        {
            wI[i]+=(activations[j])*(1-activations[j])*Learnrate*Fehler[j]*inputs[j][i];
        }
        //and the bias
        wI[nI]+=(activations[j])*(1-activations[j])*Learnrate*Fehler[j]*1;
    }
}



double* Neuron::getwI() //returns weights
{
    return wI;
}

int Neuron::getnT()//returns number of Trainingexamples
{
    return nT;
}

double* Neuron::getFehler() //returns Fehler
{
    return Fehler;
}

int Neuron::getPos(Neuron* other) //calculates, which number of wheight fits to the Neuron other
{
    for(int i=0;i<nI;i++)
    {
        if((previous+i)==other)
        return i;
    }
    return -1;
}

void Neuron::setlearnrate(double plearnrate) //change the Learnrate here
{
    Learnrate=plearnrate;
}