#include <systemc.h>
#include "gdr.h"

#ifndef inv_H
#define inv_H

/////////////////////
SC_MODULE (moy)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;
	sc_out <sc_uint<8> > pixel_out;

	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;

    sc_uint<8> temp[5] = {0};
    int i = 0;
    int somme = 0;
	void moy_trait(void);
	void synchro_out(void);
	SC_CTOR(moy)
	{
		SC_METHOD(moy_trait);
		sensitive << clk.pos(); 

		SC_METHOD(synchro_out);
		sensitive << clk; // sans pos() pour generer l'horloge en sortie

	}
};

#endif
