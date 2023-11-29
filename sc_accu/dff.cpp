
#include "systemc.h"
#include "dff.h"

void dff::d2q() {
	if (reset) q = 0;
	else  q = d;
}


