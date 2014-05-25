CXX += -std=c++0x 
CXXFLAGS += -O2

SRCS=computeSim.cpp selectGreedy.cpp computeSimAsInlierCount.cpp removeGreedy.cpp
EXECS=computeSim selectGreedy computeSimAsInlierCount removeGreedy

all: $(EXECS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $< $(LIBS) $(LDFLAGS)

clean:
	@- $(RM) $(EXECS)
