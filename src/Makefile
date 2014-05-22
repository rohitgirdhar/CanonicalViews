CXX += -std=c++0x 
CXXFLAGS += -O2

SRCS=computeSim.cpp selectGreedy.cpp computeSimAsInlierCount.cpp
EXECS=computeSim selectGreedy computeSimAsInlierCount

all: $(EXECS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $< $(LIBS) $(LDFLAGS)

clean:
	@- $(RM) $(EXECS)
