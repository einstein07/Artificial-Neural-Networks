
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

    vector < vector<int> > data =   {{0, 0},
                                    {0, 1},
                                    {1, 0},
                                    {1, 1}};
    vector < vector<int> > label =  {{0, 1, 1, 1},//OR gate
                                    {1, 1, 1, 0}, //NAND gate
                                    {0, 0, 0, 1}};//AND gate
    int n_neurons = 3;
    int prev_neurons = 2;
    MKHSIN035::layer l(prev_neurons, n_neurons);
    for(int i = 0; i < l.get_n_neurons(); i++){
        for(int j = 0; j < label[i].size(); j++){
            l.learn(i, data[j], label[i][j]);
        }
    }
//    n.learn(0, vc[0], t);
//    std::vector<double> weights = n.get_weights(0);
//       
//    std::cout<<weights[0]<<" "<<weights[1]<<" "<<weights[2]<<std::endl;
//        
//    t = 0;
//    std::vector<int> x1;
//    //x1.push_back(0.5);
//    x1.push_back(0);
//    x1.push_back(1);
//    n.learn(0, x1, t);
//    weights = n.get_weights(0);
//    std::cout<<weights[0]<<" "<<weights[1]<<" "<<weights[2]<<std::endl;
//    
//    std::vector<int> x2;
//    //x2.push_back(0.5);
//    x2.push_back(1);
//    x2.push_back(0);
//    n.learn(0, x2, t);
//    weights = n.get_weights(0);
//    std::cout<<weights[0]<<" "<<weights[1]<<" "<<weights[2]<<std::endl;
//
//    t = 1;
//    std::vector<int> x3;
//    //x3.push_back(0.5);
//    x3.push_back(1);
//    x3.push_back(1);
//    n.learn(0, x3, t);
//    weights = n.get_weights(0);
//    std::cout<<weights[0]<<" "<<weights[1]<<" "<<weights[2]<<std::endl;
//    //std::cout<<"Done learning"<<std::endl;
//    
//    //n.learn(0, x, 1);
//    std::vector<int> tes;
//    tes.push_back(0);
//    tes.push_back(1);
//    x1 = n.activate(tes);
    std::cout<<"Done learning"<<endl;
    
    return 0;
}

