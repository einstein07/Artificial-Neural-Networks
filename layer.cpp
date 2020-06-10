/* 
 * File:   layer.cpp
 * Author: Sindiso
 *
 * Created on 10 June 2020, 23:50
 */
//------------------------------------------------------------------------------
//includes
//------------------------------------------------------------------------------
#include "ann.h"
//------------------------------------------------------------------------------
//Function definitions
//------------------------------------------------------------------------------
//Default constructor
MKHSIN035::layer::layer():prev_neurons(0){}
//Constructor
MKHSIN035::layer::layer(int prev_neurons, int neurons):prev_neurons(prev_neurons+1), neurons_n(neurons){
    double rand_w[this->prev_neurons];
    srand (time(NULL));
    for (int i = 0; i < neurons_n; i++){ 
        for(int j = 0; j < this->prev_neurons; j++){
            rand_w[j]= ((double) rand() / (RAND_MAX));
        }
        neuron n(this->prev_neurons, rand_w);
        neurons.push_back(n);
    }
}
std::vector<int> MKHSIN035::layer::activate(vector<int> inputs){
    std::vector<int> values;
    if(neurons[0].get_weights().size() != inputs.size()){
        values.reserve(inputs.size()+1);
        values[0] = 1;
        for(int i = 1; i <= inputs.size(); i++){
            values[i] = inputs[i];
        }
    }else{
        values = inputs;
    }
    for(int i = 0; i < neurons_n; i++){
        outputs.push_back(neurons[i].activation_fn(values));
    }
    return this->outputs;
}
void MKHSIN035::layer::learn(double input[], double t){
    int y = activation_fn(input);
            
    while(y != t){
        for (int i = 0; i < this->n_prev_neurons; i++){
                        
            //std::cout<<"It "<<(i+1)<<" Weight: "<<weights[i]<<" ";
            this->weights[i] = weights[i] + (t-y) * input[i];

        }
        y = activation_fn(input);
        std::cout<<std::endl;
    }
    std::cout<<weights[0]<<" "<<weights[1]<<std::endl;
    //return true;
}
std::vector<double> get_weights(int i){return neurons[i].get_weights();}
