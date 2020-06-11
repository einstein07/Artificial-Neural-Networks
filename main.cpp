
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

    std::vector<int> x;
    x.push_back(0);
    x.push_back(1);
    double t = 1; 
    MKHSIN035::layer n(2, 2);
    n.learn(1, x, 1);
    std::vector<double> weights = n.get_weights(1);
       
    std::cout<<weights[0]<<" "<<weights[1]<<" "<<weights[2]<<std::endl;

    //if(n.learn(x,t))std::cout<<"Done learning: "<<n.get_output()<<endl;
    
    return 0;
}

