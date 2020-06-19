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
//------------------------------------------------------------------------------
//Constructor used for implementing PART 1:
//------------------------------------------------------------------------------
MKHSIN035::layer::layer(int prev_neurons_n, int neurons):prev_neurons(prev_neurons_n+1), neurons_n(neurons){
    double rand_w[prev_neurons];
    srand (time(NULL));
    for (int i = 0; i < neurons_n; i++){ 
        for(int j = 0; j < this->prev_neurons; j++){
            rand_w[j]= ((double) rand() / (RAND_MAX));
        }
        neuron n(prev_neurons_n+1, rand_w);
        this->neurons.push_back(n);
    }
    
}
//------------------------------------------------------------------------------
//Constructor used to implement PART 2
//------------------------------------------------------------------------------
MKHSIN035::layer::layer(int prev_neurons_n, int neurons, const std::vector<double> weights, std::vector<double> bias):prev_neurons(prev_neurons_n+1), neurons_n(neurons){
    //An array for weights
    double w [prev_neurons];
    //This constant indexes the input weights vector
    int index = 0;
    for (int i = 0; i < neurons_n; i++){ 
        for(int j = 0; j < this->prev_neurons; j++){
            //Insert bias weight
            if(j == 0)
                w[j]= bias[i];
            else{
                w[j] = weights[index];
                index += 1;
            }
        }
        neuron n(prev_neurons, w);
        this->neurons.push_back(n);
    }
}

std::vector<int> MKHSIN035::layer::threshold_activate(std::vector<int> inputs){
    std::vector<int> output; //Output values
    for(int i = 0; i < neurons_n; i++){
        int y = neurons[i].threshold(inputs); //Activate threshold fn for each neuron in layer
        output.push_back(y);//Add value to output vector
    }
    return output;
}

std::vector<double> MKHSIN035::layer::sigmoid_activate(std::vector<double> inputs){
    std::vector<double> output;//Output values
    for(int i = 0; i < neurons_n; i++){
        double sum = neurons[i].sum(inputs);//sum  of inputs
        double y = neurons[i].sigmoid(sum); //Activate each neuron
        output.push_back(y); //Add value to vector
    }
    return output;
}
void MKHSIN035::layer::learn(int index, MKHSIN035::data examples){
    int N = 20;
    double done = false;

    int c = 0;
    while(c != N){
        
        std::vector<double> weights;
        //Iteratively apply perceptron learning rule for each example
        for(auto entry:examples){
            //Get current weights
            weights = neurons[index].get_weights();
            //Example input vector
            std::vector<int> ex = entry.first;
            //Label
            int target = entry.second;
            //Activate to get actual output
            int output = neurons[index].threshold(ex);
            
            while(true){
                //Stop when the error is 0
                if(output == target)
                    break;
                //Apply perceptron learning rule
                for (int i = 0; i < this->prev_neurons; i++){
                    if(i == 0)//To take care of bias term
                        weights[i] += 0.001*(target-output);
                    else
                        weights[i] += 0.001*(target-output) * ex[i-1];
                }
                neurons[index].set_weights(weights);
                output = neurons[index].threshold(ex);
            }
        }
        
        
        c++;
        
    }   
    
}
std::vector<double> MKHSIN035::layer::get_weights(int i){return neurons[i].get_weights();}
      
int MKHSIN035::layer::get_n_neurons(){return this->neurons.size();};
