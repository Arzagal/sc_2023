#include <systemc.h>
#include "gdr.h"

#ifndef gh1D_H
#define gh1D_H

/////////////////////
SC_MODULE (gh1D)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;
	sc_out <sc_uint<8> > pixel_out;

	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;

    int prev =0;
	void gh1D_trait(void);
	void synchro_out(void);
	SC_CTOR(gh1D)
	{
		SC_METHOD(gh1D_trait);
		sensitive << clk.pos(); 

		SC_METHOD(synchro_out);
		sensitive << clk; // sans pos() pour generer l'horloge en sortie

	}
};

#endif
