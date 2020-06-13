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
    std::vector<int> values;
    if(neurons[0].get_weights().size() != inputs.size()){
        values.push_back(1);
        for(int i = 0; i <= inputs.size(); i++){
            values.push_back(inputs[i]);
        }
    }else{
        values = inputs;
    }
    //std::cout<<values[0]<<" "<<values[1]<<" "<<values[2]<<std::endl;
    for(int i = 0; i < neurons_n; i++){
        outputs.push_back(neurons[i].activation_fn(values));
    }
    return this->outputs;
}
void MKHSIN035::layer::learn(int i, std::vector<int> inputs, double t){
    std::vector<int> values;
    if(neurons[0].get_weights().size() != inputs.size()){
                
        values.push_back(1);
        for(int i = 0; i <= inputs.size(); i++){
            values.push_back(inputs[i]);
        }
    }else{
        values = inputs;
    }
    std::vector<double> weights = neurons[i].get_weights();
    int y = neurons[i].activation_fn(values);
                


    while(y != t){
        //Bias term
        for (int i = 0; i < this->prev_neurons; i++){
            weights[i] = weights[i] + 0.001*(t-y) * values[i];
        }
            
        neurons[i].set_weights(weights);

        y = neurons[i].activation_fn(values);
        //std::cout<<std::endl;
    }
    //return true;
}
std::vector<double> MKHSIN035::layer::get_weights(int i){return neurons[i].get_weights();}
      
int MKHSIN035::layer::get_n_neurons(){return this->neurons.size();};
