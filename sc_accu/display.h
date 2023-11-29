#include "systemc.h"

SC_MODULE(display) 
{
  sc_in<bool> clk;
  sc_in<sc_uint<8> > data_in;
  sc_in<sc_uint<8> > data_sum;

  void affiche();

  SC_CTOR(display)
  {
      SC_METHOD(affiche);
 	  sensitive << clk.pos();   
  }
};

