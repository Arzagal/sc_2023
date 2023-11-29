/////////////////////////////////////////////////////////////
// Filename : sc_inv.cpp
// Author   : Lounis KESSAL
// Company  : ENSEA
// Comment  : Generer les stimulis ==> modeliser cyclope
/////////////////////////////////////////////////////////////
#include "gh1D.h"

//*****************************************
// get_pixel : sortir les pixels de l'inv
//*****************************************
void gh1D::gh1D_trait()
{
    int pix_tmp = 0;
	if (reset.read() == 0) // reset
	{
		pix_tmp = 0;
        prev = 0;
	}
	else if(blank.read() == 1)
	{
        pix_tmp = prev - pixel_in.read();
        prev = pixel_in.read();
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

void gh1D::synchro_out() // pour generer les synchro en sortie
{
	// laisser passer les controles
	bk_out.write(blank.read());
	hpix_out.write(clk.read()); 
}
