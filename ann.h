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
#include <map>
#include <initializer_list>

namespace MKHSIN035{
    typedef std::map<std::vector<int>, int >  data; 
    //--------------------------------------------------------------------------
    //Auxillary methods
    //--------------------------------------------------------------------------
    void part_1();
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
      int activation_fn(const std::vector<int> inputs);
      std::vector<double> get_weights(); //return weights
      void set_weights(std::vector<double> weights);
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
      layer(int prev_neurons_n, int neurons);
      void learn(int i, data examples);//learning fn
      std::vector<int> activate(std::vector<int> inputs);
      std::vector<double> get_weights(int i);
      int get_n_neurons();
  };
};


#endif /* ANN_H */

