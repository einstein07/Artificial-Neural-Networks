/* 
 * File:   main.cpp->Driver file
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:18
 */
#include "ann.h"
using namespace std;

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


