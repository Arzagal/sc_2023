#include "systemc.h"
#include "sous.h"

void accu::add2x8()
{
    sc_uint<8> e1;
    e1 = data.read();
	e2 = e2- e1;
	somme.write(e2);
}