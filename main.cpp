
/* 
 * File:   main.cpp->Driver file
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:09
 */
#include "ann.h"
#include <cstdlib>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    double x[] = {0.1,-9};
    double t = 0; 
    MKHSIN035::neuron n(2, 0.5);
    if(n.learn(x,t))std::cout<<"Done learning: "<<n.get_output()<<endl;
    
    return 0;
}

