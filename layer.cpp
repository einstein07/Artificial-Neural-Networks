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
    for(int i = 0; i < neurons_n; i++){
        int y = neurons[i].activation_fn(inputs);
        output.push_back(y);
    }
    return output;
}
void MKHSIN035::layer::learn(int index, MKHSIN035::data examples){

    double done = false;

    int c = 0;
    while(c != 8){
        done = true;
        for(auto entry:examples){
            //if(enr)
            //done = true;
            //std::cout<<entry.second<<" "<<entry.first[0]<<" "<<entry.first[1]<<std::endl;
            std::vector<double> weights = neurons[index].get_weights();
            std::vector<int> ex = entry.first;
            int t = entry.second;
            int y = neurons[index].activation_fn(ex);
            
            while(true){
                if(y == t)
                    break;

                for (int i = 0; i < this->prev_neurons; i++){
                    if(i == 0)
                        weights[i] += 0.009*(t-y);
                    else
                        weights[i] += 0.009*(t-y) * ex[i-1];
                }
                neurons[index].set_weights(weights);
                y = neurons[index].activation_fn(ex);
            }
            
            

   
        }
        c++;
        
    }   
    
}
std::vector<double> MKHSIN035::layer::get_weights(int i){return neurons[i].get_weights();}
      
int MKHSIN035::layer::get_n_neurons(){return this->neurons.size();};
