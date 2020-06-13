
/* 
 * File:   main.cpp->Driver file
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:09
 */
#include "ann.h"
#include <cstdlib>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    MKHSIN035::part_1();
    return 0;
}

    
void MKHSIN035::part_1(){
    
    //--------------------------------------------------------------------------
    //PART 1
    //--------------------------------------------------------------------------
    //Training examples. 
    vector < vector<int> > data =   {{0, 0},
                                    {0, 1},
                                    {1, 0},
                                    {1, 1}};
    //Target output
    vector < vector<int> > label =  {{0, 1, 1, 1},//OR gate
                                    {1, 1, 1, 0}, //NAND gate
                                    {0, 0, 0, 1}};//AND gate
    //Create and open file for writing
    ofstream file;
    file.open("output.txt");
    
    file<<"--------------------------------------------------------------------------"<<endl;
    file<<"Question 1"<<endl;
    file<<"--------------------------------------------------------------------------"<<endl;  
    file<<"Minimum number of perceptrons: "<<3<<endl;
    file<<"Input layer: NAND gate & OR gate >>> Output layer: AND gate"<<endl;
    
    file<<"--------------------------------------------------------------------------"<<endl;
    file<<"Question 2"<<endl;
    file<<"--------------------------------------------------------------------------"<<endl;  
    file<<"Training examples: "<<endl;
    for(int i = 0; i < 3; i++){
        if(i == 0)
            file<<"OR gate training examples: \nInput\t\tTarget output"<<endl;
        else if(i == 1)
            file<<"NAND gate training examples: \nInput\t\tTarget output"<<endl;
        else
            file<<"AND gate training examples: \nInput\t\tTarget output"<<endl;
        for(int j = 0; j < label[i].size(); j++){
            file<<data[j][0]<<" "<<data[j][1]<<"\t\t"<<label[i][j]<<endl;
        }
    }
    file<<"It took 12 training examples to correctly learn to solve the binary XOR problem."<<endl;
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
    
    file.close();
}


