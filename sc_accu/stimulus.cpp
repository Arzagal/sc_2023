#include <systemc.h>
#include "stimulus.h"

void stimulus::data_gen() 
{
	cycle=0; data_in = 0; reset = true;

	while(true)
	{
		for(cycle=0; cycle < 4; cycle++) 
			wait();

		reset = false ;
		for(cycle = 4; cycle < 20; cycle++) 
		{
			data_in = cycle - 4;
			cout << "Stimuli : " << cycle << " at time " << sc_time_stamp() << endl;
			wait();
		}
		// Fin de simulation 
		sc_stop();
		cout << "Simulation of " << cycle-1 << " items finished" 
			 << " at time " << sc_time_stamp() << endl;

	}
}

