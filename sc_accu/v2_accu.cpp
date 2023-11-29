#include "systemc.h"
#include "v2_accu.h"

void accu::add2x8()
{
    sc_uint<8> e1;
    e1 = data.read();
	e2 = e1 + e2;
	somme.write(e2);
}