
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

    //Training examples. 
    vector < vector<int> > data =   {{0, 0},
                                    {0, 1},
                                    {1, 0},
                                    {1, 1}};
    //Target output
    vector < vector<int> > label =  {{0, 1, 1, 1},//OR gate
                                    {1, 1, 1, 0}, //NAND gate
                                    {0, 0, 0, 1}};//AND gate
    cout<<"Learning..."<<endl;
    //--------------------------------------------------------------------------
    //Input layer training
    //--------------------------------------------------------------------------
    int n_neurons = 2;
    int prev_neurons = 2;
    MKHSIN035::layer l1(prev_neurons, n_neurons);//input layer
    for(int i = 0; i < l1.get_n_neurons(); i++){
        for(int j = 0; j < label[i].size(); j++){
            l1.learn(i, data[j], label[i][j]);
        }
        vector<double> w = l1.get_weights(i);
        //cout<<"MAIN: Gate: "<<(i+1)<<" "<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
    }
    //--------------------------------------------------------------------------
    //Output layer: AND gate
    //--------------------------------------------------------------------------
    n_neurons = 1;
    MKHSIN035::layer l2(prev_neurons, n_neurons); //output layer
    for(int i = 0; i < l2.get_n_neurons(); i++){
        for(int j = 0; j < label[i].size(); j++){
            l2.learn(i, data[j], label[2][j]);
        }
        vector<double> w = l2.get_weights(i);
        //cout<<"Output layer AND Gate: "<<(i+1)<<" "<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
    }
    cout<<"Done"<<endl;
    //--------------------------------------------------------------------------
    //GATE 1: OR gate
    //GATE 2: NAND gate
    //--------------------------------------------------------------------------
    vector < vector<int> > l1_output; 
    cout<<"Testing..."<<endl;
    
    for(int i = 0; i < data.size(); i++){
        l1_output.push_back(l1.activate(data[i]));
    }
    
    for(int i = 0; i < l1.get_n_neurons(); i++){
        if(i == 0)
            cout<<"OR Gate: ";
        else
            cout<<"NAND Gate: ";
        cout<<"\nInput\t\tOutput"<<endl;
                for(int j = 0; j < data.size(); j++){
                    cout<<data[j][0]<<" "<<data[j][1]<<"\t\t"<<l1_output[j][i]<<endl;
                }
    }
    //--------------------------------------------------------------------------
    //Input of the AND is the output from the OR & NAND gates:
    //--------------------------------------------------------------------------
    vector < vector<int> > l2_output; 
    for(int i = 0; i < data.size(); i++){
        l2_output.push_back(l2.activate(l1_output[i]));
    }
    
    for(int i = 0; i < l2.get_n_neurons(); i++){
        cout<<"AND Gate: "<<"\nInput\t\tOutput"<<endl;
                for(int j = 0; j < data.size(); j++){
                    cout<<l1_output[j][0]<<" "<<l1_output[j][1]<<"\t\t"<<l2_output[j][i]<<endl;
                }
    }
    
    return 0;
}

