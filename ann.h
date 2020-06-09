

/* 
 * File:   ann.h
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:40
 */

#ifndef ANN_H
#define ANN_H
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>
namespace MKHSIN035{
  class neuron{
  private:
      int output;
      int n_prev_neurons;
      double theta;
      std::vector<double> weights;
  public:
      neuron();
      neuron(int n_prev_neurons, double theta);
      int activation_fn(const double inputs[]);
      int get_output();
      bool learn(double input[], double t);
  };  
};


#endif /* ANN_H */

