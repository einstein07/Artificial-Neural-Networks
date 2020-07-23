
/* 
 * File:   main.cpp->Driver file
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:09
 */
#include "ann.h"
using namespace std;
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
