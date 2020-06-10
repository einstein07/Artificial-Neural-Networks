/* 
 * File:   ann.h
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:40
 */

#ifndef ANN_H
#define ANN_H
//------------------------------------------------------------------------------
//INCLUDES
//------------------------------------------------------------------------------
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

namespace MKHSIN035{
    //--------------------------------------------------------------------------
    //Neuron class interface
    //--------------------------------------------------------------------------
  class neuron{
  private:
      int output;
      int prev_neurons;
      double theta;
      std::vector<double> weights;
  public:
      neuron();
      neuron(int prev_neurons, double weights[]);
      int activation_fn(const double inputs[]);
      std::vector<double> get_weights(); //return weights
  }; 
  //----------------------------------------------------------------------------
  //Layer class interface
  //----------------------------------------------------------------------------
  class layer{
  private:
      int neurons_n;//Number of neurons in this layer
      int prev_neurons;//Number of previous neurons
      std::vector<neuron> neurons;//All neurons in this layer
      std::vector<int> outputs;//outputs from all neurons in this layer
  public:
      layer();
      layer(int prev_neurons, int neurons);
      void learn(double input[], double t);//learning fn
      std::vector<int> activate(double inputs[]);
      std::vector<double> get_weights(int i);
  };
};


#endif /* ANN_H */

