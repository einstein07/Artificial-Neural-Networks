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
MKHSIN035::layer::layer(int prev_neurons_n, int neurons):prev_neurons(prev_neurons_n+1), neurons_n(neurons){
    double rand_w[prev_neurons_n+1];
    srand (time(NULL));
    for (int i = 0; i < neurons_n; i++){ 
        for(int j = 0; j < this->prev_neurons; j++){
            rand_w[j]= ((double) rand() / (RAND_MAX));
            //std::cout<<"rand: "<<rand_w[j]<<std::endl;
        }
        neuron n(prev_neurons_n+1, rand_w);
        this->neurons.push_back(n);
    }
    
}
std::vector<int> MKHSIN035::layer::activate(std::vector<int> inputs){
    std::vector<int> output;
    std::vector<int> values;
    if(neurons[0].get_weights().size() != inputs.size()){
        values.push_back(1);
        for(int i = 0; i <= inputs.size(); i++){
            values.push_back(inputs[i]);
        }
    }else{
        values = inputs;
    }
    for(int i = 0; i < neurons_n; i++){
        int y = neurons[i].activation_fn(values);
        output.push_back(y);
    }
    return output;
}
void MKHSIN035::layer::learn(int index, std::vector<int> inputs, double t){
    std::vector<int> values;
    if(neurons[index].get_weights().size() != inputs.size()){
                
        values.push_back(1);
        for(int i = 0; i <= inputs.size(); i++){
            values.push_back(inputs[i]);
        }
    }else{
        values = inputs;
    }
    std::vector<double> weights = neurons[index].get_weights();
    int y = neurons[index].activation_fn(values);
                

    //weights[0] = -1.5;
    while(true){
        if(y == t)
            break;
        
        for (int i = 0; i < this->prev_neurons; i++){
            weights[i] += 0.009*(t-y) * values[i];
        }
        neurons[index].set_weights(weights);
        y = neurons[index].activation_fn(values);
    }
    //return true;
}
std::vector<double> MKHSIN035::layer::get_weights(int i){return neurons[i].get_weights();}
      
int MKHSIN035::layer::get_n_neurons(){return this->neurons.size();};
