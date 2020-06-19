
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
    MKHSIN035::part_2();
    return 0;
}

    
void MKHSIN035::part_1(){
    
    //--------------------------------------------------------------------------
    //PART 1
    //--------------------------------------------------------------------------
    //Testing data. 
    vector < vector<int> > data =   {{0, 0},
                                    {0, 1},
                                    {1, 0},
                                    {1, 1}};
   /*Training examples for all gates*/
    MKHSIN035::data OR_examples =   {
                                            {{0, 0}, 0},
                                            {{0, 1}, 1},
                                            {{1, 0}, 1},
                                            {{1, 1}, 1}     
                                    };
    
    MKHSIN035::data NAND_examples = {
                                            {{0, 0}, 1},
                                            {{0, 1}, 1},
                                            {{1, 0}, 1},
                                            {{1, 1}, 0}
                                    };
    
    MKHSIN035::data AND_examples =  {
                                            {{0, 0}, 0},
                                            {{0, 1}, 0},
                                            {{1, 0}, 0},
                                            {{1, 1}, 1}
                                    };
    
    /* 
     * Create and open file for writing
     *
     */
    ofstream file;
    file.open("Part 1 Output.txt");
    if(file.is_open()){
        file<<"--------------------------------------------------------------------------"<<endl;
        file<<"Question 1"<<endl;
        file<<"--------------------------------------------------------------------------"<<endl;  
        file<<"Minimum number of perceptrons: "<<3<<endl;
        file<<"Input layer: NAND gate & OR gate >>> Output layer: AND gate"<<endl;

        file<<"--------------------------------------------------------------------------"<<endl;
        file<<"Question 2"<<endl;
        file<<"--------------------------------------------------------------------------"<<endl;  
        file<<"Training examples: "<<endl;

        file<<"OR gate training examples: \nInput\t\tTarget output"<<endl;
        for(auto entry: OR_examples){
            for(int i:entry.first){
                file<<i<<" ";
            }
            file<<"\t\t"<<entry.second<<endl;
        }   
        file<<"NAND gate training examples: \nInput\t\tTarget output"<<endl;
        for(auto entry: NAND_examples){
            for(int i:entry.first){
                file<<i<<" ";
            }
            file<<"\t\t"<<entry.second<<endl;
        }
        file<<"AND gate training examples: \nInput\t\tTarget output"<<endl;
        for(auto entry: AND_examples){
            for(int i:entry.first){
                file<<i<<" ";
            }
            file<<"\t\t"<<entry.second<<endl;
        }     
        file<<"It took 12 training examples to correctly learn to solve the binary XOR problem:"<<endl;
    }
    else{
        cout<<"An unexpected error occurred when creating file."<<endl;
    }
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"PART 1"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    
    cout<<"Learning..."<<endl;
    //--------------------------------------------------------------------------
    //Input layer training
    //--------------------------------------------------------------------------
    int n_neurons = 2;
    int prev_neurons = 2;
    MKHSIN035::layer l1(prev_neurons, n_neurons);//input layer
    l1.learn(0, OR_examples);
    l1.learn(1, NAND_examples);
   
    //--------------------------------------------------------------------------
    //Output layer: AND gate
    //--------------------------------------------------------------------------
    n_neurons = 1;
    MKHSIN035::layer l2(prev_neurons, n_neurons); //output layer
    l2.learn(0, AND_examples);

    cout<<"Done"<<endl;
    //--------------------------------------------------------------------------
    //GATE 1: OR gate
    //GATE 2: NAND gate
    //--------------------------------------------------------------------------
    vector < vector<int> > l1_output; 
    cout<<"Testing XOR gate..."<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Input Layer"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    for(int i = 0; i < data.size(); i++){
        l1_output.push_back(l1.threshold_activate(data[i]));
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
        l2_output.push_back(l2.threshold_activate(l1_output[i]));
    }
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Output Layer(XOR Output)"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    
    for(int i = 0; i < l2.get_n_neurons(); i++){
        cout<<"AND Gate: "<<"\nInput\t\tOutput"<<endl;
                for(int j = 0; j < data.size(); j++){
                    cout<<l1_output[j][0]<<" "<<l1_output[j][1]<<"\t\t"<<l2_output[j][i]<<endl;
                }
    }
    
    /*
     * Write final XOR output to file
     */
    if(file.is_open()){
        for(int i = 0; i < l2.get_n_neurons(); i++){
            file<<"\n\nXOR Gate: "<<"\nInput\t\tOutput"<<endl;
                    for(int j = 0; j < data.size(); j++){
                        file<<data[j][0]<<" "<<data[j][1]<<"\t\t"<<l2_output[j][i]<<endl;
                    }
        }
        file.close();
    }
    else{
        cout<<"An unexpected error occurred when creating file."<<endl;
    }
}
void MKHSIN035::part_2(){
    //---------------------------------------------------------------------------------
    //PART 2: This function implements all the requirements of part 2 of the assignment
    //---------------------------------------------------------------------------------
    
    //ANN input nodes 
    vector<double> x = {1.30, 2.70, 0.80};
    //ANNs expected output
    double y = 0.36;
    //Weights connecting the inputs to the hidden layer neurons
    vector<double>  l1_weights = {0.1, 0.2, 0.5,//First neuron incoming weights
                              -0.4, 1, -0.6};//Second neuron incoming weights
    //Weights from hidden layer nodes 1 and 2, respectively
    vector<double> l2_weights = {0.8, 1.0};
    //Bias values for the hidden layer neurons 1 and 2
    vector<double> l1_bias = {0.1, -0.3};
    //Bias value for the output layer neuron
    vector<double> l2_bias = {-0.3};
    
    /*Define Hidden layer*/
    
    //Previous neurons for hidden layer
    int prev_neurons_l1 = 3;
    //Number of neurons for hidden layer
    int n_neurons_l1 = 2;
    //Define hidden layer with 2 neurons, 3 incoming connections:
    layer l1(prev_neurons_l1, n_neurons_l1, l1_weights, l1_bias);
    //Activate hidden layer:
    vector<double> l1_output = l1.sigmoid_activate(x);
    
    /*Define Output layer*/
    
    //Previous neurons for output layer
    int prev_neurons_l2 = 2;
    //Number of neurons for output layer
    int n_neurons_l2 = 1;
    //Define output layer with 1 neuron, 2 incoming connections:
    layer l2(prev_neurons_l2, n_neurons_l2, l2_weights, l2_bias);
    //Activate hidden layer:
    vector<double> l2_output = l2.sigmoid_activate(l1_output);
    
    
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"PART 2"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"\n---------------------------------------------------------------------"<<endl;
    cout<<"Hidden Layer Output"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    //print the output of the hidden layer
    cout<<l1_output[0]<<" "<<l1_output[1]<<endl;
    
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Output Neuron Output"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    //print the output of the output neuron
    cout<<l2_output[0]<<endl;
    
    double MSE = pow((l2_output[0]-y), 2);
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"Mean Squared Error for ANN input x"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    //Print calculated MSE
    cout<<MSE<<endl;
    /*
     * Create text file to answer questions
     */
    ofstream file;
    file.open("Part 2 Output.txt");
    if(file.is_open()){
        file<<"---------------------------------------------------------------------"<<endl;
        file<<"PART 2"<<endl;
        file<<"---------------------------------------------------------------------"<<endl;
        file<<"\n---------------------------------------------------------------------"<<endl;
        file<<"Question 3: Hidden Layer Output values"<<endl;
        file<<"---------------------------------------------------------------------"<<endl;
        //print the output of the hidden layer
        file<<l1_output[0]<<" "<<l1_output[1]<<endl;

        file<<"---------------------------------------------------------------------"<<endl;
        file<<"Question 4: Output Neuron Output"<<endl;
        file<<"---------------------------------------------------------------------"<<endl;
        //print the output of the output neuron
        file<<l2_output[0]<<endl;

        file<<"---------------------------------------------------------------------"<<endl;
        file<<"Question 5: Mean Squared Error for ANN input x"<<endl;
        file<<"---------------------------------------------------------------------"<<endl;
        //Print calculated MSE
        file<<MSE<<endl;
        file.close();
    }
    else{
        cout<<"An unexpected error occurred when creating file."<<endl;
    }
}


