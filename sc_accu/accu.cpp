#include "systemc.h"
#include "accu.h"

void accu::add2x8() 
{
	e1 = data.read();
	e2 = q2sum.read(); // mieux avec read()
	sum2reg = e1 + e2;
	somme.write(e2);
}
