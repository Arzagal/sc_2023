/////////////////////////////////////////////////////////////
// Filename : sc_inv.cpp
// Author   : Lounis KESSAL
// Company  : ENSEA
// Comment  : Generer les stimulis ==> modeliser cyclope
/////////////////////////////////////////////////////////////
#include "sc_moy.h"

//*****************************************
// get_pixel : sortir les pixels de l'inv
//*****************************************
void moy::moy_trait()
{
    int pix_tmp = 0;
	if (reset.read() == 0) // reset
	{
		pix_tmp = 0; 
	}
	else if(blank.read() == 1)
	{
        somme -= temp[i];
        temp[i] = pixel_in;
        somme += temp[i];
        i = (i+1) % 5;
        pix_tmp = somme/5;
	}

	// Ecrire la sortie sur le port pixel_out
    pixel_out.write(pix_tmp);
}

void moy::synchro_out() // pour generer les synchro en sortie
{
	// laisser passer les controles
	bk_out.write(blank.read());
	hpix_out.write(clk.read()); 
}
