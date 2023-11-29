0/**********************************************************************
exemple : 
	accumulateur en SystemC
	Lounis Kessal - ENSEA (Cergy)
***********************************************************************/

#include "systemc.h"
#include "gv2D.h"
#include "stimulus.h"
#include "display.h"

/**************************************/
int sc_main (int argc, char *argv[]) {
// signaux
sc_clock clk("clk", 100, 0.5);
sc_signal<bool> reset;
sc_signal <sc_uint<8>> data_in, data_sum;

stimulus stimulus1("stimulus1");
stimulus1.reset(reset);
stimulus1.data_in(data_in);
stimulus1.clk(clk);

accu accu1("accu");
accu1.raz(reset);
accu1.clk(clk);
accu1.data(data_in);
accu1.somme(data_sum);

// Display output
display display1("display");
display1.clk(clk);
display1.data_in(data_in);
display1.data_sum(data_sum);

// <Begin TRACE>
sc_trace_file *tf = sc_create_vcd_trace_file("accu");
sc_trace(tf, clk, "clk");
sc_trace(tf, reset, "RESET");
sc_trace(tf, data_in, "DATA_IN");
sc_trace(tf, data_sum, "DATA_SUM");
// <End TRACE>

sc_start();
sc_close_vcd_trace_file(tf);
int STATUS = system("gtkwave accu.vcd &");

cout << "------------------------" << endl;
cout << "End of fsm simulation..." << endl;
return 0;
}
