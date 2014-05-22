CXX += -std=c++0x 
CXXFLAGS += -O2

SRCS=computeSim.cpp selectGreedy.cpp
EXECS=computeSim selectGreedy

all: $(EXECS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $< $(LIBS) $(LDFLAGS)

clean:
	@- $(RM) $(EXECS)
