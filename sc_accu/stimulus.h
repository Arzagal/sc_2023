SC_MODULE(stimulus) 
{
  sc_out<bool> reset;
  sc_in<bool> clk;
  sc_out<sc_uint<8> > data_in;     	    

  unsigned cycle;
  void data_gen();

  SC_CTOR(stimulus)
  {
      	SC_THREAD(data_gen);
      	sensitive << clk.neg();
		sensitive << reset;      
      	cycle = 0;
  }  
};

