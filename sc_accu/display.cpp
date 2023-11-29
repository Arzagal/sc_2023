#include <systemc.h>
#include "display.h"

void display::affiche()
{
  cout << "Display : " << data_in << " " << data_sum
       << " at time " << sc_time_stamp() << endl;
}
// EOF
