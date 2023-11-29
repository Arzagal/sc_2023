#include "systemc.h"
#include "dff.h"

#ifndef ACCU_H_INCLUDED
#define ACCU_H_INCLUDED

SC_MODULE(accu)
{
	sc_in<bool> clk;
	sc_in<bool> raz;
	sc_in<sc_uint<8> > data;
	sc_out<sc_uint<8> > somme;
	
	sc_signal <sc_uint<8> > sum2reg, q2sum;
	sc_uint<8> e1, e2;

	dff *r0;
	
	void add2x8();
	
	SC_CTOR(accu)
	{
		SC_METHOD(add2x8);
		sensitive << data << q2sum;

		r0 = new dff ("reg8");
		r0->h(clk);
		r0->reset(raz);
		r0->d(sum2reg);
		r0->q(q2sum);
	}
};
#endif
