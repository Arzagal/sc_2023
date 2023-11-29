# makefile

###############################################################
# export SYSTEMC=/usr/lsa/apps/systemc-2.3.1
# export LD_LIBRARY_PATH=$SYSTEMC/lib-linux64/
#################################################################
MODULE = v2_accu
SRCS = v2_accu.cpp stimulus.cpp display.cpp tb_v2_accu.cpp
OBJS = $(SRCS:.cpp=.o)

##########################################################################
TARGET_ARCH = linux64

CC = g++
OPT    = -O3 -Wno-deprecated
CPPFLAGS = -fpermissive -std=gnu++11
CFLAGS = $(OPT) -fexceptions

INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-linux64

LIBS   =  -lsystemc -lm

EXE    = $(MODULE).x

.SUFFIXES: .cc .cpp .o .x

$(EXE): $(OBJS) $(SYSTEMC)/lib-linux64/libsystemc.a 
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCDIR) $(LIBDIR) -o $@ $(OBJS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCDIR) -c $<

.cc.o:
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(EXE)
