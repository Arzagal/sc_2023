#include <systemc.h>
#include "gdr.h"

#ifndef gh1D_H
#define gh1D_H
extern int pixelCol;
extern int seuil;
/////////////////////
SC_MODULE (gv1D)
{
	sc_in <bool> clk;
	sc_in <bool> reset;
	sc_in <bool> blank;
	sc_in <sc_uint<8> > pixel_in;
	sc_out <sc_uint<8> > pixel_out;

	sc_out <bool> bk_out;
	sc_out <bool> hpix_out;

    int* prev1;
    int* prev2;
    int j=0;
    int prev_val1 = 0;
    int prev_val2 = 0;
	void gv1D_trait(void);
	void synchro_out(void);
	SC_CTOR(gv1D)
	{
        prev1 = new int[pixelCol];
        for(int p =0;p<pixelCol;p++){prev1[p]=0;}
        prev2 = new int[pixelCol];
        for(int p =0;p<pixelCol;p++){prev2[p]=0;}
        SC_METHOD(gv1D_trait);
		sensitive << clk.pos(); 

		SC_METHOD(synchro_out);
		sensitive << clk; // sans pos() pour generer l'horloge en sortie

	}
};

#endif
