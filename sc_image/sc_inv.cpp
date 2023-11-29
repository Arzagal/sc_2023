/////////////////////////////////////////////////////////////
// Filename : sc_inv.cpp
// Author   : Lounis KESSAL
// Company  : ENSEA
// Comment  : Generer les stimulis ==> modeliser cyclope
/////////////////////////////////////////////////////////////
#include "sc_inv.h"

//*****************************************
// get_pixel : sortir les pixels de l'inv
//*****************************************
void inv::inv_trait()
{
    int pix_tmp = 0;
	
	if (reset.read() == 0) // reset
	{
		pix_tmp = 0; 
	}
	else if(blank.read() == 1)
	{
        pix_tmp = pixel_in.read();
        pix_tmp = 255-pix_tmp;
		
	}
	// Ecrire la sortie sur le port pixel_out
    pixel_out.write(pix_tmp);
}

void inv::synchro_out() // pour generer les synchro en sortie
{
	// laisser passer les controles
	bk_out.write(blank.read());
	hpix_out.write(clk.read()); 
}
