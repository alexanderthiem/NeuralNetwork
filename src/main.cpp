#include <iostream>
#include "Network.h"
#include <time.h>
#include <stdlib.h>


using namespace std;


int main()
{

    int nN=3;
    double *inputs= new double[nN];
    srand(time(0));
    double *n=new double[nN];
    double *outputdesired= new double[nN];

    //for(int i=0;i<nN;i++)
    //outputdesired[i]=0.3;
    inputs[0]=1;
    inputs[1]=1;
    inputs[2]=1;


    Network network(2,nN,nN);
    double *output= new double[nN];
    srand(time(0));
    network.calc(inputs);
    outputdesired[0]=0;
    outputdesired[1]=0;
    outputdesired[2]=1;
    for(int i=0;i<10000;i++)
    {

        network.learn(outputdesired,inputs);
        inputs[0]=int(rand()%2);
        inputs[1]=int(rand()%2);
        inputs[2]=int(rand()%2);
        network.calc(inputs);
        outputdesired[0]=0;
        outputdesired[1]=0;
        outputdesired[2]=0;
        if(inputs[0]&&inputs[1]&&inputs[2])
            outputdesired[2]=1;
        else if((inputs[0]&&(inputs[1]||inputs[2]))||(inputs[1]&&inputs[2]))
            outputdesired[1]=1;
        else if(inputs[0]||inputs[1]||inputs[2])
            outputdesired[0]=1;

    }
    cout << inputs[0]<<"  "<< inputs[1]<<"  "<< inputs[2]<<"  "<< endl;
    output=network.getoutput();
    for(int i=0;i<nN;i++)
        cout << output[i] << "  ";
    cout << "\n\n";
    network.status();

    return 0;
}
