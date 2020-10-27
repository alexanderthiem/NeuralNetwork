#include "OutputNeuron.h"
#include "stdlib.h"
#include <iostream>
#include <math.h>


OutputNeuron::OutputNeuron()
{}

OutputNeuron::~OutputNeuron()
{
    delete[] wI;
}

//This Funktion Initializes the OutputNeuron with the Number of OutputNeurons from the next Layer and Pointers to all this OutputNeurons
void OutputNeuron::initialize(int n,Neuron *pPrevious)
{
    //Number of Neurons of the last Layer=Number of inputs
    nI=n;

    //There is one wheight for every Input and one Bias
    wI=new double[n+1];
    
    previous=new OutputNeuron[n];
    //goes through all weights
    for(int i=0;i<n+1;i++)
    {
        if(i<n)
            //Stores the pointers
            previous[i]=pPrevious[i];
        
        //initalizes the OutputNeurons wheights to random
        wI[i]=double(rand()%10)/10.0;
    }

    //sets Leanrate to 0.01
    Learnrate=0.01;
}

//The OutputNeuron takes the Inputs (from the Last Layer) and calculates the Outputs
void OutputNeuron::calc()
{
    nT=previous[0].getnT();
    //sum stores the sum of all Trainingsexamples
    double* sum=new double[nT];

    //i goes through all OutputNeurons of the previous Layer
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

double* OutputNeuron::getactivations()  //returns the activation from the OutputNeuron
{
    return activations;
}

//Stores suggested Output
void OutputNeuron::addnext(double* psuggested,int n)
{
    nsuggested=n;
    suggested=new double[n];
    //i goes through all Neurons of next Layer
    for(int i=0;i<n;i++)
    {
        suggested[i]=psuggested[i];
    }
}

//improves the wheights
void OutputNeuron::learn()
{
    //i goes through all Training examples
    Fehler=new double[nT];
    for(int i=0;i<nT;i++)
    {
        //Fehler is set to squared error
        Fehler[i]=(activations[i]-suggested[i])*(activations[i]-suggested[i]);
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



double* OutputNeuron::getwI() //returns weights
{
    return wI;
}

double* OutputNeuron::getFehler() //returns Fehler
{
    return Fehler;
}

int OutputNeuron::getPos(Neuron* other) //calculates, which number of wheight fits to the OutputNeuron other
{
    for(int i=0;i<nI;i++)
    {
        if((previous+i)==other)
        return i;
    }
    return -1;
}

void OutputNeuron::setlearnrate(double plearnrate) //change the Learnrate here
{
    Learnrate=plearnrate;
}