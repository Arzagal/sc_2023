/////////////////////////////////////////////////////////////
// Filename : sc_inv.cpp
// Author   : Lounis KESSAL
// Company  : ENSEA
// Comment  : Generer les stimulis ==> modeliser cyclope
/////////////////////////////////////////////////////////////
#include "gv2D.h"

//*****************************************
// get_pixel : sortir les pixels de l'inv
//*****************************************
void gv1D::gv1D_trait()
{
    int pix_tmp = 0;
	if (reset.read() == 0) // reset
	{
		pix_tmp = 0;
	}
	else if(blank.read() == 1)
	{
        if(j>0) {
            int temp = pixel_in.read();
            pix_tmp = prev[j-1] + prev[j] - prev_val - temp;
            prev[j - 1] = prev_val;
            prev_val = temp;
        }
        j++;
	}
    else{
        j = 0;
        prev_val = 0;
    }

    if(pix_tmp < 0){
        pix_tmp = -pix_tmp;
    }
    else if(pix_tmp > 255){
        pix_tmp = 255;
    }
	// Ecrire la sortie sur le port pixel_out
    pixel_out.write(pix_tmp);
}

void gv1D::synchro_out() // pour generer les synchro en sortie
{
	// laisser passer les controles
	bk_out.write(blank.read());
	hpix_out.write(clk.read()); 
}
