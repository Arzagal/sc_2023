#include "systemc.h"

#ifndef ACCU_H_INCLUDED
#define ACCU_H_INCLUDED

SC_MODULE(accu)
{
	sc_in<bool> clk;
	sc_in<bool> raz;
	sc_in<sc_uint<8> > data;
	sc_out<sc_uint<8> > somme;
	
	sc_uint<8> e2;

	void add2x8();
	
	SC_CTOR(accu)
    {
        SC_METHOD(add2x8);
        sensitive << data;

        e2 = 0;
    }
};
#endif
