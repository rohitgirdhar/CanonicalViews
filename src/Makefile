CXXFLAGS += -O2
LIBS += -L/usr/local/lib
INC += -I$(BOOST_ROOT)
LDFLAGS += -lboost_program_options -lboost_filesystem -lboost_system

SRCS=computeSim.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
EXECS=computeSim

all: $(EXECS)

depend: .depend

.depend: $(SRCS)
	rm -rf ./.depend
	$(CXX) -std=c++0x $(CXXFLAGS) -MM $^ -MF ./.depend

include .depend

%: %.o
	$(LINK.cc) $< -o $@

%.o: %.cpp
	$(CXX) -std=c++0x -c $(CXXFLAGS) $(INC) -o $@ $< $(LIBS) $(LDFLAGS)

clean:
	@- $(RM) $(EXECS)
	@- $(RM) $(OBJS)
