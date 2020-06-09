

/* 
 * File:   ann.h
 * Author: Sindiso
 *
 * Created on 09 June 2020, 02:40
 */

#ifndef ANN_H
#define ANN_H
#include <vector>
namespace MKHSIN035{
  class neuron{
  private:
      int output;
      int prev_neurons;
      std::vector<double> weights;
  public:
      neuron();
      neuron(int prev_neurons);
      int activation_fn(int inputs);
      int get_output();
      
  };  
};


#endif /* ANN_H */

