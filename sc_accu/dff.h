#ifndef DFF_H_INCLUDED
#define DFF_H_INCLUDED

#include "systemc.h"

SC_MODULE(dff)
{
	sc_in<bool> h;
	sc_in<bool> reset;
	sc_in<sc_uint<8> > d;
	sc_out<sc_uint<8> > q;

	void d2q();

	SC_CTOR(dff){
		SC_METHOD(d2q);
		sensitive << h.pos();
		sensitive << reset;
	}
};
#endif
