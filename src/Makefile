CXX += -std=c++0x 
CXXFLAGS += -O2

SRCS=computeSim.cpp selectGreedy.cpp
OBJS=$(patsubst %.cpp,%.o,$(SRCS))
EXECS=computeSim selectGreedy

all: $(EXECS)

depend: .depend

.depend: $(SRCS)
	rm -rf ./.depend
	$(CXX) -std=c++0x $(CXXFLAGS) -MM $^ -MF ./.depend

include .depend

%: %.o
	$(LINK.cc) -std=c++0x $< -o $@

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(INC) -o $@ $< $(LIBS) $(LDFLAGS)

clean:
	@- $(RM) $(EXECS)
	@- $(RM) $(OBJS)
