ROOTCFLAGS     = $(shell root-config --cflags)
ROOTLIBS       = $(shell root-config --libs)
ROOTGLIBS      = $(shell root-config --glibs) 

TAUOLA_DIR = ../TAUOLA
INCLUDES = -I./include/ -I$(TAUOLA_DIR)/include

CXX            = g++
CXXFLAGS       = -fPIC -fno-var-tracking -Wno-deprecated -D_GNU_SOURCE -O2  $(INCLUDES) -ldl

LIBS = -L$(TAUOLA_DIR)/lib/ -lTauolaCxxInterface
LIBS += $(ROOTCFLAGS) $(ROOTGLIBS) -lMinuit  -lTreePlayer -lGenVector -lMathMore

bin/WpWp : src/WpWp.cxx
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean :
	rm -rf bin/WpWp
