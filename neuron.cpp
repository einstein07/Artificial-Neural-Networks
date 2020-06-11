/* 
 * File:   ann.cpp
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:50
 */
#include "ann.h"
//------------------------------------------------------------------------------
//FUNCTION DEFS
//------------------------------------------------------------------------------
//Default constructor
MKHSIN035::neuron::neuron():prev_neurons(0){}

//Constructor
MKHSIN035::neuron::neuron(int prev_neurons, double weights[]):prev_neurons(prev_neurons){
    for(int i = 0; i < prev_neurons; i++){
        this->weights.push_back(weights[i]);
    }
}

int MKHSIN035::neuron::activation_fn(const std::vector<int> inputs){
    double sum = 0.0;
    std::cout<<"In activation: "<<inputs[0]<<" "<<inputs[1]<<" "<<weights[2]<<std::endl;
    for(int i = 0; i < prev_neurons; i++){
        sum += weights[i]*inputs[i];
    }
    this->output = (sum>0?1:0);
    return output;
}
      
std::vector<double> MKHSIN035::neuron::get_weights(){return this->weights;}
      
void MKHSIN035::neuron::set_weights(std::vector<double> weights){
    for(int i = 0; i < prev_neurons; i++){
        this->weights[i] = weights[i];
    }
}
//------------------------------------------------------------------------------
//EOF
//------------------------------------------------------------------------------


