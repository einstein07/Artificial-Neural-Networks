/* 
 * File:   ann.cpp
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:50
 */
#include "ann.h"

//Default constructor
MKHSIN035::neuron::neuron():n_prev_neurons(0), theta(0){}

//Constructor
MKHSIN035::neuron::neuron(int n_prev_neurons, double theta):n_prev_neurons(n_prev_neurons), theta(theta){
    srand (time(NULL));
    for(int i = 0; i < n_prev_neurons; i++){
        double w= ((double) rand() / (RAND_MAX));
        this->weights.push_back(w);
    }
}

int MKHSIN035::neuron::activation_fn(const double inputs[]){
    double sum = 0.0;
    for(int i = 0; i < this->n_prev_neurons; i++){
        sum += this->weights[i]*inputs[i];
    }
    this->output = (sum>theta?1:0);
    return output;
}
      
int MKHSIN035::neuron::get_output(){return this->output;}
      
void MKHSIN035::layer::learn(double input[], double t){
    int y = activation_fn(input);
            
    while(y != t){
        for (int i = 0; i < this->n_prev_neurons; i++){
                        
            std::cout<<"It "<<(i+1)<<" Weight: "<<weights[i]<<" ";
            this->weights[i] = weights[i] + (t-y) * input[i];

        }
        y = activation_fn(input);
        std::cout<<std::endl;
    }
    std::cout<<weights[0]<<" "<<weights[1]<<std::endl;
    //return true;
}


